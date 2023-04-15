#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "kiss_fft.h"

std::vector<std::vector<std::complex<float>>> stft(const std::vector<float>& signal, int windowSize, int overlap) {
    int stepSize = windowSize - overlap;
    int numWindows = (signal.size() - overlap) / stepSize;

    kiss_fft_cfg cfg = kiss_fft_alloc(windowSize, 0, nullptr, nullptr);
    std::vector<std::vector<std::complex<float>>> spectrogram(numWindows, std::vector<std::complex<float>>(windowSize / 2 + 1));

    for (int i = 0; i < numWindows; ++i) {
        std::vector<kiss_fft_cpx> input(windowSize);
        std::vector<kiss_fft_cpx> output(windowSize);

        for (int j = 0; j < windowSize; ++j) {
            int idx = i * stepSize + j;
            float windowVal = 0.5 * (1 - std::cos(2 * M_PI * j / (windowSize - 1))); // Hann window
            input[j].r = signal[idx] * windowVal;
            input[j].i = 0;
        }

        kiss_fft(cfg, input.data(), output.data());

        for (int j = 0; j < windowSize / 2 + 1; ++j) {
            spectrogram[i][j] = std::complex<float>(output[j].r, output[j].i);
        }
    }

    kiss_fft_free(cfg);

    return spectrogram;

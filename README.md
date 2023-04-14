<p align="center">
  <img src="docs/media/jap_hue.png" style="object-fit: cover; width: 100%; height: 300px;" />
  <h1 style="position: absolute; top: 150px; left: 50%; transform: translateX(-50%); color: white; text-shadow: 2px 2px 2px black;">FindMe</h1>
</p>
... a gaze-mimicking package for robots.

## To Do
- [X] Setup BBB
  - [X] Audio input
  - [X] Tensorflow lite 
- [ ] Test keyword spotting examples
- [ ] Record Audio samples
  - [ ] Record a few audio samples from 0°, 45°, 90°, 135°, 180°, 225°, 270°, and 315° at varying distances
- [ ] Combine STFT audio processing and fuzzy logic azimuth estimation
  - [ ] STFT: See if we can identify frequecny spikes when speech is from a certain direction 
  - [ ] Fuzzy Logic: Once we identify some characteristics, we will use fuzzy logic to estimate direction of audio  
- [ ] Combine keyword spotting and azimuth estimation
- [ ] Control Servo with azimuth results
- [ ] Create demo with realsense and base

## Overview

This package utilizes a single microphone and a BeagleBone Black board to detect the relative location of human speech and automatically orient a Realsense camera towards the sound source. When a human voice is detected, the software calculates the direction of the sound and adjusts the camera's orientation using a servo. 

## Hardware

- Digital Servo
- Common microphone
- Good microcontroller or SBC
- A USB camera

## Installation
1. WIP

## Usage

1. WIP

## Examples
1. WIP

## Acknowledgment
See [Work Referenced](./docs/ref/).
Workflow improved by [ChatGPT](https://github.com/ChatGPT).


## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for more information.

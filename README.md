# CarND-PID-Control
Udacity Self-Driving Car Nanodegree - PID Control project

# Overview

This project implements a PID controller to control a car in [Udacity's simulator](https://github.com/udacity/self-driving-car-sim/releases)).

# Prerequisites

The project has the following dependencies (from Udacity's seed project):

- cmake >= 3.5
- make >= 4.1
- gcc/g++ >= 5.4
- [uWebSockets](https://github.com/uNetworking/uWebSockets)
- [Udacity's simulator](https://github.com/udacity/self-driving-car-sim/releases).

In order to install the necessary libraries, use the [install-arch-linux.sh](./install-arch-linux.sh).

# Compiling and executing the project

Build the project with this code in your terminal `./build.sh`:
```
> ./build.sh
```
It will crete a `./build` folder.

To execute it, run `./build/pid` 

if there are some modification and a build is needed you can use the script `./makeAndrun.sh`:

Now the PID controller is running and listening on port 4567 for messages from the simulator. Next step is to open Udacity's simulator

Click the "Select" button, and the car starts driving. You will see the debugging information on the PID controller terminal. A short video with the final parameters is [./videos/final_params.mov](./videos/final_params.mov).

# [Rubric](https://review.udacity.com/#!/rubrics/824/view) points

## Compilation

### Your code should compile.

The code compiles without errors or warnings.

## Implementation

### The PID procedure follows what was taught in the lessons.

 - The PID implementation is coded on the [./src/PID.cpp](./src/PID.cpp).
 - The [PID::UpdateError](./src/PID.cpp#L29) method calculates proportional, integral and derivative errors
 - The [PID::TotalError](./src/PID.cpp#L47) calculates the total error.

## Reflection

### Describe the effect each of the P, I, D components had in your implementation.

- The proportional portion of the controller tries to steer the car toward the center line (against the cross-track error). If used along, the car overshoots the central line very easily and go out of the road very quickly. An example video where this component is used along is [./videos/proportional_error.mov](./videos/proportional_error.mov).

- The integral portion tries to eliminate a possible bias on the controlled system that could prevent the error to be eliminated. If used along, it makes the car to go in circles. In the case of the simulator, no bias is present. An example video where this component is used along is [./videos/integral_error.mov](./videos/integral_error.mov).

- The differential portion helps to counteract the proportional trend to overshoot the center line by smoothing the approach to it. An example video where this component is used along is [./videos/differential.mov](./videos/differential.mov).

### Describe how the final hyperparameters were chosen.

The parameters were chosen manually by try and error. First, make sure the car can drive straight with zero as parameters. Then add the proportional and the car start going on following the road but it starts overshooting go out of it. Then add the differential to try to overcome the overshooting. The integral part only moved the car out of the road; so, it stayed as zero. After the car drove the track without going out of it, the parameters increased to minimize the average cross-track error on a single track lap. The final parameters where [P: 1.5, I: 0.0, D: 2.5].

## Simulation

### The vehicle must successfully drive a lap around the track.

A short video with the final parameters is [./videos/final_params.mov](./videos/final_params.mov).

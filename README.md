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

- P: The  P is the proportional portion of the controller, it tries steer the car toward the center line (against the cross-track error). If used along, the car overshoots the central line very easily and go out of the road very quickly. A video example is here [./videos/proportional_error.mov](./videos/proportional_error.mov).

- I: The I is the integral portion, it tries to remove a bias on the controlled system that could prevent the real error to be eliminated. but the simulator, don't has a bias . A video example is here [./videos/integral_error.mov](./videos/integral_error.mov).

- D: The D is the differential portion, it helps the car to counteract the trend to overshoot the center line by smoothing the approach to it. An example video where this component is used along is [./videos/differential.mov](./videos/differential.mov).

### Describe how the final hyperparameters were chosen.

I choose these param by try and errors.

 I tried make sure the car can drive straight with 0 as param. Then I added the P, so the car start going on following the road. Then added the D . When i added the I part, it the car go out of the road, so, it stayed as zero. The final parameters where [P: 1.5, I: 0.0, D: 2.5].

## Simulation

### The vehicle must successfully drive a lap around the track.

A video with the final parameters is this [./videos/final_params.mov](./videos/final_params.mov).

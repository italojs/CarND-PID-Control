#include "PID.h"

#include <algorithm>

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  // Proportional error.
  pErr = 0.0;
  // Integral error.
  iErr = 0.0;
  // Diferential error.
  dErr = 0.0;

  prevCTE = 0.0;

  counter = 0;
  errorSum = 0.0;
  minError = std::numeric_limits<double>::max();
  maxError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {

  pErr = cte;
  iErr += cte;
  dErr = cte - prevCTE;
  prevCTE = cte;

  errorSum += cte;
  counter++;

  if ( cte > maxError ) {
    maxError = cte;
  }
  if ( cte < minError ) {
    minError = cte;
  }
}

double PID::TotalError() {
  return pErr * Kp + iErr * Ki + dErr * Kd;
}

double PID::AverageError() {
  return errorSum/counter;
}

double PID::MinError() {
  return minError;
}

double PID::MaxError() {
  return maxError;
}

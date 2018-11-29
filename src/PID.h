#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double pErr;
  double iErr;
  double dErr;
  double prevCTE;

  /**
   * Error counters
  **/
  long counter;
  double errorSum;
  double minError;
  double maxError;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  *  Returns the average error.
  */
  double AverageError();

  /*
  * Returns the min error.
  */
  double MinError();

  /*
  * Returns the max error.
  */
  double MaxError();
};

#endif /* PID_H */

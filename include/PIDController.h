/*
 * PIDController.h
 *
 *  Created on: Feb 8, 2017
 *      Author: Brian Buxton
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

/** Implementation of a basic PIDController
 * @see https://en.wikipedia.org/wiki/PID_controller
 *
 * Constructed with the proportional, integral, and derivative gains.
 *
 * compute method is then called at some interval to calculate the output
 * power given the current and target velocity.
 *
 *
 */
class PIDController {
 private:
  double _Kp, _Ki, _Kd;

 public:
  /**
   * PIDControlller to compute power adjustment given Kp, Ki, and Kd
   * @param Kp the proportional gain
   * @param Ki the integral gain,
   * @param Kd the derivative gain
   * @return constructed PIDController
   */
  PIDController(double Kp, double Ki, double Kd);
  /**
   * Computes the controller output given gain settings and current and target velocities
   * @param currentVelocity current measured velocity
   * @param targetSetPoint current desired velocity
   * @return controller output
   */
  double compute(double currentVelocity, double targetSetPoint);
};

#endif /* PIDCONTROLLER_H_ */

#include <stdexcept>
#include "PIDController.h"
/**
 * PIDController.cpp
 *
 * @created on: Feb 8, 2017
 * @author: Brian Buxton
 *
 * Proportional Derivative Controller
 *
 */
PIDController::PIDController(double Kp, double Ki, double Kd) {
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

double PIDController::compute(double currentVelocity, double targetSetPoint) {
  return 0.0001;
}


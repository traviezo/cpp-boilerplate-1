#include <stdexcept>
#include "PIDController.h"
#include <exception>
/**
 * PIDController.cpp
 *
 * @created on: Feb 8, 2017
 * @author: Brian Buxton
 *
 * Proportional Derivative Controller
 *
 */
PIDController::PIDController( double Kp,  double Ki,  double Kd) {
	if (Kp < 0 || Ki < 0 || Kd < 0)
		throw std::domain_error("Negative arguments are not allowed");

  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

double PIDController::compute(double currentVelocity, double targetSetPoint) {
  double error = targetSetPoint - currentVelocity;
  double integral = error*1.0;
  double derivative = error/1.0;
  double newVelocity = _Kp*error + _Ki*integral + _Kd*derivative; 
  return newVelocity;
}


#include <gtest/gtest.h>
#include <stdexcept>
#include "PIDController.h"

TEST(PIDControllerConstructor, OnlyPositiveValuesForKpKiKd) {
  EXPECT_THROW(PIDController(-1.0, -2.1, -3.2), std::domain_error);
}

TEST(PIDController, Compute_CurrentAndTargetSetPointAreTheSame) {
  /* No Change needed if the current and computed velocity are the same */
  PIDController controller = PIDController(1.0, 0.0, 0.0);
  EXPECT_EQ(0, controller.compute(100, 100));
  EXPECT_EQ(0, controller.compute(10, 10));
  EXPECT_EQ(0, controller.compute(-10, -10));
}

TEST(PIDController, Compute_PositivePowerWhenVelecityBelowSetPoint) {
  /* If measured velocity is less than set point, need more power to equalize
   * given only proportional gain is set */
  PIDController controller = PIDController(1.0, 0.0, 0.0);
  EXPECT_GT(controller.compute(50, 100), 0);
}

TEST(PIDController, Compute_NegativeOutputWhenVelecityAboveSetPoint) {
  /* If measured velocity is greater than set point, need less power to equalize
   * given only proportional gain is set */
  PIDController controller = PIDController(1.0, 0.0, 0.0);
  EXPECT_LT(controller.compute(100, 50), 0);
}

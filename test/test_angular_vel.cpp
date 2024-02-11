#include <gtest/gtest.h>

#include <serial_interface/frame_types.hpp>

#define FLOAT_TOLERANCE 0.001

TEST(test_libserial_bridge, test_getter) {
  serial::AngularVel vel;

  EXPECT_TRUE(abs(vel.getRoll()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(vel.getPitch()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(vel.getYaw()) < FLOAT_TOLERANCE);
}

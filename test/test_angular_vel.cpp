#include <gtest/gtest.h>

#include <serial_interface/frame_types.hpp>

TEST(test_libserial_bridge, test_getter) {
  serial::AngularVel vel;

  EXPECT_TRUE(abs(vel.getRoll()) < 0.0);
  EXPECT_TRUE(abs(vel.getPitch()) < 0.0);
  EXPECT_TRUE(abs(vel.getYaw()) < 0.0);
}

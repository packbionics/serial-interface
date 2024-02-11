#include <gtest/gtest.h>

#include <serial_interface/frame_types.hpp>

#define FLOAT_TOLERANCE 0.001

TEST(test_libserial_bridge, test_getter) {
  serial::LinearAccel accel;

  EXPECT_TRUE(abs(accel.getX()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(accel.getY()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(accel.getZ()) < FLOAT_TOLERANCE);
}

#include <gtest/gtest.h>

#include <serial_interface/frame_types.hpp>

TEST(test_libserial_bridge, test_getter) {
  serial::LinearAccel accel;

  EXPECT_TRUE(abs(accel.getX()) < 0.0);
  EXPECT_TRUE(abs(accel.getY()) < 0.0);
  EXPECT_TRUE(abs(accel.getZ()) < 0.0);
}

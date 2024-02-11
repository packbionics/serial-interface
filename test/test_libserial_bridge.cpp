#include <gtest/gtest.h>

#include <serial_interface/libserial_bridge.hpp>

#define FLOAT_TOLERANCE 0.001

TEST(test_libserial_bridge, test_constructor) {

  std::shared_ptr<serial::LibSerialBridge> bridge;
  try {
    bridge =
      std::make_shared<serial::LibSerialBridge>("/dev/ttyUSB0", LibSerial::BaudRate::BAUD_9600);
  } catch (const std::exception & exc) {
    EXPECT_EQ("Bad file descriptor", std::string(exc.what()));
  }

  EXPECT_EQ(nullptr, bridge);

  bridge = std::make_shared<serial::LibSerialBridge>();

  serial::ImuPtr imuPtr = bridge->getImu(0);

  serial::LinearAccel accel = imuPtr->getLinear();
  serial::AngularVel vel = imuPtr->getAngular();

  EXPECT_TRUE(abs(vel.getRoll()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(vel.getPitch()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(vel.getYaw()) < FLOAT_TOLERANCE);

  EXPECT_TRUE(abs(accel.getX()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(accel.getY()) < FLOAT_TOLERANCE);
  EXPECT_TRUE(abs(accel.getZ()) < FLOAT_TOLERANCE);
}

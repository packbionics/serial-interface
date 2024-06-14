#include <gtest/gtest.h>

#include <serial_interface/libserial_bridge.hpp>

#define FLOAT_TOLERANCE 0.001

TEST(test_libserial_bridge, test_constructor) {

  std::shared_ptr<serial::LibSerialBridge> bridge;
  try {
    bridge =
      std::make_shared<serial::LibSerialBridge>("INVALID FILE", LibSerial::BaudRate::BAUD_9600);
  } catch (const std::exception & exc) {
    EXPECT_EQ(
      "Bad file descriptor",
      std::string(exc.what())) <<
      "Constructor should fail when not given a valid file path to a serial port.";
  }

  EXPECT_EQ(nullptr, bridge);

  bridge = std::make_shared<serial::LibSerialBridge>();

  serial::ImuPtr imuPtr = bridge->getImu(0);
  EXPECT_NE(nullptr, imuPtr) << "At least 1 reference to an IMU should exist.";
}

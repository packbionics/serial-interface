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

  std::vector<double> accel = imuPtr->getLinear();
  std::vector<double> vel = imuPtr->getAngular();
  std::vector<double> orientation = imuPtr->getOrientation();

  for(size_t i = 0; i < accel.size(); i++) {
    EXPECT_TRUE(abs(accel[i]) < FLOAT_TOLERANCE);
  }

  for(size_t i = 0; i < vel.size(); i++) {
    EXPECT_TRUE(abs(vel[i]) < FLOAT_TOLERANCE);
  }

  for(size_t i = 0; i < orientation.size(); i++) {
    EXPECT_TRUE(abs(orientation[i]) < FLOAT_TOLERANCE);
  }
}

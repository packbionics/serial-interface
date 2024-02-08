#include <gtest/gtest.h>

#include <serial_interface/libserial_bridge.hpp>

TEST(test_libserial_bridge, test_constructor) {
  EXPECT_NO_THROW(std::make_shared<serial::LibSerialBridge>());
}

// Copyright 2024 Pack Bionics
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#ifndef SERIAL_INTERFACE__MCU_INTERFACE_HPP_
#define SERIAL_INTERFACE__MCU_INTERFACE_HPP_

#include <libserial/SerialPort.h>

#include <memory>
#include <sensor_msgs/msg/imu.hpp>

#include "sensor_state.hpp"
#include "stream_parser.hpp"


/**
 * @brief Maintains an internal representation of the sensor data read from a microcontroller
 *
 * This class possesses behavior for retrieving the most current sensor data from
 * the IMU and updating the internal state based on data read from a
 * given serial port.
 *
 */
class MCUInterface
{
public:
  /**
   * @brief Construct a new MCUInterface object
   *
   * @param port pointer to a handler for reading a stream of characters from a microcontroller
   */
  explicit MCUInterface(std::shared_ptr<LibSerial::SerialPort> port);

  /**
   * @brief Update the internal state of the interface with the latest information from the MCU
   *
   */
  void processStream();

  /**
   * @brief Get the Imu object
   *
   * @return std::shared_ptr<sensor_msgs::msg::Imu>
   */
  std::shared_ptr<sensor_msgs::msg::Imu> getImu();

  /**
   * @brief Get the Knee Signal object
   *
   * @return double
   */
  double getKneeSignal();

private:
  void setPort(std::shared_ptr<LibSerial::SerialPort> port);
  void setStreamParser(std::shared_ptr<StreamParser> streamParser);

  std::shared_ptr<LibSerial::SerialPort> mPort;
  std::shared_ptr<SensorState> mState;
  std::shared_ptr<StreamParser> mStreamParser;
};


#endif  // SERIAL_INTERFACE__MCU_INTERFACE_HPP_

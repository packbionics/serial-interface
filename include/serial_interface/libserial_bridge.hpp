// Copyright 2023 Pack Bionics
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


// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef LIBSERIAL_BRIDGE_HPP
#define LIBSERIAL_BRIDGE_HPP

#include <libserial/SerialPort.h>

#include <string>
#include <map>

#include <serial_interface/frame_types.hpp>

namespace serial
{

typedef std::shared_ptr<ImuFrame> ImuPtr;

/**
 * @brief Provides a direct interface to sensors and actuators
 *
 */
class LibSerialBridge
{
public:
  /**
   * @brief Construct a new Lib Serial Adapter object
   *
   */
  LibSerialBridge();

  /**
   * @brief Construct a new Lib Serial Adapter object
   *
   * @param name file name of the serial port
   * @param baudRate BAUD rate at which data is communicated
   * @throws LibSerial::AlreadyOpen if the port is alread open
   * @throws LibSerial::OpenFailed if the port could not be opened
   * @throws UnsupportedBaudRate if an invalid BAUD rate is provided
   * @throws std::invalid_argument if an invalid argument is provided
   */
  LibSerialBridge(std::string name, LibSerial::BaudRate baudRate);

  /**
   * @brief Get the Imu object based on a given index
   *
   * @param index identifies the IMU to retrieve
   * @return ImuPtr reference to the IMU data
   */
  ImuPtr getImu(size_t index);

  /**
   * @brief Sends a stream of bytes through the serial connections
   *
   * @param data collection of bytes to send to controller
   * @return true if the data was successfully written to the port or false otherwise
   */
  bool writeData(const std::string &data);

  /**
   * @brief Update the internal representation of the sensor measurements
   * 
   */
  void update();

private:
  /**
   * @brief Add a representation of an IMU
   *
   */
  void addImu();

  /**
   * @brief Converts the raw data retrieved from the serial communication device into a structured format
   * 
   * @param data represents the measurements from the sensors, the keys represent the semantic meaning of the values
   */
  void parseData(std::map<std::string, double> &data);

  /**
   * @brief Read a sequence of data and store it in the given buffer.
   *
   * The given buffer is assumed to be at least as large as the given capacity. The
   * function may return a value less than the capacity if there is no more data to read.
   *
   * @param data buffer to store processed data
   * @param capacity upper bound on the number of bytes read
   * @return the number of bytes processed
   */
  size_t readData(std::string &data, size_t capacity);

  /** Provides an interface to the embedded controller through serial communication */
  std::shared_ptr<LibSerial::SerialPort> port;

  /** Stores data for one or more inertial measurement units (IMU) */
  std::vector<ImuPtr> imus;

  static constexpr size_t RD_TIMEOUT = 200;

  static std::string X_KEY;
  static std::string Y_KEY;
  static std::string Z_KEY;

  static std::string ROLL_KEY;
  static std::string PITCH_KEY;
  static std::string YAW_KEY;
};
}

#endif // LIBSERIAL_BRIDGE_HPP

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

#include <serial_interface/libserial_bridge.hpp>

#include <vector>
#include <memory>

namespace serial
{

std::string LibSerialBridge::X_KEY = "x";
std::string LibSerialBridge::Y_KEY = "y";
std::string LibSerialBridge::Z_KEY = "z";

std::string LibSerialBridge::ROLL_KEY = "r";
std::string LibSerialBridge::PITCH_KEY = "p";
std::string LibSerialBridge::YAW_KEY = "y";

LibSerialBridge::LibSerialBridge()
{

  // Set up the connection with the serial port
  port = std::make_shared<LibSerial::SerialPort>();

  addImu();
}

LibSerialBridge::LibSerialBridge(std::string name, LibSerial::BaudRate baudRate)
{

  // Set up the connection with the serial port
  port = std::make_shared<LibSerial::SerialPort>(name);
  port->SetBaudRate(baudRate);

  addImu();
}

ImuPtr LibSerialBridge::getImu(size_t index)
{
  if (index >= imus.size()) {
    throw std::runtime_error("Index out of bounds.");
  }
  return imus[index];
}

double LibSerialBridge::getKneeAngle()
{
  return 0.0;
}

void LibSerialBridge::addImu()
{
  imus.push_back(std::make_shared<ImuFrame>());
}

bool LibSerialBridge::updateInput(const std::vector<double> inputs)
{
  std::string serializedData = "";
  return writeData(serializedData);
}

bool LibSerialBridge::writeData(const std::string & data)
{
  if (port->IsOpen()) {
    port->Write(std::string(data));
    return true;
  }

  return false;
}

void LibSerialBridge::update()
{

}

size_t LibSerialBridge::readData(std::string & data, size_t capacity)
{

  // Ensure there is enough space to fit the limit
  if (data.size() < capacity) {
    data.resize(capacity);
  }

  // Check if the port is open before reading
  if (!port->IsOpen()) {
    return false;
  }

  size_t counter = 0;

  // Continue reading until there is no more data or the limit is reached
  while (port->IsDataAvailable() && counter < capacity) {

    try {
      port->ReadByte(data[counter], LibSerialBridge::RD_TIMEOUT);
      counter++;
    } catch (const LibSerial::ReadTimeout & exc) {
      return counter;
    }
  }

  return counter;
}

void LibSerialBridge::parseData(std::map<std::string, double> & /*data*/)
{
  throw std::runtime_error("Not yet implemented (LibSerialBridge::parseData).");
}

}

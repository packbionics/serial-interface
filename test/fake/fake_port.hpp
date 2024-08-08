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


#ifndef FAKE__FAKE_PORT_HPP_
#define FAKE__FAKE_PORT_HPP_

#include <string>

#include <serial_interface/stream_reader.hpp>


/**
 * @brief Defines a testing interface to simulate the behavior of reading a stream of characters
 *
 */
class FakePort : public StreamReader
{
public:
  explicit FakePort(const std::string & portName);

  std::string getBytes(std::size_t numBytes) override;

  std::string getLine(const std::string & delimiter) override;

private:
  std::string mTestData;
};


#endif  // FAKE__FAKE_PORT_HPP_

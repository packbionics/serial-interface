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


#include "fake/fake_port.hpp"


FakePort::FakePort(const std::string & portName)
: StreamReader(portName)
{
  mTestData =
    "0.5\n"
    "-0.2\n"
    "57.309\n";
}

std::string FakePort::getBytes(std::size_t /*numBytes*/)
{
  return "";
}

std::string FakePort::getLine(const std::string & delimiter)
{
  const size_t delimiterPos = mTestData.find(delimiter);

  // Check if there are no more complete lines to read
  if (std::string::npos == delimiterPos) {
    return "";
  }

  std::string result = mTestData.substr(0, delimiterPos);

  mTestData = mTestData.substr(delimiterPos + 1);
  return result;
}

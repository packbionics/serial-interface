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


#ifndef SERIAL_INTERFACE__STREAM_READER_HPP_
#define SERIAL_INTERFACE__STREAM_READER_HPP_

#include <vector>
#include <string>


/**
 * @brief Provides an interface for reading a stream of characters
 *
 */
class StreamReader
{
public:
  /**
   * @brief Construct a new Stream Reader object
   *
   * @param source describes the source of the character stream
   */
  explicit StreamReader(const std::string & /*source*/)
  {}

  /**
   * @brief Get the next sequence of bytes
   *
   * @param numBytes maximum number of bytes to read before returning
   * @return std::string
   */
  virtual std::string getBytes(size_t numBytes) = 0;

  /**
   * @brief Get the next line
   *
   * @param delimiter sequence of characters used to mark the end of a line
   * @return std::string
   */
  virtual std::string getLine(const std::string & delimiter) = 0;
};


#endif  // SERIAL_INTERFACE__STREAM_READER_HPP_

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


#ifndef SERIAL_INTERFACE__STREAM_PARSER_HPP_
#define SERIAL_INTERFACE__STREAM_PARSER_HPP_

#include "stream_reader.hpp"

#include <memory>

#include "sensor_state.hpp"


/**
 * @brief Converts a stream of raw character data into a representation of sensor state
 *
 * This class serves as a base class which describes common functionality
 * for all stream parsers.
 *
 */
class StreamParser
{
public:

  /**
   * @brief Retrieve the next sensor state
   * 
   * This function generates and returns sensor data from the next available
   * chunk of data from the input stream. If a field is not contained in the
   * data chunk, it is assigned a sentinel value.
   * 
   * @param port source of the data stream
   * @return std::shared_ptr<SensorState> 
   */
  virtual std::shared_ptr<SensorState> next(std::shared_ptr<StreamReader> port) = 0;
};


#endif  // SERIAL_INTERFACE__STREAM_PARSER_HPP_

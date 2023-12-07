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

#ifndef DATA_FRAME_HPP
#define DATA_FRAME_HPP

#include <serial_interface/frame_types.hpp>

namespace serial
{

/**
 * @brief Unstructured representation of message received through serial port
 * 
 */
class DataFrame
{
public:

    /**
     * @brief Construct a new Data Frame object
     * 
     * @param data raw bytes received through serial port
     */
    DataFrame(const char *data);

    /**
     * @brief Interprets the raw bytes as IMU sensor data
     * 
     * This method constructs an ImuFrame with values corresponding
     * to the stored bytes. The returned object stores a structured copy
     * of the data
     * 
     * @return ImuFrame structured copy of the message data
     */
    ImuFrame asImu();

    /**
     * @brief Interprets the raw bytes as IMU sensor data
     * 
     * This method constructs an LoadCellFrame with values corresponding
     * to the stored bytes. The returned object stores a structured copy
     * of the data
     * 
     * @return LoadCellFrame structured copy of the message data
     */
    LoadCellFrame asLoadCell();
private:

    /** Stores the contents of the message frame */
    const char *data;
};

}

#endif // DATA_FRAME_HPP
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

#ifndef FRAME_TYPES_HPP
#define FRAME_TYPES_HPP

#include <cstring>
#include <vector>

namespace serial
{

/**
 * @brief Structured representation of sensor data provided by an IMU (inertial measurement unit)
 *
 */
class ImuFrame
{
public:
  /**
   * @brief Construct a new Imu Frame object
   *
   * @param linAccel structured representation of the linear acceleration
   * @param angVel structured representation of the angular velocity
   */
  ImuFrame(
    const std::vector<double> orientation, const std::vector<double> & linAccel,
    const std::vector<double> & angVel)
  : mOrientation(orientation), mLinAccel(linAccel), mAngVel(angVel)
  {}

  ImuFrame()
  : mOrientation({0.0, 0.0, 0.0, 1.0}), mLinAccel({1.0, 0.0, 0.0}), mAngVel({0.0, 0.0, 0.0})
  {}

  /**
   * @brief Get the orientation
   *
   * @return std::vector<double>
   */
  std::vector<double> getOrientation()
  {
    return mOrientation;
  }

  /**
   * @brief Get the linear acceleration
   *
   * @return std::vector<double>
   */
  std::vector<double> getLinear()
  {
    return mLinAccel;
  }

  /**
   * @brief Get the angular velocity
   *
   * @return std::vector<double>
   */
  std::vector<double> getAngular()
  {
    return mAngVel;
  }

private:
  std::vector<double> mOrientation;
  std::vector<double> mLinAccel;
  std::vector<double> mAngVel;
};

}

#endif // FRAME_TYPES_HPP

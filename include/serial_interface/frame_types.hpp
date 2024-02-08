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

#define LINEAR_COMPONENTS 3
#define ANGULAR_COMPONENTS 3

namespace serial
{

static constexpr unsigned int INDEX_X = 0;
static constexpr unsigned int INDEX_Y = 1;
static constexpr unsigned int INDEX_Z = 2;

static constexpr unsigned int INDEX_ROLL = 0;
static constexpr unsigned int INDEX_PITCH = 1;
static constexpr unsigned int INDEX_YAW = 2;

/**
 * @brief Structured representation of the linear acceleration of an object
 *
 */
struct LinearAccel
{
  /** Maintains linear acceleration components */
  double mData[LINEAR_COMPONENTS];

  LinearAccel()
  {
    mData[INDEX_X] = 0.0;
    mData[INDEX_Y] = 0.0;
    mData[INDEX_Z] = 0.0;
  }

  /**
   * @brief Construct a new Linear Accel object
   *
   * @param data array containing ordered values for the x, y, and z components
   */
  LinearAccel(const double data[LINEAR_COMPONENTS])
  {
    // Copies parameter array contents into mData as the destination
    std::memcpy(mData, data, sizeof(double) * LINEAR_COMPONENTS);
  }

  /**
   * @brief Construct a new Linear Accel object
   *
   * @param x x-coordinate of the linear acceleration
   * @param y y-coordinate of the linear acceleration
   * @param z z-coordinate of the linear acceleration
   */
  LinearAccel(double x, double y, double z)
  {
    mData[INDEX_X] = x;
    mData[INDEX_Y] = y;
    mData[INDEX_Z] = z;
  }

  double getX()
  {
    return mData[INDEX_X];
  }

  double getY()
  {
    return mData[INDEX_Y];
  }

  double getZ()
  {
    return mData[INDEX_Z];
  }
};

/**
 * @brief Structured representation of the angular velocity of an object
 *
 */
struct AngularVel
{
  /** Maintains angular velocity components */
  double mData[ANGULAR_COMPONENTS];

  /**
   * @brief Construct a new Angular Vel object
   *
   * @param data array containing ordered values for the roll, pitch, and yaw components
   */
  AngularVel(const double data[ANGULAR_COMPONENTS])
  {
    // Copies parameter array contents into mData as the destination
    std::memcpy(mData, data, sizeof(double) * ANGULAR_COMPONENTS);
  }

  /**
   * @brief Construct a new Angular Vel object
   *
   * @param roll roll-coordinate of the angular velocity
   * @param pitch pitch-coordinate of the angular velocity
   * @param yaw yaw-coordinate of the angular velocity
   */
  AngularVel(double roll, double pitch, double yaw)
  {
    mData[INDEX_ROLL] = roll;
    mData[INDEX_PITCH] = pitch;
    mData[INDEX_YAW] = yaw;
  }

  double getRoll()
  {
    return mData[INDEX_ROLL];
  }

  double getPitch()
  {
    return mData[INDEX_PITCH];
  }

  double getYaw()
  {
    return mData[INDEX_YAW];
  }
};

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
  ImuFrame(const LinearAccel & linAccel, const AngularVel & angVel)
  : mLinAccel(linAccel), mAngVel(angVel)
  {}

  ImuFrame()
  : mLinAccel(LinearAccel({0.0, 0.0, 0.0})), mAngVel(AngularVel(0.0, 0.0, 0.0))
  {}

  LinearAccel getLinear()
  {
    return mLinAccel;
  }

  AngularVel getAngular()
  {
    return mAngVel;
  }

private:
  LinearAccel mLinAccel;
  AngularVel mAngVel;
};

}

#endif // FRAME_TYPES_HPP

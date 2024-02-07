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

#include <serial_interface/serial_interface.hpp>

namespace serial {

    typedef std::shared_ptr<ImuFrame> ImuPtr;
    typedef std::shared_ptr<LoadCellFrame> LoadCellPtr;

    class LibSerialBridge {
        public:

            /**
             * @brief Construct a new Lib Serial Adapter object
             * 
             */
            LibSerialBridge();

            /**
             * @brief Get the Imu object based on a given index
             * 
             * @param index identifies the IMU to retrieve
             * @return ImuPtr reference to the IMU data
             */
            ImuPtr getImu(int index);

            /**
             * @brief Get the Load Cell object
             * 
             * @param index  identifies the load cell to retrieve
             * @return LoadCellPtr reference to the load cell data
             */
            LoadCellPtr getLoadCell(int index);

        private:

            /**
             * @brief Add a representation of an IMU
             * 
             */
            void addImu();

            /** Stores data for one or more inertial measurement units (IMU) */
            std::vector<ImuPtr> imus;

            /** Stores data for one or more load cells */
            std::vector<LoadCellPtr> loadCells;
    };

}

#endif // LIBSERIAL_BRIDGE_HPP

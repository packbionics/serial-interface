
.. _program_listing_file_include_serial_interface_libserial_bridge.hpp:

Program Listing for File libserial_bridge.hpp
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_serial_interface_libserial_bridge.hpp>` (``include/serial_interface/libserial_bridge.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

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
   
   class LibSerialBridge
   {
   public:
     LibSerialBridge();
   
     LibSerialBridge(std::string name, LibSerial::BaudRate baudRate);
   
     ImuPtr getImu(size_t index);
   
     double getKneeAngle();
   
     bool updateInput(const std::vector<double> inputs);
   
     void update();
   
   private:
     void addImu();
   
     bool writeData(const std::string & data);
   
   
     void parseData(std::map<std::string, double> & data);
   
     size_t readData(std::string & data, size_t capacity);
   
     std::shared_ptr<LibSerial::SerialPort> port;
   
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

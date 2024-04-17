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

#ifndef SERIAL_DECODER_HPP
#define SERIAL_DECODER_HPP

#include <memory>

#include <serial_interface/frame_types.hpp>

namespace serial {

class Field
{
public:
    virtual std::vector<double> get() = 0;
};

class CompositeField : public Field
{
public:
    std::vector<double> get()
    {
        std::vector<double> data;
        for(size_t i = 0; i < fields.size(); i++) {

            // Recursively recover the data of the first field
            std::vector<double> fieldData = fields[i].get();

            // Append the field data to the aggregate data
            data.insert(data.end(), fieldData.begin(), fieldData.end());
        }

        return data;
    }

    void add(Field field)
    {
        fields.push_back(field);
    }
private:
    std::vector<Field> fields;
};

class DataField : public Field
{
public:
    DataField();

    std::vector<double> get()
    {
        return data;
    }
private:
    std::vector<double> data;
};

class DataFrame : public CompositeField
{
public:
    DataFrame(std::shared_ptr<ImuFrame> imuData, const double kneeAngle)
    {
        CompositeField linAccel;
    }
private:
    CompositeField rootField;
};

class SerialDecoder {

    typedef std::shared_ptr<std::vector<double>> VectorPtr;

public:
    std::shared_ptr<DataFrame> processMessage(const char *buffer);
private:
    VectorPtr decodeStream(const char *buffer);

    std::shared_ptr<ImuFrame> readField(VectorPtr buffer, size_t start, size_t end);

    double readKneeAngle(VectorPtr buffer);
};

}

#endif // SERIAL_DECODER_HPP
#pragma once

#include "utils/NonCopyable.h"

class StreamRingBuffer : NonCopyable
{
public:
    StreamRingBuffer(unsigned int size);
    ~StreamRingBuffer();

    template<class T> void WriteValueType(const T& val);

private:
    char* buffer;
};




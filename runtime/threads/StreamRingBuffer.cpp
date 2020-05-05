#include "StreamRingBuffer.h"

StreamRingBuffer::StreamRingBuffer(unsigned int size)
{
    buffer = new char[size];
}

StreamRingBuffer::~StreamRingBuffer()
{
    delete buffer;
    buffer = nullptr;
}

template<class T>
void StreamRingBuffer::WriteValueType(const T& val)
{

}
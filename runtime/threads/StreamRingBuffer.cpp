#include "StreamRingBuffer.h"

StreamRingBuffer::StreamRingBuffer(unsigned int size)
{
    buffer = new char[size];
    initBufferPos(size);
}

StreamRingBuffer::~StreamRingBuffer()
{
    delete buffer;
    buffer = nullptr;
}

static UInt32 Align(UInt32 val, UInt32 alignment) { return (val + alignment - 1) & ~(alignment - 1); }

template<class T>
void StreamRingBuffer::writeValueType(const T& val)
{
    void* pdata = getWritePointer(sizeof(T), alignof(T));
    new(pdata) T(val);
}

void* StreamRingBuffer::getWritePointer(UInt32 size, UInt32 alignment)
{
    size = Align(size, alignment);
    UInt32 pos = Align(writer.pos, alignment);
    UInt32 end = pos + size;
    if (end > writer.available)
    {
        DataOffset offset{ pos,end };
        processOutOfBufferToWrite(offset);
        pos = offset.pos;
        end = offset.end;
    }
    writer.pos = end;
    return &buffer[pos];
}

void StreamRingBuffer::processOutOfBufferToWrite(DataOffset& offset)
{
    if (offset.end > writer.size)
    {
        offset.end -= offset.pos;
        offset.pos = 0;
    }

    while (true)
    {
        writer.available = sharePos.readPos;
        if (offset.end < writer.available)
        {
            return;
        }
        writer.waiting = true;
        writer.signal.wait();
    }

}

template<class T>
const T& StreamRingBuffer::readValueType()
{
    const void* pdata = getReadPointer(sizeof(T), alignof(T));
    const T& src = *reinterpret_cast<const T*>(pdata);
    return src;
}

void* StreamRingBuffer::getReadPointer(UInt32 size, UInt32 alignment)
{
    size = Align(size, alignment);
    UInt32 pos = Align(reader.pos, alignment);
    UInt32 end = pos + size;
    if (end > reader.available)
    {
        
    }
    else 
    {
        //processOutOfBufferToRead()
    }
    writer.pos = end;
    return &buffer[pos];
}

void StreamRingBuffer::processOutOfBufferToRead(DataOffset& offset)
{
    if (offset.end > reader.size)
    {
        offset.end -= offset.pos;
        offset.pos = 0;
    }

    while (true)
    {
        reader.available = sharePos.writePos;
        if (offset.end < reader.available)
        {
            return;
        }
        reader.waiting = true;
        reader.signal.wait();
    }
}

void StreamRingBuffer::initBufferPos(unsigned int size)
{
    writer.pos = 0;
    writer.size = size;
    writer.available = size;

    reader.pos = size;
    reader.size = size;
    reader.available = size;
}

#pragma once

#include "utils/NonCopyable.h"
#include "utils/Types.h"
#include "Semaphore.h"

struct SharePos
{
    UInt32 readPos;
    UInt32 writePos;
};
struct BufferPos
{
    UInt32 pos;
    UInt32 end;
    UInt32 available;
    UInt32 size;
    bool waiting;
    Semaphore signal;
};
struct DataOffset
{
    UInt32 pos;
    UInt32 end;
};
class StreamRingBuffer : NonCopyable
{
public:
    StreamRingBuffer(unsigned int size);
    ~StreamRingBuffer();

    template<class T> void writeValueType(const T& val);
    void* getWritePointer(UInt32 size, UInt32 alignment);
    void processOutOfBufferToWrite(DataOffset& offset);

    template<class T> const T& readValueType();
    void* getReadPointer(UInt32 size, UInt32 alignment);
    void processOutOfBufferToRead(DataOffset& offset);
protected:
    
private:
    char* buffer;
    BufferPos writer;
    BufferPos reader;
    SharePos sharePos;
    void initBufferPos(unsigned int size);
};





#pragma once

#include "threads/StreamRingBuffer.h"

class GfxClient
{
public:
    GfxClient();
    ~GfxClient();
    void clear();
    StreamRingBuffer* startUp();
private:
    StreamRingBuffer* _commandBuffer;
};



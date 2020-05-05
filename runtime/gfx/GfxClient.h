#pragma once

#include "threads/StreamRingBuffer.h"

class GfxClient
{
public:
    GfxClient();
    ~GfxClient();
    void clear();
private:
    StreamRingBuffer* commandBuffer;
};



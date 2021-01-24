#pragma once

#include "threads/StreamRingBuffer.h"

class GfxServer
{
public:
    void startUp(StreamRingBuffer* commandBuffer);
private:
    void run();

    StreamRingBuffer* _commandBuffer;
};


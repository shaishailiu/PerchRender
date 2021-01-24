#include "GfxClient.h"

#define RING_BUFFER_SIZE 1024 * 1024

GfxClient::GfxClient()
{
    
}

GfxClient::~GfxClient()
{
}

void GfxClient::clear()
{
    
}

StreamRingBuffer* GfxClient::startUp()
{
    _commandBuffer = new StreamRingBuffer(RING_BUFFER_SIZE);
    return _commandBuffer;
}

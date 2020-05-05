#include "GfxClient.h"

#define RING_BUFFER_SIZE 1024 * 1024

GfxClient::GfxClient()
{
    commandBuffer = new StreamRingBuffer(RING_BUFFER_SIZE);
}

GfxClient::~GfxClient()
{
}

void GfxClient::clear()
{

}

#include "Engine.h"
#include "log.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::startUp()
{
    Log("Engine start\n");
    StreamRingBuffer* commandBuffer = _gfxClient.startUp();
    _gfxServer.startUp(commandBuffer);
}

void Engine::beginFrame()
{
    _gfxClient.clear();
}

void Engine::endFrame()
{
    
}

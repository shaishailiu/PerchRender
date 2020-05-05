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
    _gfxServer.startUp(); 
}

void Engine::beginFrame()
{
    _gfxClient.clear();
}

void Engine::endFrame()
{
    
}

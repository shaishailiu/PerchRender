#pragma once

#include "utils/Instance.h"
#include "gfx/GfxServer.h"
#include "gfx/GfxClient.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void startUp();
    void beginFrame();
    void endFrame();
private:
    GfxServer _gfxServer;
    GfxClient _gfxClient;
};


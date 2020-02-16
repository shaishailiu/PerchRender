#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "utils/Instance.h"
#include "gfx/GfxServer.h"
#include "gfx/GfxClient.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void startUp();
private:
    GfxServer _gfxServer;
    GfxClient _gfxClient;
};


#endif // !_ENGINE_H_

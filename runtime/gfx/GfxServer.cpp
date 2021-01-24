#include "GfxServer.h"

#include <thread>
#include <mutex>
#include <condition_variable>

#include "log.h"
#include "threads/Semaphore.h"

Semaphore semaphore;


void GfxServer::startUp(StreamRingBuffer* commandBuffer)
{
    this->_commandBuffer = commandBuffer;
    Log("GfxServer::startUp\n");
    std::thread t(&GfxServer::run,this);
    Log("GfxServer::startHasUp\n");
    //semaphore.notify();
    t.detach();
}

void GfxServer::run()
{
    //semaphore.wait();
    while (true)
    {
        Log("GfxServer::run\n");
    }
}


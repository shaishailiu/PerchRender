#include "GfxServer.h"

#include <thread>
#include <mutex>
#include <condition_variable>

#include "log.h"
#include "utils/Semaphore.h"

//Semaphore semaphore;


void GfxServer::startUp()
{
    Log("GfxServer::startUp\n");
    std::thread t(&GfxServer::run,this);
    Log("GfxServer::startUp111\n");
    //semaphore.notify();
    t.detach();
}

void GfxServer::run()
{
    //semaphore.wait();
    //while (true)
    //{
        Log("GfxServer::run\n");
    //}
}


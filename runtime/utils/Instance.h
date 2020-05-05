#pragma once

template<typename T>
T& Instance()
{
    static T t;
    return t;
}


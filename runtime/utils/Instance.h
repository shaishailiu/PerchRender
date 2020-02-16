#ifndef _INSTANCE_H_
#define _INSTANCE_H_

template<typename T>
T& instance()
{
    static T t;
    return t;
}

#endif // !_INSTANCE_H_

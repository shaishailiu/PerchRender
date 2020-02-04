#ifndef _LOG_H_
#define _LOG_H_

#include <android/log.h>

#define Log(...) __android_log_print(ANDROID_LOG_INFO,"render",__VA_ARGS__)

#endif // !_GL_H_
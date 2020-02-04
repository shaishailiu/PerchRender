cmake_minimum_required(VERSION 3.4.1)

#project(gl2jni)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(ANDROID_ROOT_FOLDER ../../../../../../)
include_directories(${ANDROID_ROOT_FOLDER}/runtime/
        ${ANDROID_ROOT_FOLDER}/platformDependent/android
        )
file(GLOB runtime ${ANDROID_ROOT_FOLDER}/runtime/*/*.cpp ${ANDROID_ROOT_FOLDER}/platformDependent/android/*.cpp)

add_library(gl2jni SHARED
        GfxAndroid.cpp
        ${runtime}
        )

# add lib dependencies
target_link_libraries(gl2jni
                      android
                      log 
                      EGL
                      GLESv2
        )


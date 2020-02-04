cmake_minimum_required(VERSION 3.5)

project(Render)

set(ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../../)
file(GLOB RUNTIME_SRC ${ROOT_FOLDER}/runtime/*/*.*)
file(GLOB DEPENDENT_SRC ${ROOT_FOLDER}/platformDependent/win/*.*)

function(assign_source_group)
    if(MSVC)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${ROOT_FOLDER}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
    endif(MSVC)
endfunction(assign_source_group)

function(group_vs)
    foreach(_source IN ITEMS ${ARGN})
        assign_source_group(${_source})
    endforeach()
endfunction(group_vs)

# GLFW3
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
#add_subdirectory(${ROOT_FOLDER}/libs/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glfw ${CMAKE_CURRENT_BINARY_DIR}/libs/glfw)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../runtime ${CMAKE_CURRENT_BINARY_DIR}/runtime)

# glm
include_directories(
        ${ROOT_FOLDER}/libs/glad/include/
        ${ROOT_FOLDER}/libs/glfw/include/
        ${ROOT_FOLDER}/libs/glm/
        ${ROOT_FOLDER}/runtime/
        ${ROOT_FOLDER}/platformDependent/win/
        )

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

# glad.c
set(GLAD_FILES ${ROOT_FOLDER}/libs/glad/src/glad.c)

# LIBs
set(COMMON_LIBS glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

file(GLOB SOURCES "main.cpp" ${RUNTIME_SRC} ${DEPENDENT_SRC} ${GLAD_FILES})

group_vs(${SOURCES})

add_executable(Render ${SOURCES})

target_link_libraries(Render ${COMMON_LIBS})

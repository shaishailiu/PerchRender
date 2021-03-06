cmake_minimum_required (VERSION 3.2)
project (render C CXX)
enable_testing()

set(ROOT_FOLDER ../../../)
include_directories(${ROOT_FOLDER}/runtime/  ${ROOT_FOLDER}/platformDependent/ios/ )

MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )

# Add some sanitary checks that the toolchain is actually working!
include(CheckCXXSymbolExists)
check_cxx_symbol_exists(kqueue sys/event.h HAVE_KQUEUE)
if(NOT HAVE_KQUEUE)
  message(FATAL_ERROR "kqueue NOT found!")
else()
  message(STATUS "kqueue found!")
endif()

find_library(HAVE_UIKIT UIKit)
if (NOT HAVE_UIKIT)
  message(FATAL_ERROR "UIKit.framework NOT found!")
else()
  message(STATUS "UIKit.framework found!")
endif()

# Hook up XCTest for the supported plaforms (all but WatchOS)
if(NOT PLATFORM MATCHES ".*WATCHOS.*")
  # Use the standard find_package, broken between 3.14.0 and 3.14.4 at least for XCtest...
  find_package(XCTest)
  # Fallback: Try to find XCtest as host package via toochain macro (should always work)
  find_host_package(XCTest REQUIRED)
endif()

# Includes
include_directories(${render_SOURCE_DIR})

# Make sure try_compile() works
include(CheckTypeSize)
check_type_size(time_t SIZEOF_TIME_T)

# Source files
#set(SOURCES core.cpp coreIOS.mm)
file(GLOB SOURCES GfxIOS.mm ${ROOT_FOLDER}/runtime/*/*.cpp ${ROOT_FOLDER}/platformDependent/ios/*.cpp)

# Headers
#set(HEADERS core.h coreIOS.h)
file(GLOB HEADERS GfxIOS.h ${ROOT_FOLDER}/runtime/*/*.h ${ROOT_FOLDER}/platformDependent/ios/*.h)

# Library
if(BUILD_SHARED)
  add_library (render SHARED ${SOURCES} ${HEADERS})
  message(STATUS "Building shared version...")
else()
  add_library (render STATIC ${SOURCES} ${HEADERS})
  message(STATUS "Building static version...")
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${render_SOURCE_DIR}/../render/libs CACHE PATH "Install path" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Executable
#add_executable (helloworld main.cpp)

# Link the library with the executable
#target_link_libraries(helloworld example)

# Debug symbols set in XCode project
set_xcode_property(render GCC_GENERATE_DEBUGGING_SYMBOLS YES "All")

# Installation
install (TARGETS render DESTINATION lib)
install (FILES ${HEADERS} DESTINATION include)

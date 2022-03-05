cmake_minimum_required(VERSION 3.22.0) 
project(CxxDrill LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
 	# Build with both optimization and debug information.
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, one of: , Release, RelWithDebInfo, MinSizeRel" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS 
)

add_executable(myApp
    ${SRCS}
)

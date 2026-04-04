cmake_minimum_required(VERSION 4.2)
project(CPPKube)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(RayCPPKube)
include_directories(raylib)
include_directories(raylib/include)

add_executable(CPPKube
        include/TeaLib.h
        RayCPPKube/RayCPPKube.cpp
        RayCPPKube/RayCPPKube.h
        raylib/include/raygui.h
        raylib/include/raylib.h
        raylib/include/raymath.h
        raylib/include/rlgl.h
        raylib/lib/libraylib.a
        raylib/lib/libraylibdll.a
        raylib/lib/raylib.dll
        raylib/lib/raylib.lib
        raylib/lib/raylibdll.lib)

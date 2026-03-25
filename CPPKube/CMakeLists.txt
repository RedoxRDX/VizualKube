cmake_minimum_required(VERSION 3.15)
project(RayCPPKube)

set(CMAKE_CXX_STANDARD 17)

# sources
file(GLOB_RECURSE SOURCES *.cpp)

add_executable(RayCPPKube ${SOURCES})

# raylib (chemin relatif depuis CPPKube)
add_subdirectory(../raylib raylib_build)

target_link_libraries(RayCPPKube raylib)

# includes
target_include_directories(RayCPPKube PRIVATE . ../raylib/include)
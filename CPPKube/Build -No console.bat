@echo off
if not exist BUILD mkdir BUILD
g++ -O3 -DNDEBUG "RayCPPKube\RayCPPKube.cpp" ^
    -I"./include" -I"./raylib/include" ^
    -L"./raylib/lib" ^
    -lraylib -lopengl32 -lgdi32 -lwinmm ^
    -mwindows -s ^
    -o "BUILD\RayCPPKube.exe"
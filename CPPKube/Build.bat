if not exist BUILD mkdir BUILD
g++ -O3 -DNDEBUG "RayCPPKube\RayCPPKube.cpp" ^
    -I"./include" -I"./raylib/include" ^
    -L"./raylib/lib" ^
    -lraylib -lopengl32 -lgdi32 -lwinmm ^
    -w ^
    -o "BUILD\RayCPPKube.exe"
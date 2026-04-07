@echo off
if not exist BUILD mkdir BUILD
CD BUILD
if not exist Win mkdir Win
CD ..
if exist resource.rc (
    windres resource.rc -O coff -o BUILD\icon.res
)

set ICON_RES=
if exist BUILD\icon.res set ICON_RES=BUILD\icon.res

echo building RayCPPKube gui only (win)
g++ -O3 -DNDEBUG "RayCPPKube\RayCPPKube.cpp" %ICON_RES% ^
    -I"./RayCPPKube" -I"./RayCPPKube/include" -I"./RayCPPKube/raylib/include" ^
    -L"./RayCPPKube/raylib/lib" ^
    -lraylib -lopengl32 -lgdi32 -lwinmm ^
    -static-libgcc -static-libstdc++ -static ^
    -ffunction-sections -fdata-sections -Wl,--gc-sections ^
    -mwindows -s -w ^
    -o "BUILD\Win\RayCPPKube.exe"

echo building RayCPPKube with Console (win)
g++ -O3 -DNDEBUG "RayCPPKube\RayCPPKube.cpp" %ICON_RES% ^
    -I"./RayCPPKube" -I"./RayCPPKube/include" -I"./RayCPPKube/raylib/include" ^
    -L"./RayCPPKube/raylib/lib" ^
    -lraylib -lopengl32 -lgdi32 -lwinmm ^
    -static-libgcc -static-libstdc++ -static ^
    -ffunction-sections -fdata-sections -Wl,--gc-sections ^
    -w -s ^
    -o "BUILD\Win\RayCPPKubeKonsole.exe"
echo deleting tmp files
cd BUILD
del icon.res

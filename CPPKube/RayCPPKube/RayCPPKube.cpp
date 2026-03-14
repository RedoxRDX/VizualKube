#include "../include/TeaLib.h"
#include "../raylib/include/Raylib.h"

using namespace TeaLib;

int main()
{
    printLine("Loading...");
    std::string TeaLibVersionLoaded = TeaLibVersion();
    printLine("TeaLib " + TeaLibVersionLoaded + " Loaded");
    printLine("Initializing Raylib...");
    InitWindow(800, 600, "visualKube 3D");
    printLine("Raylib Initialized");
    SetTargetFPS(60);
    Vector3 position = { 0, 0, 0 };
    Camera3D camera = { 0 };
    camera.position = { 4.0f, 4.0f, 4.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetWindowTitle("VKube");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("CPPVKube", 10, 10, 20, RAYWHITE);

        BeginMode3D(camera);

        DrawCube(position, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(position, 2.0f, 2.0f, 2.0f, BLUE);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}

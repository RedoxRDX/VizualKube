#include "../include/TeaLib.h"
#include "../raylib/include/Raylib.h"
#include "../raylib/include/rlgl.h" // Indispensable pour les transformations manuelles

using namespace TeaLib;

int main()
{
    InitWindow(800, 600, "VKube");
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = { 4.0f, 4.0f, 4.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float rotationAngle = 0.0f;

    while (!WindowShouldClose()) {

        rotationAngle += 1.5f;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("CPPVKube", 10, 10, 20, RAYWHITE);
        BeginMode3D(camera);
        rlPushMatrix();
        rlRotatef(rotationAngle, 0, 1, 0);
        DrawCube(Vector3{ 0,0,0 }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(Vector3{ 0,0,0 }, 2.0f, 2.0f, 2.0f, WHITE);
        rlPopMatrix();

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
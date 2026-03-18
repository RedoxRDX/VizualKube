#define _CRT_SECURE_NO_WARNINGS

#include "../include/TeaLib.h"
#include "../raylib/include/Raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../raylib/include/RayGui.h"
#include "../raylib/include/rlgl.h" 
#include "RayCPPKube.h"
using namespace TeaLib;

int main()
{




    std::string TeaLibActualVersion = TeaLibVersion();
    printLine("Inisialating TeaLib " + TeaLibActualVersion);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(600, 800, "VKube");
    SetTargetFPS(60);
    Camera3D camera = { 0 };
    camera.position = { 4.0f, 4.0f, 4.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    float X_axis_size = 2.0f;
    float Z_axis_size = 2.0f;
    float Y_axis_size = 2.0f;
    float rotationAngle = 0.0f;
    float rotationSpeed = 0.5f;


    bool rotating = true;
    SetWindowFocused();
    while (!WindowShouldClose()) {


        if (rotating == true)
        {
            rotationAngle += rotationSpeed;

        }

        else {}

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("CPPVKube", 10, 10, 20, RAYWHITE);
        BeginMode3D(camera);
        rlPushMatrix();
        rlRotatef(rotationAngle, 0, 1, 0);
        DrawCube(Vector3{ 0,0,0 }, X_axis_size, Z_axis_size, Y_axis_size, RED);
        DrawCubeWires(Vector3{ 0,0,0 }, X_axis_size, Z_axis_size, Y_axis_size, WHITE);
        rlPopMatrix();

        EndMode3D();
        GuiSlider(Rectangle{ 60, 40, 150, 20 }, "X Size", TextFormat("%2.2f", X_axis_size), &X_axis_size, 0.1f, 2.5f);
        GuiSlider(Rectangle{ 60, 70, 150, 20 }, "Y Size", TextFormat("%2.2f", Y_axis_size), &Y_axis_size, 0.1f, 2.5f);
        GuiSlider(Rectangle{ 60, 100, 150, 20 }, "Z Size", TextFormat("%2.2f", Z_axis_size), &Z_axis_size, 0.1f, 2.5f);
        GuiSlider(Rectangle{ 60, 140, 150, 20 }, "Speed", TextFormat("%2.2f", rotationSpeed), &rotationSpeed, 0.0f, 5.0f);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}

void UpdateRotationSpeed(float& rotationSpeed)
{
    printLine("Rotation Speed (default 0.5f)");
    print("-->");
    rotationSpeed = readInt();
    clear();
}

void AskSize(float& X_axis_size, float& Z_axis_size, float& Y_axis_size)
{
    printLine("\n----------------------------------------------------");//Really not Cool defeitely make it just better 
    printLine("VKube Is Loaded");
    printLine("\n Wirte the size of the cube X axis (default 2)");
    print("--->");
    X_axis_size = readInt();
    clear();
    //Really not Cool defeitely make it just better 
    printLine("\n Wirte the size of the cube Z axis (default 2)");
    print("--->");
    Z_axis_size = readInt();
    clear();
    //Really not Cool defeitely make it just better is almost  a duplicate
    printLine("\n Wirte the size of the cube Y axis (default 2)");
    print("--->");
    Y_axis_size = readInt();
    clear();
}

void UpdateRotation(bool& rotating)
{

    printLine("Activate Rotation ? (Y/N)");
    std::string ActivateRotationYorN = readString();
    if (ActivateRotationYorN == "Y" or ActivateRotationYorN == "y")
    {
        rotating = true;
        printLine("Rotation Activated");
        clear();
        float rotationSpeed = 0.5f;
        UpdateRotationSpeed(rotationSpeed);
    }
    else if (ActivateRotationYorN == "N" or ActivateRotationYorN == "n") { rotating = false; clear(); }
    else {
        UpdateRotation(rotating);
    }
}

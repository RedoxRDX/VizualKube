#include "../include/TeaLib.h"
#include "../raylib/include/Raylib.h"
#include "../raylib/include/rlgl.h" 
#include "RayCPPKube.h"
using namespace TeaLib;

int main()
{
    std::string TeaLibActualVersion = TeaLibVersion();
    printLine("Inisialating TeaLib "+ TeaLibActualVersion);
    InitWindow(400, 1, "VKube");
    SetTargetFPS(60);
    Camera3D camera = { 0 };
    camera.position = { 4.0f, 4.0f, 4.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    float X_axis_size = 2;
    float Z_axis_size = 2;
    float Y_axis_size = 2;
    float rotationAngle = 0.0f;
	float rotationSpeed = 0.5f;

    AskSize(X_axis_size, Z_axis_size, Y_axis_size);

    bool rotating = false;
    UpdateRotation(rotating);
    UpdateRotationSpeed(rotationSpeed);
    SetWindowSize(500, 600);
    MaximizeWindow();

   printLine("Everyting looks fine...");
    while (!WindowShouldClose()) {

        if (rotating == true) 
        {
            rotationAngle += rotationSpeed;
            
        }

        else {  }

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
        EndDrawing();
       
    }

    CloseWindow();
    return 0;
}

void UpdateRotationSpeed(float& rotationSpeed)
{
    printLine("Rotation Speed (default 0.5)");
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
    }
    else if (ActivateRotationYorN != "Y" or ActivateRotationYorN != "y") { rotating = false; clear(); }
    else {}
}

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

}


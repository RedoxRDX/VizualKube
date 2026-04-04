#pragma once

// TeaLib
// Lightweight header-only console library
// Made by Yel0w 

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

#define TEALIB_VERSION_MAJOR 0
#define TEALIB_VERSION_MINOR 0
#define TEALIB_VERSION_PATCH 3

namespace TeaLib
{


    template<typename T>
    inline void print(const T& message)
    {
        std::cout << message;
    }

    inline void printLine(const std::string& message)
    {
        std::cout << message << '\n';
    }


    inline std::string readString()
    {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    inline int readInt()
    {
        int value;

        while (!(std::cin >> value))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number, try again: ";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }



    inline void clear()
    {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }

    inline void pause()
    {
        std::cout << "Press ENTER to continue...";
        std::cin.get();
    }

    inline void line(int length = 40)
    {
        for (int i = 0; i < length; i++)
            std::cout << "-";
        std::cout << '\n';
    }

    /* =========================
       System info
       ========================= */

    inline std::string findOS()
    {
#ifdef _WIN32
        return "Windows";
#elif __linux__
        return "Linux";
#elif __APPLE__
        return "macOS";
#elif __unix__
        return "Unix";
#else
        return "Unknown";
#endif
    }


    inline std::string TeaLibVersion()
    {
        return std::to_string(TEALIB_VERSION_MAJOR) + "." +
            std::to_string(TEALIB_VERSION_MINOR) + "." +
            std::to_string(TEALIB_VERSION_PATCH);
    }


}

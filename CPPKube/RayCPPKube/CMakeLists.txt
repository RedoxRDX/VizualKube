cmake_minimum_required(VERSION 3.21)

project(RayCPPKube LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(RayCPPKube
    RayCPPKube.cpp
    RayCPPKube.h
)

target_compile_definitions(RayCPPKube PRIVATE _CRT_SECURE_NO_WARNINGS)
target_include_directories(RayCPPKube PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/raylib/include"
)

function(link_raylib_from_vendor target_name)
    set(raylib_root "${CMAKE_CURRENT_SOURCE_DIR}/raylib")
    set(raylib_lib_dir "${raylib_root}/lib")
    set(raylib_include_dir "${raylib_root}/include")

    if(MSVC)
        set(raylib_library "${raylib_lib_dir}/raylib.lib")
        set(raylib_runtime "${raylib_lib_dir}/raylib.dll")
    elseif(MINGW)
        set(raylib_library "${raylib_lib_dir}/libraylib.a")
    endif()

    if(NOT EXISTS "${raylib_library}")
        message(FATAL_ERROR "Bundled raylib library not found: ${raylib_library}")
    endif()

    add_library(raylib_vendor UNKNOWN IMPORTED)
    set_target_properties(raylib_vendor PROPERTIES
        IMPORTED_LOCATION "${raylib_library}"
        INTERFACE_INCLUDE_DIRECTORIES "${raylib_include_dir}"
    )

    target_link_libraries("${target_name}" PRIVATE raylib_vendor)

    if(WIN32)
        target_link_libraries("${target_name}" PRIVATE opengl32 gdi32 winmm)
    endif()

    if(MSVC AND EXISTS "${raylib_runtime}")
        add_custom_command(TARGET "${target_name}" POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "${raylib_runtime}"
                "$<TARGET_FILE_DIR:${target_name}>/raylib.dll"
            VERBATIM
        )
    endif()
endfunction()

if(WIN32 AND (MSVC OR MINGW))
    link_raylib_from_vendor(RayCPPKube)
else()
    find_package(raylib QUIET CONFIG)

    if(raylib_FOUND)
        target_link_libraries(RayCPPKube PRIVATE raylib)
    else()
        include(FindPkgConfig)
        pkg_check_modules(raylib QUIET raylib)

        if(raylib_FOUND)
            target_include_directories(RayCPPKube PRIVATE ${raylib_INCLUDE_DIRS})
            target_link_directories(RayCPPKube PRIVATE ${raylib_LIBRARY_DIRS})
            target_link_libraries(RayCPPKube PRIVATE ${raylib_LIBRARIES})
        else()
            message(FATAL_ERROR
                "raylib was not found. On Windows, use the bundled libraries in RayCPPKube/raylib/lib. "
                "On Linux/macOS, install raylib so CMake can find it."
            )
        endif()
    endif()
endif()

if(MSVC)
    target_compile_options(RayCPPKube PRIVATE /W3 /permissive-)
else()
    target_compile_options(RayCPPKube PRIVATE -Wall -Wextra)
endif()

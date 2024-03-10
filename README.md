# Visual Studio Code SDL2 compile setup for cl.exe (MSVC)

## Initial setup

First follow tutorial at: https://code.visualstudio.com/docs/languages/cpp

## Required directories

In the root directory of the project create 'lib' and 'build' directories.

## Setting up SDL2

To download SDL2 visit https://github.com/libsdl-org/SDL/releases.
Select SDL2-devel-2.xx.x-VC.zip version to download.

Extract to this project lib directory. Resulting directory should be named like SDL2-2.30.0

From "SDL2-2.30.0 > lib > x86" copy file SDL2.dll to the build directory of this project.

In tasks.json update all references to SDL2-2.30.0 to the correct SDL2 version (the one you have downloaded).

If you do not need SDL_image library remove any references to SDL_image library from tasks.json.

## Setting up additonal SDL2 libraries

For example we'll use SDL2_image.

To download SD2_image visit https://github.com/libsdl-org/SDL_image/releases.

Select SD2_image-devel-2.x.x-VC.zip

Extract to this project lib directory. Resulting directory should be named like SDL2_image-2.8.2

From "SDL2_image-2.x.x > lib > x86" copy file SDL2_image.dll to the build directory of this project.

In tasks.json update all references to SDL_image-2.8.2 to the correct SDL_image version (the one you have downloaded).

Repeat the above steps to add any additonal libraries.

While SDL2_image is already added to cl.exe config any additional libraries will have to be added to tasks.json:
* After line 17 add additional library's include directory, follow the pattern from the previous includes for SDL2 and SDL2_image.
* After line 30 add additional library's lib file, follow the pattern from the previous libs for SDL2 and SDL2_image.

## Compiling for x64
By default cl.exe compiles x86. If you want to compile for x64 architecture you'll have to add environment variable
check here https://stackoverflow.com/a/46734431/543559.

* In ".vscode > c_cpp_properties.json" replace references to x86 with x64.
* In ".vscode > tasks.json" replace references to x86 with x64 if x64.
* In ".vscode > settings.json" replace references to x86 with x64 if x64.

## Compiling, running and debugging
Open "Run and Debug" panel (Ctrl+Shift+D). Make sure that "(SPG) Launch Current C++ file" is selected configuration.

Now open a .cpp file (main.cpp is included for example) and either hit F5, or click on play button in "Run and Debug" panel, or click on run/debug button in file tab toolbar.

## Result

A small window should open and stay open for 5 seconds if you have run main.cpp included with this project.
All built files should land in build directory. Otherwise, the .cpp file you have had open should build and run.

If you have any assets e.g. images, you should copy them into the build directory and reference them with relative paths.

Relative paths should be relative to the build directory, not the project root directory.

## Ignored files

Any files in lib and build directories are ignored.
echo off
set arg=%1
gcc -lm -fdiagnostics-color=always -g %arg%.c -o %arg%.exe -IC:/SDL3/SDL3-3.2.8/x86_64-w64-mingw32/include/ -LC:/SDL3/SDL3-3.2.8/x86_64-w64-mingw32/lib -lSDL3

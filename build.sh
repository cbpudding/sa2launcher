#!/bin/bash
clang -target x86_64-w64-mingw32 -nostdinc -fno-exceptions -isystem /usr/x86_64-w64-mingw32/sys-root/mingw/include -isystem /usr/x86_64-w64-mingw32/sys-root/mingw/lib/gcc/x86_64-w64-mingw32/8.2.0/include -L/usr/x86_64-w64-mingw32/sys-root/mingw/lib/gcc/x86_64-w64-mingw32/8.2.0 -o Launcher.exe main.c

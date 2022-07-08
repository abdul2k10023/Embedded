#!/bin/bash

if [ -d "build/" ]; then
rm -rf build
fi
mkdir build
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug -B build/
make -j8 -C build/


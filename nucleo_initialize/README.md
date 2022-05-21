# Commands for build

##cmake
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug ..

make -j4 OR cmake --build . -- -j 4


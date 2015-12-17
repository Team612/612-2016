#!/bin/bash

#satisfy dependencies
echo "Downloading Libraries..."
./.wpilib-download.sh
echo "Downloading Compiler..."
./.compiler-download.sh

#build
cd ./.build
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile

echo "Building..."
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake ..
make VERBOSE=1

#Delete cmake files to keep Eclipse working
echo "Deleting CMakeFiles!"
rm -rf CMakeFiles/
rm -rf ./FRCUserProgram
mv ./FRC* ./FRCUserProgram

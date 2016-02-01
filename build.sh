#!/bin/bash

#satisfy dependencies
echo "build.sh: Downloading Libraries..."
./.wpilib-download.sh
echo "build.sh: Downloading Compiler..."
./.compiler-download.sh

#build
cd ./.build
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile

echo "build.sh: Generating Makefiles..."
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake .. > /dev/null
make VERBOSE=1

#Delete cmake files to keep Eclipse working
echo "build.sh: Deleting CMakeFiles..."
rm -rf CMakeFiles/
rm -rf ./FRCUserProgram
mv ./FRC* ./FRCUserProgram

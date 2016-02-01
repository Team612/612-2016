#!/bin/bash

# Will download required packages for building
# Using -qq and -y on apt-get is considered redundant,
# but it is unlikely that the redundancy is well known,
# so we do both anyways.
# Also, the -qq must go before the command (update, install)

command_exists () {
    type "$1" &> /dev/null ;
}

if command_exists arm-frc-linux-gnueabi-gcc ; then
	:
else
	sudo apt-add-repository -y ppa:wpilib/toolchain > /dev/null 2>&1
	sudo apt-get -qq update -y > /dev/null 2>&1
	sudo apt-get -qq install -y frc-toolchain > /dev/null 2>&1
fi

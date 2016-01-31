#!/bin/bash

# Will download required packages for building
# Using -qq and -y on apt-get is considered redundant,
# but it is unlikely that the redundancy is well known,
# so we do both anyways.

dpkg-query -s frc-toolchain
if [ $? = 1 ]; then
	sudo apt-add-repository -qqy ppa:wpilib/toolchain
	sudo apt-get update -qqy
	sudo apt-get install -qqy frc-toolchain
fi

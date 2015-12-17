#!/bin/bash

# Will download required packages for building
dpkg-query -s frc-toolchain
if [ $? = 1 ]; then
	sudo apt-add-repository -y ppa:byteit101/frc-toolchain 
	sudo apt-get update -y
	sudo apt-get install -y frc-toolchain
fi

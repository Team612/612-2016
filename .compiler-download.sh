#!/bin/bash

# Will download required packages for building
# Using -qq and -y on apt-get is considered redundant,
# but it is unlikely that the redundancy is well known,
# so we do both anyways.
# Also, the -qq must go before the command (update, install)

frcavail="$(dpkg-query -s frc-toolchain)"
if [ "$frcavail" = "1" ]; then
	sudo apt-add-repository -y ppa:wpilib/toolchain > /dev/null
	sudo apt-get -qq update -y > /dev/null
	sudo apt-get -qq install -y frc-toolchain > /dev/null
fi

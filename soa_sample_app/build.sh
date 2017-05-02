#!/bin/sh

# This script is used to build a the SOA library or executable.
export BUILD_DIR=build

# Set build environment variables.
./env.sh

if [ -z "${USE_CCACHE}" ]
then
	export CXX=${BIN}/g++
	export CC=${BIN}/gcc
    export CMAKE_C_COMPILER=${BIN}/gcc
    export CMAKE_CXX_COMPIER=${BIN}/g++
else
    echo "Using ccache"
	export CXX=/usr/lib/ccache/g++
	export CC=/usr/lib/ccache/gcc
fi

if [ ! -d $BUILD_DIR ]
then
	mkdir $BUILD_DIR
	
	if [ -d CMakeModules ]
	then
		mkdir $BUILD_DIR/CMakeModules
		cp -r CMakeModules/ $BUILD_DIR/CMakeModules/
	fi
fi

# Build the binary executable.
cd $BUILD_DIR
cmake ..
make

cd ..


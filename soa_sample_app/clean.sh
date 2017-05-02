#!/bin/sh

# This script is used to delete any cached CMake build files and other temporary files.

if [ -d build ]
then
	rm -Rf build
fi

if [ -f core ]
then
	rm core
fi

if [ -f CMakeCache.txt ]
then
	rm CMakeCache.txt
fi
	
if [ -d CMakeFiles ]
then
	rm -Rf CMakeFiles
fi

if [ -d src/CMakeFiles ]
then
	rm -Rf src/CMakeFiles
fi


echo "Finished cleaning build directories."

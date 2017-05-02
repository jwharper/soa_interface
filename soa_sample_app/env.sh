#!/bin/sh

export BIN=/usr/bin
export CMAKE_CXX_FLAGS="-std=c++11 -Wno-deprecated -Wall -g"

if [ -d /usr/lib/ccache/ ]; then
    export USE_CCACHE=true
fi


# uncomment this to let make run in parallel
export MAKE_ARGS="-j"





#!/bin/bash

# create .proto from YAML
ORIG_DIR="$(pwd)"
cd ..
cd icd
make messages

# copy .proto to /external/proto_buff
cp _build/autonomy.proto $ORIG_DIR"/autonomy.proto"

# run protoc
cd $ORIG_DIR
protoc --cpp_out=src/ autonomy.proto

# copy .h to include
mv src/autonomy.pb.h include/autonomy.pb.h

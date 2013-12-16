#!/bin/bash
DIRNAME=$(pwd)
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DIRNAME/lib:/usr/local/lib
./QtClient

#!/bin/sh

# This is a simple compiler script that will create an executable in the "bin" folder
set -e

sudo mkdir build
cd build
cmake ..
make
cd ..
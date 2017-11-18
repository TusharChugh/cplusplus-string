#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

cmake string || exit 1
make || exit 1



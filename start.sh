#!/bin/bash

curpath=$(dirname $(realpath $0))
cd "$curpath"

make clean
make all

echo "================================================================"

if [ -f "./tree" ]; then
    time ./tree
    echo "================================================================"
    if [ -f "./valgrind.log" ]; then
        rm -f ./valgrind.log
    fi
    valgrind --tool=memcheck --leak-check=full --log-file=./valgrind.log ./tree && cat ./valgrind.log
else
    echo "build failed"
fi
echo "================================================================"
#! /bin/sh

cmake -DUSER_ADDER=on -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B out/build
# cmake -DUSER_ADDER=off -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B out/build

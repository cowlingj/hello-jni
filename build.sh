#!/usr/bin/env bash

set -e

javac -h ./src -d out src/Basic.java
gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o out/libnative.so src/Native.c

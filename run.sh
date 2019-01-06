#!/usr/bin/env bash

set -e

cd out && java -Djava.library.path=. Basic

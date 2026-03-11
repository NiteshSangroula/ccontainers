#!/bin/bash

set -e

echo "Compiling..."

gcc -Wall -Wextra -Werror -std=c11 -Iinclude \
    src/my_string.c tests/test_string.c -o test

echo "Running my_string tests..."

./test

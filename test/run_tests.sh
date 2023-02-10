#!/bin/bash

# Compile the shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Run the tests
for test_case in test_*.c; do
    ./hsh < $test_case
    assert_equal $? 0 "Test case $test_case failed"
done

echo "All tests passed"


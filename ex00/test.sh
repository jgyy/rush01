#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

run_test() {
    input="$1"
    expected="$2"
    echo "Testing input: $input"
    output=$(./rush-01 "$input")
    if [ "$output" == "$expected" ]; then
        echo -e "${GREEN}Test passed${NC}"
    else
        echo -e "${RED}Test failed${NC}"
        echo "Expected:"
        echo "$expected"
        echo "Got:"
        echo "$output"
    fi
    echo
}

gcc -Wall -Wextra -Werror *.c -o rush-01

run_test "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3"

run_test "2 2 2 1 3 2 1 2 2 1 3 2 1 3 2 2" "3 1 2 4
4 2 1 3
1 4 3 2
2 3 4 1"

run_test "1 2 3 3 3 1 2 2 2 3 1 2 2 1 3 2" "4 2 1 3
3 1 4 2
1 4 2 3
2 3 3 1"

run_test "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2" "Error"
run_test "5 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "Error"
run_test "a 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "Error"
run_test "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 3" "Error"

echo "All tests completed."

rm rush-01

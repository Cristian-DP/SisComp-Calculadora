#!/bin/bash

assert_equals () {
  if [ "$1" = "$2" ]; then
    echo -e "$Green $Check_Mark Success $Color_Off"
  else
    echo -e "$Red Failed $Color_Off"
    echo -e "$Red Expected -$1- to equal -$2- $Color_Off"
    Errors=$((Errors  + 1))
    exit 1
  fi
}

response=$(./calc 4 - 2)
assert_equals "$response" "La resta es: 2"
response=$(./calc 4 - 84)
assert_equals "$response" "La resta es: 2"
response=$(./calc 4 - 4)
assert_equals "$response" "La resta es: 2"
response=$(./calc -4 - 2)
assert_equals "$response" "La resta es: 2"
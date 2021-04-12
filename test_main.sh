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

response=$(./calc 6 + 2)
assert_equals "$response" "La suma es: 8"

response=$(./calc -66 + 2)
assert_equals "$response" "La suma es: -64"

response=$(./calc 2 - 4)
assert_equals "$response" "La resta es: -2"

response=$(./calc -2 - 4)
assert_equals "$response" "La resta es: -6"
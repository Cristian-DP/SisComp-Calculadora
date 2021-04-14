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

# test int 
response=$(./calc 6 + 2)
assert_equals "$response" "La suma es: 8"

response=$(./calc -66 + 2)
assert_equals "$response" "La suma es: -64"

response=$(./calc 2 - 4)
assert_equals "$response" "La resta es: -2"

response=$(./calc -2 - 4)
assert_equals "$response" "La resta es: -6"

# test binario 
response=$(./calc -b 110 + 010)
assert_equals "$response" "La suma binaria es: 01000"

response=$(./calc -b 1000000 - 1010)
assert_equals "$response" "La resta binaria es: 0110110"

response=$(./calc -b 1000000 + 1010)
assert_equals "$response" "La suma binaria es: 01001010"
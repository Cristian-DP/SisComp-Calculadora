# Imágenes de los test en jenkins

## Pasos de ejecución
- make
- sh test_main.sh

## Casos de prueba

- **prueba con número enteros** 

response=$(./calc 6 + 2)
assert_equals "$response" "La suma es: 8"

response=$(./calc -66 + 2)
assert_equals "$response" "La suma es: -64"

response=$(./calc 2 - 4)
assert_equals "$response" "La resta es: -2"

response=$(./calc -2 - 4)
assert_equals "$response" "La resta es: -6"

- **prueba con números binarios** 

response=$(./calc -b 110 + 010)
assert_equals "$response" "La suma binaria es: 01000"

response=$(./calc -b 1000000 - 1010)
assert_equals "$response" "La resta binaria es: 0110110"

response=$(./calc -b 1000000 + 1010)
assert_equals "$response" "La suma binaria es: 01001010"

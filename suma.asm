segment .data
;
; los datos iniciados se colocan en el segmento de
; datos ac´a
;

segment .bss
;
; Datos no iniciados se colocan en el segmento bss
;
suma resd 1     ; suma total

segment .text
        global suma_asm
        global suma_binaria_asm

        %define d1   [ebp+8]
        %define d2   [ebp+12]

suma_asm:

    enter 0,0 ; rutina de
    pusha
;
; El c´odigo est´a colocado en el segmento de texto. No modifique el
; c´odigo antes o despu´es de este comentario
;
    mov     eax, d1
    add     eax, d2     ; add arg2 from eax
    mov     [suma], eax

    popa
    mov     eax, [suma]
    leave
    ret
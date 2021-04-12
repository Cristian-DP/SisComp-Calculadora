;segment .data
;
; initialized data is put in the data segment here
;
;segment .bss
;
; uninitialized data is put in the bss segment
;

segment .text
        global  resta_asm

        %define d1   [ebp+8]
        %define d2   [ebp+12]


resta_asm:

        enter   0, 0        ; create stack frame

        mov     eax, d1
        sub     eax, d2     ; subtract arg2 from eax

        leave               ; restore stack frame        
        ret

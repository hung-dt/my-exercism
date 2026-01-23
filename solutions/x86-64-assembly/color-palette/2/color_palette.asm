; Everything that comes after a semicolon (;) is a comment
default rel

section .rodata

; Define the constants 'RED', 'GREEN' and 'BLUE'
; They must be accessible from other source files

global RED, GREEN, BLUE
    RED dd 0xFF000000
    GREEN dd 0x00FF0000
    BLUE dd 0x0000FF00

section .data

; Define the variable 'base_color' with the default value of 0xFFFFFF00
; It must be accessible from other source files
global base_color
    base_color dd 0xFFFFFF00

section .text

; You should implement functions in the .text section

; the global directive makes a function visible to the test files
global get_color_value
get_color_value:
    ; This function takes the address for a color as parameter
    ; It must return the 32-bit value associated with the color
    mov eax, dword [rdi]    ; or mov eax, dword [rdi] or just mov eax, [rdi]
    ret

global add_base_color
add_base_color:
    ; TODO: define the 'add_base_color' function
    ; This function takes the address for a color as parameter
    ; It saves the 32-bit value associated with this color in the variable 'base_color'
    ; This variable must be accessible from other source files
    ; This function has no return value
    mov eax, dword [rdi]
    mov dword [base_color], eax
    ret

extern combining_function

global make_color_combination
make_color_combination:
    ; TODO: define the 'make_color_combination' function
    ; This function takes the following parameters:
    ; - rdi: The address where the 32-bit value for the combined color should be stored.
    ; - rsi: The address of a secondary color in the color table.
    ; It should call 'combining_function' with the 32-bit value for base and secondary colors and store the result in the passed address
    ; This function has no return value
    push rdi    ; save this before calling combining_function

    mov edi, dword [base_color]         ; set 1st param for combining_function
    mov esi, dword [rsi]                ; load secondary color
    call combining_function             ; combined color in rax

    pop rdi
    mov dword [rdi], eax
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

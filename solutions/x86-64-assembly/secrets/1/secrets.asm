; Everything that comes after a semicolon (;) is a comment

PRIVATE_KEY equ 0b1011_0011_0011_1100

section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global extract_higher_bits
extract_higher_bits:
    ; This function has a 16-bit integer as argument.
    ; it returns the higher 8-bit value of the argument.
    mov eax, edi
    shr eax, 8
    ret

; TODO: define the 'extract_lower_bits' function.
global extract_lower_bits
extract_lower_bits:
    ; This function takes one 16-bit integer as argument and must return the lower 8-bit value of it.
    and edi, 0xFF
    mov eax, edi
    ret

; TODO: define the 'extract_redundant_bits' function.
global extract_redundant_bits
extract_redundant_bits:
    ; This function takes one 16-bit integer as argument. Message is the high 8-bit, mask is the low 8-bit
    ; It returns a 8-bit integer with all bits set in both the lower and the higher 8 bits of the argument.
    mov esi, edi                ; backup edi
    call extract_higher_bits    ; higher bits in eax
    and esi, 0xFF               ; get lower 8-bit
    and eax, esi
    ret

; TODO: define the 'set_message_bits' function.
global set_message_bits
set_message_bits:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 8-bit integer with all bits set if they are set in the higher 8 bits of the argument, the others unchanged.
    mov esi, edi                ; backup edi
    call extract_higher_bits    ; higher bits in eax
    and esi, 0xFF               ; get lower 8-bit
    or eax, esi
    ret

; TODO: define the 'rotate_private_key' function.
global rotate_private_key
rotate_private_key:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 16-bit integer with bits of the private key rotated to the left a number of positions equal to the redundant bits.
    ; The private key is 0b1011_0011_0011_1100.
    ; A bit is redundant when it is set in both the lowest 8-bit portion of the argument and the highest 8-bit portion of the argument.
    call extract_redundant_bits
    popcnt ecx, eax    ; count redundant bits
    mov eax, PRIVATE_KEY
    rol ax, cl        ; rotate 16-bit ax reg
    ret

; TODO: define the 'format_private_key' function.
global format_private_key
format_private_key:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 8-bit integer with the private key fully formatted.
    ; To format a private key, you must:
    ; - Rotate it.
    call rotate_private_key
    mov esi, eax    ; back up rotated private key
    ; - Isolate the lowest 8-bit portion of the rotated private key, which is the base value.
    mov edi, esi
    call extract_lower_bits
    mov edx, eax    ; store it
    ; - Isolate the highest 8-bit portion of the rotated private key, which is a mask to be applied to the base value.
    mov edi, esi
    call extract_higher_bits
    ; - Flip set bits in the base value that are also set in the mask.
    xor al, dl
    ; - Flip all bits in the result.
    not al
    ret

; TODO: define the 'decrypt_message' function
global decrypt_message
decrypt_message:
    ; This function takes one 16-bit integer as argument
    ; It returns a 16-bit integer, of which:
    ; - The higher 8 bits are the formatted private key, according to 'format_private_key'
    ; - The lower 8 bits are the message with all bits set, according to 'set_message_bits'
    mov r8w, di                ; store input
    call format_private_key    ; formatted key in rax
    mov r9b, al                ; store formatted key

    mov di, r8w
    call set_message_bits      ; 8-bit message in al

    shl r9w, 8                 ; formatted key in high 8-bit
    or ax, r9w                 ; combine
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

; Everything that comes after a semicolon (;) is a comment

WEIGHT_OF_EMPTY_BOX equ 500
TRUCK_HEIGHT equ 300
PAY_PER_BOX equ 5
PAY_PER_TRUCK_TRIP equ 220

section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global get_box_weight
get_box_weight:
    ; This function takes the following parameters:
    ; rdi - The number of items for the first product in the box, as a 16-bit non-negative integer
    ; rsi - The weight of each item of the first product, in grams, as a 16-bit non-negative integer
    ; rdx - The number of items for the second product in the box, as a 16-bit non-negative integer
    ; rcx - The weight of each item of the second product, in grams, as a 16-bit non-negative integer
    ; The function must return the total weight of a box, in grams, as a 32-bit non-negative integer
    mov rax, WEIGHT_OF_EMPTY_BOX       ; sum = WEIGHT_OF_EMPTY_BOX
    imul rdi, rsi    ; rdi = rdi * rsi = total weight of items of the first product
    add rax, rdi     ; sum += rdi = weight_1
    imul rdx, rcx    ; rdx = rdx * rcx = total weight of items of the second product
    add rax, rdx     ; sum += rdx = weight_1 + weight_2
    ret

global max_number_of_boxes
max_number_of_boxes:
    ; TODO: define the 'max_number_of_boxes' function
    ; This function takes the following parameter:
    ; rdi - The height of the box, in centimeters, as a 8-bit non-negative integer
    ; The function must return how many boxes can be stacked vertically, as a 8-bit non-negative integer
    mov rax, TRUCK_HEIGHT
    mov rdx, 0
    div rdi    ; rax = rax / rdi = TRUCK_HEIGHT / box_height
    ret

global items_to_be_moved
items_to_be_moved:
    ; TODO: define the 'items_to_be_moved' function
    ; This function takes the following parameters:
    ; rdi - The number of items still unaccounted for a product, as a 32-bit non-negative integer
    ; rsi - The number of items for the product in a box, as a 32-bit non-negative integer
    ; The function must return how many items remain to be moved, after counting those in the box, as a 32-bit integer
    sub rdi, rsi    ; rdi = rdi - rsi
    mov rax, rdi
    ret

global calculate_payment
calculate_payment:
    ; TODO: define the 'calculate_payment' function
    ; This function takes the following parameters:
    ; rdi - The upfront payment, as a 64-bit non-negative integer
    ; rsi - The total number of boxes moved, as a 32-bit non-negative integer
    ; rdx - The number of truck trips made, as a 32-bit non-negative integer
    ; rcx - The number of lost items, as a 32-bit non-negative integer
    ; r8 - The value of each lost item, as a 64-bit non-negative integer
    ; r9 - The number of other workers to split the payment/debt with you, as a 8-bit positive integer
    ; The function must return how much you should be paid, or pay, at the end, as a 64-bit integer (possibly negative)
    ; Remember that you get your share and also the remainder of the division
    imul rsi, PAY_PER_BOX           ; rsi = payment for boxes moved
    imul rdx, PAY_PER_TRUCK_TRIP    ; rdx = payment for trips made
    imul rcx, r8                    ; rcx = lost value
    mov rax, rsi                    ; rax = payment for boxes moved
    add rax, rdx                    ; rax += payment for trips made
    sub rax, rcx                    ; rax -= lost value
    sub rax, rdi                    ; rax -= upfront
    inc r9                          ; r9 = workers + 1
    cqo                             ; sign-extension rdx
    idiv r9                         ; rax = payment / workers
    add rax, rdx                    ; with remainder
    
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

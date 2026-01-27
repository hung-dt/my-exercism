; Everything that comes after a semicolon (;) is a comment

C2 equ 2
C3 equ 3
C4 equ 4
C5 equ 5
C6 equ 6
C7 equ 7
C8 equ 8
C9 equ 9
C10 equ 10
CJ equ 11
CQ equ 12
CK equ 13
CA equ 14

TRUE equ 1
FALSE equ 0

section .text

; You should implement functions in the .text section

; the global directive makes a function visible to the test files
global value_of_card
value_of_card:
    ; This function takes as parameter a number representing a card (rdi)
    ; The function should return the numerical value of the passed-in card (rax)
    cmp rdi, 11       ; if rdi < 11
    jl .number_cards
    cmp rdi, 14        ; else if rdi < 14
    jl .face_cards
    mov rax, 1         ; else CA
    jmp .end
.number_cards:
    mov rax, rdi
    jmp .end
.face_cards:
    mov rax, 10
.end:    
    ret

global higher_card
higher_card:
    ; This function takes as parameters two numbers (rdi, rsi) each representing a card
    ; The function should return which card has the higher value
    ; If both have the same value, both should be returned
    ; If one is higher (rax), the second one should be 0 (rdx)
    push rdi
    push rsi
    
    call value_of_card     ; value of first card in rax
    mov rdx, rax           ; store to rdx
    mov rdi, rsi
    call value_of_card     ; value of second card in rax

    pop rsi
    pop rdi

    cmp rax, rdx           ; if rax < rdx (second < first)
    mov rdx, 0
    jl .lower
    jg .higher
    mov rax, rdi            ; second == first
    mov rdx, rsi
    jmp .end

.lower:    ; second < first
    mov rax, rdi
    jmp .end
.higher:    ; second > first
    mov rax, rsi
.end:
    ret

global value_of_ace
value_of_ace:
    ; This function takes as parameters two numbers (rdi, rsi) each representing a card
    ; The function should return the value of an upcoming ace
    cmp rdi, CA    ; if first card is Ace
    je .ace_one
    cmp rsi, CA    ; if second card is Ace
    je .ace_one

    call value_of_card    ; value of first card in rax
    mov rdx, rax          ; store to rdx
    mov rdi, rsi
    call value_of_card    ; value of second card in rax
    add rax, rdx          ; sum = card1 + card2

    cmp rax, 10           ; if sum > 10
    jg .ace_one 
    mov rax, 11
    jmp .end
.ace_one:
    mov rax, 1
.end:
    ret

global is_blackjack
is_blackjack:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a blackjack, and FALSE otherwise
    cmp rdi, CA
    jne .first_not_CA    ; if rdi != CA then first_not_CA
                         ; rdi == CA
.check:
    cmp rsi, C10
    jl .not_bj           ; if rsi < C10 then not_bj
                         ; rsi >= C10
    cmp rsi, CK
    jg .not_bj           ; or rsi > CK then not_bj
                         ; rsi <= CK
    jmp .is_bj

.first_not_CA:
    cmp rsi, CA
    jne .not_bj          ; if second is not CA then not_bj
                         ; second is CA
    mov rax, rdi         ; swap first with second and recheck
    mov rdi, rsi
    mov rsi, rax
    jmp .check

.not_bj:
    mov rax, FALSE
    ret

.is_bj:
    mov rax, TRUE
    ret

global can_split_pairs
can_split_pairs:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards can be split into two pairs, and FALSE otherwise
    call value_of_card     ; value of first card in rax
    mov rdx, rax           ; store to rdx
    mov rdi, rsi
    call value_of_card     ; value of second card in rax
    cmp rax, rdx
    je .can_split
    mov rax, FALSE
    ret
.can_split:
    mov rax, TRUE
    ret

global can_double_down
can_double_down:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a hand that can be doubled down, and FALSE otherwise
    call value_of_card     ; value of first card in rax
    mov rdx, rax           ; store to rdx
    mov rdi, rsi
    call value_of_card     ; value of second card in rax
    add rax, rdx
    cmp rax, 9
    jl .cant
    cmp rax, 11
    jg .cant
    mov rax, TRUE
    ret
.cant:
    mov rax, FALSE
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

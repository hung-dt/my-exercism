# x86_64 Assembly Notes

The x86-64 track in Exercism uses NASM (Netwide Assembler) syntax

## Basics
- Comments are prefixed by a semicolon (;)
- An assembler-time contanst can be defined using `equ`:
```nasm
UNIVERSE equ 42
```
### General purpose registers:

16 64-bit GPRs, which can also be accessed as 32-bit, 16-bit or 8-bit

| 64-bit | 32-bit | 16-bit | 8-bit |
| ------ | ------ | ------ | ----- |
| rax    | eax    | ax     | ah/al |
| rbx    | ebx    | bx     | bh/bl |
| rcx    | ecx    | cx     | ch/cl |
| rdx    | edx    | dx     | dh/dl |
| rsi    | esi    | si     | sil   |
| rdi    | edi    | di     | dil   |
| rbp    | ebp    | bp     | bpl   |
| rsp    | esp    | sp     | spl   |
| rn (*) | rnd    | rnw    | rnb   |

(*) `n` in `rn` ranges from 8 to 15: `r8`, `r9`, `r10`, `r11`, `r12`, `r13`, `r14` and `r15`.

When using less than 64-bits, the bits accessed are usually from the lower portion of the register. The exception to this rule are `ah`, `bh`, `ch` and `dh`, which access the upper 8-bits from the 16-bits portion of the register.

Illustration of how the bits are accessed for the `rax` register:
```
+--------+---------------------------------------+
| 64-bit |                  rax                  |
+--------+-------------------+-------------------+
| 32-bit |                   |        eax        |
+--------+-------------------+---------+---------+
| 16-bit |                             |    ax   |
+--------+-----------------------------+----+----+
| 8-bit  |                             | ah | al |
+--------+-----------------------------+----+----+
```

### Instructions

Note that writing to a 32-bit register also clears the upper bits, so `mov eax, 42` is the same as `mov rax, 42`. This is not true for 16-bit and 8-bit registers.

## Functions

Instructions are organized in functions. All functions are placed in the section .text of the source file.

A function declaration consists of:

1. A label with the name of the function, followed by a `:`.
2. The instructions that define the function.
3. The return instruction, `ret`.

To call a function, we use the `call` instruction. A function can be called anywhere in the same source file. In order to make a function visible to other source files, the `global` directive must be used.

### Calling conventions

| Feature                 | System V (Linux/macOS)                 | Microsoft x64 (Windows)     |
| ----------------------- | -------------------------------------- | --------------------------- |
| Integer Args (in order) | `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` | `rcx`, `rdx`, `r8`, `r9`    |
| Floating Point Args     | `xmm0` - `xmm7`                        | `xmm0` - `xmm3`             |
| Return Value (Integer)  | `rax` (64-bit), `rdx:rax` (128-bit)    | `rax`                       |
| Return Value (Float)    | `xmm0`, `xmm1`                         | `xmm0`                      |
| Shadow Space            | None                                   | 32 bytes (caller-reserved)  |
| Stack Alignment         | 16-byte aligned before CALL            | 16-byte aligned before CALL |

**System V AMD64 ABI notes**

The caller uses registers to pass the first 6 arguments to the callee.  Given the arguments in left-to-right order, the order of registers used is: `rdi`, `rsi`, `rdx`, `rcx`, `r8`, and `r9`.  Any remaining arguments are passed on the stack in reverse order so that they can be popped off the stack in order.

The callee is responsible for perserving the value of registers `rbp`, `rbx`, and `r12-r15`, as these registers are owned by the caller.  The remaining registers are owned by the callee.

The callee places its return value in `rax` and is responsible for cleaning up its local variables as well as for removing the return address from the stack.

The `call`, `enter`, `leave` and `ret` instructions make it easy to follow this calling convention.

## Numbers

> In assembly, there's no way to tell if a sequence of bytes represents a signed or an unsigned number. It's the programmer's responsibility to give meaning to those bytes.
>
> The use of comments can be a great aid in this task.

### Immediate

An immediate is truncated to fit into the destination operand.

The `mov` instruction is the only one which accepts a 64-bit signed integer as source operand.

```nasm
add eax, -1          ; this is 4294967295 in unsigned representation
                     ; an attempt to use 4294967295 directly wouldn't work because immediates are usually 32-bit signed integers

mov eax, 4294967295  ; this works because mov can take a 64-bit immediate as source operand
```

### Arithmetic

`adc` - Add with carry (carray flag CF is set if the sum leaves an excessive bit that does not fit into the destination operand.)

| Instruction    | Description                                                           |
| -------------- | --------------------------------------------------------------------- |
| `add a, b`     | sets a to a + b                                                       |
| `adc a, b`     | sets a to a + b + CF (previous carry)                                 |
| `inc a`        | sets a to a + 1                                                       |
| `sub a, b`     | sets a to a - b                                                       |
| `dec a`        | sets a to a - 1                                                       |
| `imul a`       | sets rax to a * rax (signed)                                          |
| `imul a, b`    | sets a to a * b                                                       |
| `imul a, b, c` | sets a to b * c                                                       |
| `mul a`        | sets rax to a * rax (unsigned)                                        |
| `div a`        | sets rax to rax / a and rdx to rax % a (unsigned)                     |
| `idiv a`       | sets rax to rax / a and rdx to rax % a (signed)                       |
| `movzx a, b`   | copies b to a, adding 0 to exceeding bits                             |
| `movsx a, b`   | copies b to a, adding 1 to exceeding bits if num b < 0 or 0 otherwise |

**Division**

```nasm
div src    ; unsigned
idiv src   ; signed
```

In both cases, the value in `rdx:rax` is divided by the value in the `src` operand. The quotient is written to the `rax` register and the remainder is written to the `rdx` register.

Notice that as `rdx:rax` is the dividend, both registers must have the appropriate bits set.

So, whenever working with 64-bit integers, all bits in the `rdx` register must be cleared for a non-negative number in `rax`, and set for a negative number. This is called sign extension.

Failing to perform sign extension can cause a wrong result for the division or, if the quotient is too large to fit in `rax`, an error.

## Conditionals

There's a special register called `rflags`. Its bits act like flags for various conditions. Some of them are listed below:

| name     | symbol | bit |
|----------|--------|-----|
| carry    | CF     | 0   |
| zero     | ZF     | 6   |
| sign     | SF     | 7   |
| overflow | OF     | 11  |

These flags are not modified directly but are set by many different instructions.

One of the most common instruction used to test condition is `cmp`. It takes two operands and update the flags, but do not modify its operands.

### CMP instruction

```nasm
cmp A, B
```

The `cmp` instruction subtracts the second operand from the first and sets flags according to the result.

| flag | set when                       |
|------|--------------------------------|
| CF   | A < B (unsigned)               |
| ZF   | A == B                         |
| SF   | A < B (signed)                 |
| OF   | overflow in signed subtraction |

### Branching

#### Unconditional Jump

```nasm
jmp <label>
```

`jmp` instruction transfers execution of the program to another point of the code.

#### Conditional Jump

The family of instructions `jcc` transfers execution of the program to another point only if a specific condition is met. Otherwise, execution continues sequentially.

Each condition maps to one or more flags in `rflags`. The `cc` in `jcc` refers to the specific suffix associated with the flag tested.

Some of the suffixes refer directly to a flag:

| suffix | jumps if |
|--------|----------|
| z      | ZF == 1  |
| c      | CF == 1  |
| s      | SF == 1  |
| o      | OF == 1  |

Many others are chosen in order to refer to their meaning in a `cmp` instruction:

| instruction | suffix | jumps if         |
|-------------|--------|------------------|
| cmp A, B    | e      | A == B           |
| cmp A, B    | l      | A < B (signed)   |
| cmp A, B    | b      | A < B (unsigned) |
| cmp A, B    | g      | A > B (signed)   |
| cmp A, B    | a      | A > B (unsigned) |

Note that some suffixes are aliases to the same conditions: `jz` and `je` both jump when `ZF` is set.

It's possible to add `e` after `l`, `b`, `g` or `a` to include the equality in the condition:
```nasm
cmp rcx, r8
jge two      ; this jumps to 'two' if rcx is greater than, or equal to, r8 in a signed comparison
jbe two      ; this jumps to 'two' if rcx is lesser than, or equal to, r8 in an unsigned comparison
```

For all suffixes, there are variants which check the opposite behavior. They have the same syntax, but with a `n` before the suffix.

For instance, `jnz` jumps when `ZF` is not set. Similarly, `jnae` jumps when A is not >= B (A and B interpreted as unsigned integers).

### Local Labels

In order to mimic the behavior of a local label, NASM has a special notation for a label declared with a period (.) before it. This notation defines a label which implicitly includes the name of the previous non-dotted label:

```nasm
section .text
fn1:
    ...
.example: ; this is fn1.example
    ...
    ret

fn2:
    ...
.example: ; this is fn2.example
    ...
    ret
```

A jump that uses the part of the label starting at the dot will be made to the label inside the upper function. For example, .example behaves as if it was local to the function:

```nasm
section .text
fn1:
    ...
.example:
    ...
    jmp .example ; this jumps to fn1.example

fn2:
    ...
.example:
    ...
    jmp .example ; this jumps to fn2.example
```

Note that a non-dotted label inside a function in practice defines another function.

## Bit Manipulation

### Single bit manipulation

- Work on single bits in an operand.

| Name   | Description                                                                    |
|--------|--------------------------------------------------------------------------------|
| `bt`   | copies the bit into `CF` without modifying any operand                         |
| `bts`  | copies the bit into `CF` and sets it in the destination operand                |
| `btr`  | copies the bit into `CF` and clears it in the destination operand              |
| `btc`  | copies the bit into `CF` and complements (flips) it in the destination operand |

### Bitwise operations

- Are performed in all bits of an operand.
- Most take two operands, perform a bitwise operation on both and store the result in the destination operand.

| Name  | Description                        |
|-------|------------------------------------|
| `and` | 1 if both bits are 1               |
| `or`  | 1 if at least one of the bits is 1 |
| `xor` | 1 if the bits differ               |
| `not` | 1 if bit was 0; 0 if bit was 1     |

### TEST instruction

- The `test` instruction makes a bitwise AND between both operands and sets flags according to the result.

| flag   | set when             |
|--------|----------------------|
| `CF`   | always cleared       |
| `ZF`   | A AND B == 0         |
| `SF`   | A AND B < 0 (signed) |
| `OF`   | always cleared       |

### Shift operations

- Move the bits in the destination operand by a number of positions specified by the second operand.
- The second operand must be a constant number (an immediate) or the register `cl`

| Name      | Description              |
|-----------|--------------------------|
| `shl/sal` | Shifts bits to the left  |
| `shr/sar` | Shifts bits to the right |

Both `shl` and `sal` perform the exact same operation.

`shr` moves `0` bits to the left end, while `sar` moves `1` if the most significant was set and `0` otherwise. This means that `sar` preserves the sign in the shift of a signed integer.

Bits are moved to CF and then discarded. Since each bit in an integer represents a power of 2, a shift to the left by n positions has the effect of multiplying the integer by $2^n$, a shift to the right has the effect of making a division by $2^n$.

### Rotation operations

The difference between a rotation and a shift is that a rotation does not discard or add any bits. Bits that would be discarded by a shift are instead moved to the opposite end. So, all bits remain, they all change places.

| Name   | Description                                   |
|--------|-----------------------------------------------|
| `rol`  | Rotates bits to the left                      |
| `ror`  | Rotates bits to the right                     |
| `rcl`  | Rotates bits to the left, including the `CF`  |
| `rcr`  | Rotates bits to the right, including the `CF` |

### Other bit manipulation instructions

| Name     | Description                                                                            |
|----------|----------------------------------------------------------------------------------------|
| `popcnt` | Counts the number of bits set                                                          |
| `lzcnt`  | Counts the number of leading zeros (a bit cleared before the first set bit)            |
| `bsr`    | Gets the index of the most significant set bit. If no bit is set, result is undefined  |
| `bsf`    | Gets the index of the least significant set bit. If no bit is set, result is undefined |

These instructions all work with two 16-bit, 32-bit or 64-bit operands. They can not be used with 8-bit operands.

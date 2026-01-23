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

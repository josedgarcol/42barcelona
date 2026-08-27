*This project was created as part of the 42 curriculum by jcolque.*

---

# ft_printf

A partial reimplementation of the C standard library `printf` function, built from scratch using variadic arguments and custom format specifier handlers.

---

## Description

`ft_printf` replicates the core behavior of `printf(3)` from `<stdio.h>`, handling a curated set of format conversion specifiers. It is built on top of the `libft` library (also developed as part of the 42 curriculum) and compiles into a static archive (`libftprintf.a`) that can be linked into any C project.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String (null-safe: prints `(null)`) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%p` | Pointer address (e.g. `0x7ffd...`, null-safe: prints `(nil)`) |
| `%%` | Literal percent sign |

### Return value

Returns the total number of characters printed, or `-1` on a write error. Error propagation is handled consistently across all specifiers.

---

## Algorithm and data structure decisions

### Parsing strategy: character-by-character traversal

The format string is walked one character at a time in `ft_handle_char`. When a `%` is detected and a following character exists, the parser advances past the `%` and dispatches the conversion via `handle_conversion`. Otherwise, the character is written directly.

This approach was chosen over alternatives like `strchr` or splitting into tokens because:

- It maps cleanly to the Norminette function-length limit (25 lines).
- It handles edge cases such as a trailing `%` at end of string without lookahead complexity.
- Index-based traversal with a pointer-to-int (`int *i`) allows the sub-functions to advance the cursor cleanly without returning new positions.

### Dispatch: if-chain over a lookup table

`handle_conversion` uses a sequence of `if` comparisons to dispatch each specifier to its handler. A function pointer array indexed by character value would be more performant at scale, but the if-chain was chosen because:

- The number of specifiers is small and fixed (8 total).
- It is explicit and easy to audit — adding or removing a specifier is one line.
- It avoids the complexity of a sparse index table (ASCII value of `%p` is 112, requiring a 113-entry array mostly filled with NULLs).

### Number-to-string conversion

Integer and unsigned integer printing allocates a temporary string via `ft_itoa` (from libft) and `ft_utoa` (defined locally). Hexadecimal conversion uses a fixed-size stack-allocated buffer (`char buf[9]` for `unsigned int`, `char buf[17]` for `unsigned long`) filled right-to-left and written in one `write` call. This avoids heap allocation for the hot path of pointer and hex printing.

### Error handling

Every `write` call is checked for `-1`. If any write fails, the function immediately returns `-1` up the call stack through the return value, without using `errno` or `exit`. This allows the caller to detect and react to write failures, which is verified in the test suite (see `main.c`: `close(1)` followed by `ft_printf`).

---

## Instructions

### Requirements

- `cc` (GCC or Clang compatible)
- GNU Make
- A Unix-like system (Linux or macOS)

### Compilation

The project builds `libftprintf.a`, a static library containing both `ft_printf` and `libft`.

```bash
make
```

To recompile from scratch:

```bash
make re
```

To remove object files:

```bash
make clean
```

To remove objects and the library:

```bash
make fclean
```

### Linking into a project

Once built, link the library against your source files:

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program
```

Or include the header directly and compile together:

```bash
cc -Wall -Wextra -Werror your_file.c -I. libftprintf.a -o your_program
```

Include the header in your source:

```c
#include "ft_printf.h"
```

### Running the included tests

Two manual test files are provided:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test && ./test
cc -Wall -Wextra -Werror main2.c libftprintf.a -o test2 && ./test2
```

`main.c` covers all supported specifiers, edge cases (INT_MIN, UINT_MAX, null pointer, null string, closed stdout), and compares output against the system `printf`.  
`main2.c` tests unsupported specifier fallback behavior (`%z`).

---

## Resources

### Documentation and references

- [`printf(3)` — Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html) — canonical reference for format specifier behavior and return values.
- [`stdarg(3)` — Linux man page](https://man7.org/linux/man-pages/man3/stdarg.3.html) — documents `va_list`, `va_start`, `va_arg`, and `va_end`.
- [`write(2)` — Linux man page](https://man7.org/linux/man-pages/man2/write.2.html) — used directly for all output, bypassing buffered I/O.
- *C Programming Language*, Kernighan & Ritchie (2nd ed.) — chapters on variadic functions and I/O.
- [42 Francinette tester](https://github.com/xicodomingues/francinette) — automated test suite used to validate correctness and Norminette compliance.

### AI usage

Deepseek was used during this project in the following capacities:

- **Conceptual explanations**: understanding the internals of `va_list` (how `va_arg` advances a pointer through the stack frame), integer promotion rules in variadic calls (why `char` must be cast from `int` when using `va_arg`), and Makefile dependency mechanics.

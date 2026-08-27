*This project has been created as part of the 42 curriculum by jcolque.*

# get_next_line

## Description

`get_next_line` is a C project from the 42 school curriculum whose goal is to implement a function that reads and returns one line at a time from a file descriptor — including standard input. Each successive call to `get_next_line` picks up exactly where the previous one left off, making it possible to iterate through an entire file line by line without loading it all into memory at once.

The function has the following prototype:

```c
char *get_next_line(int fd);
```

It returns the next line (including the terminating `\n` if present), or `NULL` when the file has been fully read or an error occurs. The caller is responsible for freeing the returned string.

The project is split into two versions:

- **Mandatory** (`get_next_line.c` / `get_next_line_utils.c` / `get_next_line.h`): supports a single file descriptor at a time using one static pointer.
- **Bonus** (`get_next_line_bonus.c` / `get_next_line_utils_bonus.c` / `get_next_line_bonus.h`): supports multiple file descriptors simultaneously by using a static array of pointers indexed by `fd`.

---

## Algorithm — Design & Justification

### Core Idea: the Stash

The central challenge of `get_next_line` is that a single `read()` call may return data that spans more than one line, or less than one full line. A naive approach of reading exactly up to the next `\n` would require reading one byte at a time, which is extremely slow and defeats the purpose of `BUFFER_SIZE`.

The chosen algorithm solves this with a **persistent stash**: a `static` string that survives between calls and accumulates leftover data from previous reads.

### Step-by-step flow

Each call to `get_next_line` goes through three stages:

**1. `read_and_stash` — fill the stash until a newline is found**

```
while the stash does not contain '\n' AND the fd is not exhausted:
    read up to BUFFER_SIZE bytes into a temporary buffer
    concatenate the buffer onto the stash (ft_strjoin)
```

Reading stops as soon as a `\n` appears in the stash, so we never read more from the file than necessary. If `read()` returns 0 (EOF) the loop exits naturally and the remaining stash content (the last line without a trailing `\n`) is handled correctly.

**2. `extract_line` — carve out exactly one line**

The function scans the stash for the first `\n` (inclusive) and returns a freshly allocated substring covering characters `[0, i]`. This is the value returned to the caller.

**3. `update_stash` — keep the remainder for next time**

After extraction, everything after the `\n` is saved back into the stash via `ft_substr`. If nothing remains, the stash is freed and set to `NULL`, ready for the next file.

### Why this algorithm?

| Property | Explanation |
|---|---|
| **Efficiency** | Reads in chunks of `BUFFER_SIZE` instead of one byte at a time, minimising syscall overhead. |
| **Correctness at EOF** | Because the loop condition checks `bytes_read > 0`, the last line (no trailing `\n`) is still captured in the stash and returned normally. |
| **No global state pollution** | Using a `static` local variable (or a `static` array in the bonus) keeps state isolated inside the function. No heap-allocated global is needed. |
| **Multi-fd support (bonus)** | Indexing the stash array by `fd` (up to 4096, the typical OS limit) gives each file descriptor its own independent stash at zero extra cost per call. |
| **Clean memory management** | Every intermediate allocation is freed before leaving a function. On error paths, both `buffer` and `stash` are freed before returning `NULL`, preventing leaks. |

### Complexity

- Time: O(n) where n is the total number of characters read — each character is touched a constant number of times across `strjoin`, `substr`, and the scan loops.
- Space: O(L + B) per fd, where L is the length of the longest line and B is `BUFFER_SIZE`.

---

## Instructions

### Prerequisites

- A C compiler (`cc` / `gcc` / `clang`)
- GNU Make (optional, if a Makefile is added)
- A POSIX-compatible OS (Linux, macOS)

### Compilation

The project does not ship a Makefile by default; compile manually with `cc`. `BUFFER_SIZE` can be overridden at compile time with `-D BUFFER_SIZE=<n>`.

**Mandatory version (single fd):**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main_sec.c \
   -o gnl
```

**Bonus version (multiple fds):**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c main.c \
   -o gnl_bonus
```

### Running

**Single-file mode (mandatory):**

```bash
./gnl file1.txt          # reads file1.txt line by line
./gnl file1.txt file2.txt  # sequential: all of file1, then file2
```

**Multi-fd interleaved mode (bonus):**

```bash
./gnl_bonus file1.txt file2.txt file3.txt
```

The bonus `main.c` opens all files at once and reads one line from each fd in round-robin order, demonstrating that each fd preserves its own independent reading position.

**Reading from stdin:**

```bash
echo -e "hello\nworld" | ./gnl
```

### Integrating into your own project

Copy the relevant source files into your project and include the header:

```c
#include "get_next_line.h"   // or get_next_line_bonus.h

// Example
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## Resources

### Documentation & References

- [man 2 read](https://www.man7.org/linux/man-pages/man2/read.2.html) — POSIX `read()` system call specification
- [man 3 malloc / free](https://www.man7.org/linux/man-pages/man3/malloc.3.html) — dynamic memory management
- [Static variables in C — GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/) — explanation of `static` local variables and their lifetime
- [File descriptors — Wikipedia](https://en.wikipedia.org/wiki/File_descriptor) — overview of how the OS manages open files
- [42 Docs — get_next_line](https://harm-smits.github.io/42docs/projects/get_next_line) — community notes and common pitfalls

### AI Usage

DeepSeek was used in this project for the following tasks:


- **Code review**: DeepSeek was consulted to verify edge-case handling (e.g., EOF without trailing newline, `BUFFER_SIZE = 1`, error paths in `read_and_stash`) and to suggest clearer variable names during development.
- **Conceptual clarification**: explanations of `static` variable behaviour across multiple calls and across multiple translation units were discussed with the AI to deepen understanding before implementing the bonus version.

All code was written, understood, and validated by the student; AI was used exclusively as a learning and documentation aid.

*This project was created as part of the 42 curriculum by jcolque.*

# libft

## Description

**libft** is a custom C library built from scratch as part of the 42 curriculum. The goal is to deeply understand how standard C library functions work by reimplementing them, and to build a personal toolset that can be reused across future projects.

The library is organized in three parts:

- **Part 1** — Reimplementations of standard `libc` functions (character checks, memory operations, string manipulation).
- **Part 2** — Additional utility functions not present in `libc`, or present but with a different approach (string creation, output to file descriptors, etc.).
- **Part 3** — Functions to manipulate linked lists using the `t_list` structure.

---

## Instructions

### Requirements

- `cc` compiler
- `make`

### Compilation

Clone the repository and run:

```bash
make
```

This will compile all source files and generate `libft.a` in the root of the repository.

### Usage

To use the library in your own project, include the header and link the archive at compile time:

```bash
cc your_file.c -L. -lft -I. -o your_program
```

### Cleaning

```bash
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

---

## Library reference

### Part 1 — libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if `c` is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if `c` is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if `c` is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if `c` is in ASCII range, 0 otherwise |
| `ft_isprint` | Returns 1 if `c` is printable, 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out a block of memory |
| `ft_memcpy` | Copies memory from src to dest (no overlap) |
| `ft_memmove` | Copies memory safely handling overlaps |
| `ft_strlcpy` | Copies a string with size limit, returns src length |
| `ft_strlcat` | Appends a string with size limit, returns total length |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Returns pointer to first occurrence of `c` in string |
| `ft_strrchr` | Returns pointer to last occurrence of `c` in string |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_memchr` | Searches for a byte in memory |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within a length-limited string |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates zero-initialized memory |
| `ft_strdup` | Duplicates a string using `malloc` |

### Part 2 — Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims characters from both ends of a string |
| `ft_split` | Splits a string by a delimiter into a NULL-terminated array |
| `ft_itoa` | Converts an integer to its string representation |
| `ft_strmapi` | Applies a function to each character, returns new string |
| `ft_striteri` | Applies a function to each character in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Part 3 — Linked list functions

The `t_list` structure used throughout Part 3:

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Counts the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Frees a single node using a delete function |
| `ft_lstclear` | Frees all nodes of a list and sets pointer to NULL |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Resources

### Documentation

- [C standard library reference — cppreference.com](https://en.cppreference.com/w/c)
- [Linux man pages](https://man7.org/linux/man-pages/)
- [42 Norm — norminette rules](https://github.com/42School/norminette)

### AI usage

Deepseek (deepseek) was used during this project as a learning support tool, specifically to:

- Verify that the project structure matched the subject requirements.

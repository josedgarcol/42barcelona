*This project was created as part of the 42 curriculum by jcolque and cristrod.*

Index
=================

* [Overview](#overview)
   * [Operations](#operations)
   * [Flags](#flags)
   * [Disorder](#disorder)
* [Instructions](#instructions)
   * [Makefile](#makefile)
   * [Usage](#usage)
* [Description](#description)
   * [Algorithms](#algorithms)
      * [Simple Sort](#simple-sort)
      * [Medium Sort](#medium-sort)
      * [Complex Sort](#complex-sort)
* [Resources](#resources)
   * [References](#references)
   * [AI Usage](#ai-usage)
* [Authors](#authors)

# Overview

**push_swap** sorts a stack of integers using a limited set of operations (see [Operations](#operations)). \
The algorithm is selected automatically according to the stack's level of disorder (see [Disorder](#disorder)), although it can also be forced using a flag (see [Flags](#flags)).

## Operations

Operation | Description
--|--
`sa (swap a)` | Swaps the first two elements of stack `a`
`sb (swap b)` | Swaps the first two elements of stack `b`
`ss` | `sa` and `sb` at the same time
`pa (push a)` | Takes the first element from `b` and places it on top of `a`
`pb (push b)` | Takes the first element from `a` and places it on top of `b`
`ra (rotate a)` | The first element of stack `a` becomes the last
`rb (rotate b)` | The first element of stack `b` becomes the last
`rr` | `ra` and `rb` at the same time
`rra (reverse rotate a)` | The last element of stack `a` becomes the first
`rrb (reverse rotate b)` | The last element of stack `b` becomes the first
`rrr` | `rra` and `rrb` at the same time

## Flags

Flag | Description | Complexity
--|--|:--:
`--simple` | Forces the use of the simple sorting algorithm (selection sort adaptation) | $O(n^2)$
`--medium` | Forces the use of the medium sorting algorithm (chunk-based) | $O(n \sqrt{n})$
`--complex` | Forces the use of the complex sorting algorithm (LSD Radix Sort adaptation) | $O(n \log n)$

> If no flag is specified, the program automatically chooses the most suitable algorithm based on the stack's level of disorder.

## Disorder

Disorder is a value on the scale $[0, 1]$. The closer it is to 1, the less ordered the list of numbers is.

Disorder | Algorithm Used | Complexity
:--:|:--:|:--:
$[0.0, 0.2)$ | Simple Sort | $O(n^2)$
$[0.2, 0.5)$ | Medium Sort | $O(n \sqrt{n})$
$[0.5, 1.0]$ | Complex Sort | $O(n \log n)$

# Instructions

## Makefile

Command | Description
--|--
`make` | Compiles the `push_swap` binary
`make bonus` | Compiles the `checker` binary created by the students
`make clean` | Removes generated object files
`make fclean` | Removes generated object files and binaries
`make re` | Rebuilds `push_swap` from scratch (equivalent to `make fclean` followed by `make`)

## Usage

1. Compile it:
   ```bash
   make && make bonus
   ```

2. Sort a list of numbers:
   ```bash
   ./push_swap 12 9 86 10 4
   ```

   This will print the sequence of operations required to sort the stack.

3. Verify the result using the checker:
   ```bash
   ARG="12 9 86 10 4"
   ./push_swap $ARG | ./checker $ARG
   ```

   Expected output:
   ```bash
   OK
   ```
   # Description

The main goal of this project is to sort a stack of integers using the fewest possible moves, through operations such as swapping the first two numbers, rotating the stack in either direction, or moving a number to a second stack before reinserting it into the original one.

The purpose of the project is to develop the skills required to optimize code by minimizing the number of operations needed to sort a set of numbers. Through practice, it helps build an understanding of linked lists, stack implementation, memory allocation and deallocation, and the design of different sorting algorithms.

## Algorithms

Depending on the stack's level of disorder, a different algorithm is used (see [Disorder](#disorder)).

### Simple Sort

*Selection Sort adaptation · $O(n^2)$ · applied when the disorder is below 0.2.*

The algorithm searches for the minimum value in stack `a`, brings it to the top (using `rotate` or `reverse rotate`), and pushes it to stack `b` (`pb`). Once all elements have been moved to `b`, they are pushed back to `a` in sorted order (`pa`).

This Selection Sort adaptation is preferred over algorithms such as *Bubble Sort*, which compares elements one by one to decide each movement, because it requires fewer operations to achieve the same result.

### Medium Sort

*Chunk-based sorting (splitting into √n blocks) · $O(n \sqrt{n})$ · applied when the disorder is between 0.2 and 0.5.*

The input is divided into chunks of size √n (hence the √n division), which are moved to stack `b` before being reinserted into `a` in sorted order. By grouping elements into index ranges, the algorithm significantly reduces the number of operations compared to the $O(n^2)$ approach.

### Complex Sort

*LSD (Least Significant Digit) Radix Sort adaptation · $O(n \log n)$ · applied when the disorder is above 0.5.*

The numbers are processed in binary and sorted according to their least significant bit. If the current bit is `1`, the element is considered "greater" and is moved to stack `b`; if it is `0`, it remains in stack `a`. After processing all the required bits, every element is pushed back to `a`. Since the numbers are represented in binary, Radix Sort requires far fewer passes than the previous algorithms.

# Resources

Several sources were used throughout this project to continue improving both the learning process and the problem-solving skills required for programming.

## References

- Help from fellow 42 students. If you're at 42, always ask the person next to you for help: social interaction makes it easier to acquire knowledge, strengthens interpersonal skills, and reminds you that you're not the only one with those questions.
- The `libft` manual available in the terminal, which provides a complete description of every function that must be reimplemented (available in English, although translations and summaries can also be found on various websites).

## AI Usage

AI (DeepSeek, Claude, and ChatGPT) was used to:
- Review whether the code was correct.
- Explain concepts or lines of code that were not fully understood despite having been implemented.
- Write part of this README.

# Authors

| Login | Main Area |
|-------|-----------|
| **jcolque** | Project structure, data structure implementation, final review |
| **cristrod** | Program review, algorithm implementation, README author |

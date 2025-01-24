# push_swap

Welcome to the `push_swap` project! This repository contains a program designed to solve the stack-sorting problem using a specific set of operations. The goal is to sort data on a stack in the least number of moves possible.

## Repository

[GitHub Repository](https://github.com/mouadnajjar/push_swap)

---

## Table of Contents

- [Overview](#overview)
- [Rules](#rules)
- [Allowed Operations](#allowed-operations)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Evaluation](#evaluation)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

The `push_swap` project is a coding challenge part of the 42 Network curriculum. The goal is to sort a stack of integers in ascending order using a limited set of stack operations while achieving the lowest possible number of moves.

This project requires:
- Efficient algorithms.
- A strong understanding of data structures.
- Optimization skills to minimize the number of operations.

---

## Rules

- The program receives a list of integers as arguments.
- It sorts these integers using two stacks (`stack_a` and `stack_b`).
- The output must be a sequence of valid operations that sorts the integers in ascending order.

---

## Allowed Operations

### Stack Operations

1. **Swap (sa, sb, ss)**
   - `sa`: Swap the first two elements of `stack_a`.
   - `sb`: Swap the first two elements of `stack_b`.
   - `ss`: Perform `sa` and `sb` simultaneously.

2. **Push (pa, pb)**
   - `pa`: Push the top element of `stack_b` to `stack_a`.
   - `pb`: Push the top element of `stack_a` to `stack_b`.

3. **Rotate (ra, rb, rr)**
   - `ra`: Rotate `stack_a` (the first element becomes the last).
   - `rb`: Rotate `stack_b`.
   - `rr`: Perform `ra` and `rb` simultaneously.

4. **Reverse Rotate (rra, rrb, rrr)**
   - `rra`: Reverse rotate `stack_a` (the last element becomes the first).
   - `rrb`: Reverse rotate `stack_b`.
   - `rrr`: Perform `rra` and `rrb` simultaneously.

---

## Algorithm

The program employs an efficient algorithm to sort the stack. It includes the following steps:

1. Parse and validate input arguments.
2. Determine the optimal sorting strategy:
   - Small stack (3 or fewer elements): Use a minimal hardcoded solution.
   - Medium stack (5-100 elements): Use chunking or a simplified sorting algorithm.
   - Large stack (>100 elements): Use advanced techniques like radix sort or quicksort-inspired chunking.
3. Execute and output the sequence of operations.

---

## Installation

Clone the repository:

```bash
$ git clone https://github.com/mouadnajjar/push_swap.git
$ cd push_swap
```

Compile the program:

```bash
$ make
```

---

## Usage

Run the program with a list of integers:

```bash
$ ./push_swap [integers]
```

### Example:

```bash
$ ./push_swap 4 2 3 1
```

Output:

```
pb
ra
sa
pa
```

This output represents the sequence of operations to sort the stack.

---

## Evaluation

The performance of your solution is evaluated based on the number of operations:

- Fewer operations = better score.
- Achieving the minimum number of operations for various test cases is key to passing the project.

---

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes.
4. Open a pull request.

---

## Contact

For any inquiries, please feel free to contact the repository owner via [GitHub Issues](https://github.com/mouadnajjar/push_swap/issues).

Happy coding!

# Array Statistics in C

A CLI utility written in C that dynamically allocates an integer array, reads user-defined values, and computes basic descriptive statistics: minimum, maximum, and arithmetic mean.

## Features

- **Dynamic Memory Allocation:** Allocates memory on the heap using `malloc` based on user-defined length.
- **Statistical Analysis:** Computes minimum, maximum, and average in a single pass ($O(n)$ complexity).
- **Multiple Output Parameters:** Passes computed statistics back to the caller using pointer arguments (`int *min`, `int *max`, `double *prumer`).
- **Input Validation & Safety:** Validates array lengths, verifies `scanf` return codes, and prevents memory leaks by freeing dynamically allocated memory across all execution branches.

## How to Build and Run

### 1. Compilation
Compile with standard strict GCC flags:
```bash
gcc -Wall -pedantic -g StatistikaPoleCisel.c -o array_stats
```

### 2. Execution
```bash
./array_stats
```

### 3. Memory Leak Check (Valgrind)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./array_stats
```

## Example Usage

```text
Zadejte pocet prvku:
5
Zadejte prvky:
12 5 -3 42 10
Min: -3, Max: 42, Prumer: 13.20
```

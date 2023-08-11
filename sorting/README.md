# Sam Gaines - Sorting Algorithms

## Project Description

This project offers a runtime comparison of the following integer sorting algorithms:
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Merge Sort

Additionally, this project provides a way for the user to generate random lists of a desired size and range.

C++ was used for every function of the project.

## Overview

### C++ Scripts

The main interface for sorting can be found in `sorting.cpp`.

`bubble-sort.cpp`, `insertion-sort.cpp`, `selection-sort.cpp`, and `merge-sort.cpp` provide the functionality for each sorting algorithm. Some of these algorithms make calls to `swap.cpp`, which provides the functionality for swapping two elements in a list.

`random-list.cpp` is the script for generating a random list, that can then be sorted by any algorithm.

## Usage

### Input File Format

An input file will contain a list to be sorted. It should contain the following lines:
 - One line containing two integers $n$ and $r$, with $n$ being the number of elements in the list and $r$ being the highest possible integer in the list.
 - One line containing $n$ integers, where $0 \leq x_i \leq r$ for all $x_i$ in the list.

### Compiling

All C++ scripts can be compliled by running the `make` command in the terminal. Executables can be removed by running the `make clean` command in the terminal.

### Using the Main Sorting Interface

Typing `./sorting.exe filename` in the terminal opens the interface for the sorting algorithms on an input file. The terminal will prompt the user for which algorithm to run. After running, the terminal will show the sorted list and the amount of time elapsed in the sorting process.

### Generating a Random List

Typing `./random-list.exe filename` in the terminal opens the interface for generating a random list and writing it to a file. The terminal will prompt the user for the number of elements $n$ and the maximum element $r$.
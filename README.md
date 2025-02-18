# libasm

## Overview
The goal of this project is to recreate some of the libC functions in assembly . The lib is written in `x86-64` assembly and compiled with `NASM`, following the intel syntax.


## Implementation

This project implements the following standard C functions in assembly:
- `ft_strlen` – Computes the length of a string.
- `ft_strcpy` – Copies a string from source to destination.
- `ft_strcmp` – Compares two strings.
- `ft_write` – Writes data to a file descriptor.
- `ft_read` – Reads data from a file descriptor.
- `ft_strdup` – Duplicates a string.

## Objectives

This project aims to learns :
- The assembly intel syntax
- How register work
- How the stack works


## Requirements

To build and run this project, you need:
- A Unix-based operating system like Linux or macOS (if you use MacOs you will have to change NASM FLAGS)
- NASM (Netwide Assembler) installed
- GCC compiler


## Usage

Compile the lib with make:
``` SHELL
make
```
To compile tests you should use:
``` SHELL
make test
```

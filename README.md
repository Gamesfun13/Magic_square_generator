
# Magic Square Generator
C practice project

A standalone C program that generates magic squares using the Siamese method.

## Description

This program implements the `magic_square()` function to construct odd-order magic squares. A magic square is a square matrix where the sums of each row, column, and both diagonals are equal (known as the magic constant).

## Compilation

```bash
gcc magic_square.c -o magic_square
```

## Usage

```bash
./magic_square
```

The program will prompt you to enter the order of the magic square (must be an odd positive integer).

## Example

```
=== Magic Square Generator (Siamese Method) ===
Enter the order of the magic square (odd positive integer): 3

Magic Square of order 3:
-------------------------
   8    1    6 
   3    5    7 
   4    9    2 
-------------------------

Expected Magic Constant: 15

Row sums: 15 15 15
Column sums: 15 15 15
Main diagonal sum: 15
Anti-diagonal sum: 15

Magic square generated successfully!
```

## Algorithm

The program uses the **Siamese method** (also known as the De la Loubère method) for constructing magic squares of odd order:
1. Start in the middle of the first row
2. Move diagonally up and right
3. If the position is occupied, move down one row instead
4. Wrap around edges of the square

## Limitations

- Only works for odd-order magic squares (1, 3, 5, 7, ...)
- Even-order magic squares are not supported by this implementation

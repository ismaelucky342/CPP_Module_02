# CPP_Module_02

## Overview

This project is part of the C++ Module 02 at 42. Its main purpose is to reinforce object-oriented programming principles, focusing on canonical form and operator overloading in C++. A key element of the module is implementing a custom `Fixed` class that uses fixed-point arithmetic to handle fractional values using integer math.

---

## Features

- Canonical form:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor

- Fixed-point arithmetic with 8 fractional bits:
  - Internal representation using a single integer (`_value`)
  - Conversion between `int` and `float`

- Operator overloading:
  - Arithmetic: `+`, `-`, `*`, `/`
  - Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Increment and decrement: `++`, `--` (both prefix and postfix)

- Static member functions:
  - `Fixed::min()` (overloaded for const and non-const references)
  - `Fixed::max()` (overloaded for const and non-const references)

- Stream output overload:
  - Overloaded `<<` operator to print `Fixed` objects as floats

---

## Build Instructions

```bash
make
./fixed
```

### File Structure
- Fixed.hpp: Class definition and method declarations

- Fixed.cpp: Method implementations

- main.cpp: Test cases to demonstrate class behavior

## Extras 

This module demonstrates how fundamental OOP concepts are applied in C++ through the implementation of a class that respects the canonical form and supports advanced features like operator overloading. By simulating decimal behavior with fixed-point arithmetic, the project also introduces efficient alternatives to floating-point operations.

-Born2code


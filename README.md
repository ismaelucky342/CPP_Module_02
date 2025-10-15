<img width="917" height="218" alt="imagen" src="https://github.com/user-attachments/assets/69920d8b-9531-4f03-a01f-e4c736bb86b1" />

# CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading & Orthodox Canonical Class Form

## Overview

This module reinforces object-oriented programming principles in C++98, focusing on **ad-hoc polymorphism** through operator overloading and the **Orthodox Canonical Class Form**. The primary focus is implementing a `Fixed` class that uses **fixed-point arithmetic** to handle fractional values using integer mathematics, providing precise decimal calculations without floating-point precision issues.

## Learning Objectives

- Understanding and implementing the **Orthodox Canonical Class Form**
- Mastering **operator overloading** for custom classes
- Working with **fixed-point arithmetic** and bit manipulation
- Implementing **const-correctness** throughout class design
- Creating **static member functions** for utility operations
- Understanding **ad-hoc polymorphism** through function overloading

## Key Concepts

### Orthodox Canonical Class Form
The "Big Four" that every well-designed C++ class should implement:
1. **Default Constructor**: Creates object with default values
2. **Copy Constructor**: Creates object as copy of another object
3. **Copy Assignment Operator**: Assigns one object to another existing object
4. **Destructor**: Cleans up resources when object is destroyed

### Fixed-Point Arithmetic
Fixed-point numbers represent fractional values using integers:
- **Advantages**: Deterministic, no rounding errors, faster than floating-point
- **Implementation**: Use bit shifting for multiplication/division by powers of 2
- **Our Format**: 24 integer bits + 8 fractional bits = 32-bit total

### Operator Overloading Categories
- **Arithmetic**: `+`, `-`, `*`, `/`
- **Comparison**: `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Increment/Decrement**: `++`, `--` (prefix and postfix)
- **Stream**: `<<` for output formatting

## Project Structure

```
CPP_Module_02/
├── ex00/          # Orthodox Canonical Class Form Implementation
├── ex01/          # Towards a More Useful Fixed-Point Number Class
├── ex02/          # Now We're Talking
├── ex03/          # BSP (Binary Space Partitioning)
└── README.md      # This file
```

## Exercises

### ex00: My First Class in Orthodox Canonical Form
**Objective:** Implement the foundational Fixed class with proper canonical form.

**Description:**
Create a `Fixed` class that represents fixed-point numbers with 8 fractional bits. This exercise focuses on proper class construction, destruction, and copying.

**Class Requirements:**
- **Private Members:**
  - `int _fixedPointValue` - stores the fixed-point value
  - `static const int _fractionalBits = 8` - number of fractional bits

- **Public Members:**
  - Default constructor (initializes to 0)
  - Copy constructor
  - Copy assignment operator
  - Destructor
  - `int getRawBits(void) const` - returns raw fixed-point value
  - `void setRawBits(int const raw)` - sets raw fixed-point value

**Key Learning Points:**
- Proper implementation of canonical form
- Constructor and destructor messaging for debugging
- Understanding shallow vs deep copy (though not needed here)
- Const-correctness in member functions

**Expected Debug Output:**
```
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Destructor called
```

---

### ex01: Towards a More Useful Fixed-Point Number Class
**Objective:** Add conversion capabilities and floating-point operations.

**Description:**
Extend the Fixed class with constructors for int and float, conversion methods, and stream output operator.

**New Features:**
- **Constructors:**
  - `Fixed(const int value)` - converts int to fixed-point
  - `Fixed(const float value)` - converts float to fixed-point

- **Conversion Methods:**
  - `float toFloat(void) const` - converts to float
  - `int toInt(void) const` - converts to int

- **Stream Operator:**
  - `operator<<` overload for std::ostream

**Implementation Details:**
```cpp
// Converting int to fixed-point: multiply by (1 << fractionalBits)
Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {}

// Converting float to fixed-point: multiply by (1 << fractionalBits) and round
Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits))) {}

// Converting back to float: divide by (1 << fractionalBits)
float toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}
```

**Key Learning Points:**
- Type conversion in C++
- Bit shifting for efficient multiplication/division
- Proper rounding for float conversions
- Stream operator overloading
- Static casting and type safety

---

### ex02: Now We're Talking
**Objective:** Implement complete operator overloading suite for mathematical operations.

**Description:**
Add comprehensive operator support to make Fixed numbers fully functional for arithmetic and comparison operations.

**Operators to Implement:**

**Comparison Operators:**
- `>`, `<`, `>=`, `<=`, `==`, `!=`

**Arithmetic Operators:**
- `+`, `-`, `*`, `/`

**Increment/Decrement Operators:**
- `++fixed` (pre-increment)
- `fixed++` (post-increment)
- `--fixed` (pre-decrement)
- `fixed--` (post-decrement)

**Static Member Functions:**
- `static Fixed& min(Fixed& a, Fixed& b)` - returns reference to smaller value
- `static const Fixed& min(const Fixed& a, const Fixed& b)` - const version
- `static Fixed& max(Fixed& a, Fixed& b)` - returns reference to larger value
- `static const Fixed& max(const Fixed& a, const Fixed& b)` - const version

**Implementation Considerations:**
```cpp
// Arithmetic operators work on raw values directly
Fixed operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

// Multiplication requires shifting to maintain precision
Fixed operator*(const Fixed& other) const {
    Fixed result;
    long long temp = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(temp >> _fractionalBits));
    return result;
}

// Post-increment returns old value, pre-increment returns new value
Fixed operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}
```

**Key Learning Points:**
- Operator overloading syntax and conventions
- Difference between pre and post increment/decrement
- Function overloading for const and non-const versions
- Efficient arithmetic on fixed-point numbers
- Static member function implementation

---

### ex03: BSP (Binary Space Partitioning)
**Objective:** Apply Fixed-point arithmetic to solve geometric problems.

**Description:**
Implement a function that determines if a point lies inside a triangle using Binary Space Partitioning and fixed-point arithmetic.

**Requirements:**
- **Point Class**: Simple class to represent 2D coordinates using Fixed numbers
- **BSP Function**: `bool bsp(Point const a, Point const b, Point const c, Point const point)`
- Use only Fixed-point arithmetic (no floating-point calculations)

**Mathematical Background:**
Use the cross product method to determine if a point is inside a triangle:
1. Calculate the cross product for each edge of the triangle
2. Check if the point is on the same side of all three edges
3. Handle edge cases (point on triangle boundary)

**Implementation Strategy:**
```cpp
class Point {
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
```

**Key Learning Points:**
- Practical application of fixed-point arithmetic
- Geometric algorithms and computational geometry
- Const member variables and their implications
- Cross product calculations using Fixed numbers
- Edge case handling in geometric calculations

---

## Build Instructions

Each exercise can be compiled individually:

```bash
cd ex00
make
./fixed

cd ../ex01
make  
./fixed

cd ../ex02
make
./fixed

cd ../ex03
make
./bsp
```

## Advanced Concepts Covered

### Const-Correctness
- **Const member functions**: Don't modify object state
- **Const references**: Prevent unnecessary copying
- **Const return types**: Prevent modification of temporary objects

### Operator Overloading Best Practices
1. **Return types**: 
   - Arithmetic operators return by value
   - Assignment operators return by reference
   - Comparison operators return bool

2. **Parameter types**:
   - Use const references for complex types
   - Use value parameters for simple types

3. **Symmetry**: Ensure operations work in both directions where appropriate

### Fixed-Point Arithmetic Advantages
- **Deterministic**: Same input always produces same output
- **No precision loss**: Unlike floating-point arithmetic
- **Fast**: Integer operations are faster than floating-point
- **Embedded-friendly**: Useful in systems without FPU

## Common Implementation Pitfalls

1. **Overflow in multiplication**: Use larger intermediate type (long long)
2. **Precision loss in division**: Shift dividend before dividing
3. **Incorrect post-increment**: Must return old value, not new
4. **Missing const versions**: Provide both const and non-const variants
5. **Assignment operator**: Remember to return *this


## Extras 

This module demonstrates how fundamental OOP concepts are applied in C++ through the implementation of a class that respects the canonical form and supports advanced features like operator overloading. By simulating decimal behavior with fixed-point arithmetic, the project also introduces efficient alternatives to floating-point operations.

-Born2code

![42madrid](https://github.com/ismaelucky342/Born2code/assets/153450550/3a377f34-9156-4eff-b04b-71c4b128523e)

# CPP Module 02

This repository contains my implementation of **C++ Module 02**, developed as part of the 42 School curriculum. This module focuses on ad-hoc polymorphism, operator overloading, and the Orthodox Canonical class form, introducing fundamental concepts of fixed-point arithmetic and operator overloading in C++.

**"Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form"**

## Table of Contents

- [Overview](#overview)
- [General Rules](#general-rules)
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [Exercises](#exercises)
  - [Exercise 00: My First Class in Orthodox Canonical Form](#exercise-00-my-first-class-in-orthodox-canonical-form)
  - [Exercise 01: Towards a more useful fixed-point number class](#exercise-01-towards-a-more-useful-fixed-point-number-class)
  - [Exercise 02: Now we're talking](#exercise-02-now-were-talking)
  - [Exercise 03: BSP](#exercise-03-bsp)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Submission and Peer Evaluation](#submission-and-peer-evaluation)
- [Acknowledgments](#acknowledgments)
- [Disclaimer](#disclaimer)
- [License](#license)

## Overview

C++ is a general-purpose programming language created by **Bjarne Stroustrup** as an extension of the C programming language, or "C with Classes". This module introduces advanced OOP concepts, specifically focusing on fixed-point arithmetic and operator overloading.

Key topics covered in this module:
- **Fixed-point numbers** - an alternative to integers and floating-point numbers
- **Orthodox Canonical Form** - the standard way to design C++ classes
- **Operator overloading** - redefining operators for custom classes
- **Ad-hoc polymorphism** - different implementations based on argument types
- **Static member functions** - class-level utility functions

All exercises must be written in **C++98** and compiled using the appropriate flags.

## General Rules

- **Compilation:**
  - Compile with `c++ -Wall -Wextra -Werror`
  - Code must still compile with `-std=c++98`

- **Formatting & Naming:**
  - Exercises are stored in directories `ex00`, `ex01`, `ex02`, …  
  - Class names in `UpperCamelCase` (e.g., `Fixed`, `Point`)  
  - Source files: `ClassName.cpp`  
  - Header files: `ClassName.hpp` or `ClassName.h`  

- **Allowed / Forbidden:**
  - Allowed: most of the C++ standard library, `roundf` from `<cmath>`
  - Forbidden: external libraries, C++11 or newer, Boost libraries
  - Forbidden functions: `*printf()`, `*alloc()`, `free()`
  - Forbidden keywords: `using namespace <ns_name>`, `friend` (unless explicitly stated)
  - STL containers and algorithms are only allowed starting from Module 08

- **Design Requirements:**
  - All classes must follow the Orthodox Canonical Form (from Module 02 onwards)
  - Avoid memory leaks when using `new` / `delete`
  - Each header must be self-contained and protected by include guards
  - No function implementations inside headers (except templates)

## Orthodox Canonical Form

From this module onwards, all classes must implement the four required member functions:

1. **Default constructor** - initializes the object with default values
2. **Copy constructor** - creates a copy of an existing object
3. **Copy assignment operator** - assigns the value of one object to another
4. **Destructor** - cleans up resources when the object is destroyed

Split your class code into two files:
- Header file (`.hpp`/`.h`) - contains the class definition
- Source file (`.cpp`) - contains the implementation

## Exercises

### Exercise 00: My First Class in Orthodox Canonical Form

**Directory:** `ex00/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`

Create a `Fixed` class in Orthodox Canonical Form that represents a fixed-point number.

**Private members:**
- An integer to store the fixed-point number value
- A static constant integer to store the number of fractional bits (value: 8)

**Public members:**
- Default constructor (initializes to 0)
- Copy constructor
- Copy assignment operator
- Destructor
- `int getRawBits(void) const` - returns the raw value
- `void setRawBits(int const raw)` - sets the raw value

**Key Learning:** Understanding the Orthodox Canonical Form and fixed-point number representation.

### Exercise 01: Towards a more useful fixed-point number class

**Directory:** `ex01/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`  
**Allowed functions:** `roundf` (from `<cmath>`)

Extend the `Fixed` class with conversion capabilities.

**Add the following constructors:**
- Constructor taking a constant integer (converts to fixed-point)
- Constructor taking a constant float (converts to fixed-point)

**Add the following member functions:**
- `float toFloat(void) const` - converts fixed-point to float
- `int toInt(void) const` - converts fixed-point to integer

**Add operator overload:**
- Overload the insertion operator (`<<`) to output the floating-point representation

**Expected output example:**
```
a is 1234.43
b is 10
c is 42.4219
d is 10
```

**Key Learning:** Type conversion and operator overloading for output streams.

### Exercise 02: Now we're talking

**Directory:** `ex02/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`  
**Allowed functions:** `roundf` (from `<cmath>`)

Add comprehensive operator overloading to the `Fixed` class.

**Comparison operators:** `>`, `<`, `>=`, `<=`, `==`, `!=`

**Arithmetic operators:** `+`, `-`, `*`, `/`

**Increment/decrement operators:**
- Pre-increment (`++a`) and post-increment (`a++`)
- Pre-decrement (`--a`) and post-decrement (`a--`)
- Increment/decrement by the smallest representable ε such that 1 + ε > 1

**Static member functions:**
- `static Fixed& min(Fixed& a, Fixed& b)` - returns reference to the smallest
- `static const Fixed& min(const Fixed& a, const Fixed& b)` - const version
- `static Fixed& max(Fixed& a, Fixed& b)` - returns reference to the greatest
- `static const Fixed& max(const Fixed& a, const Fixed& b)` - const version

**Expected output example:**
```
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

**Key Learning:** Comprehensive operator overloading and static member functions.

*Note: Division by 0 may crash the program (acceptable behavior).*

### Exercise 03: BSP

**Directory:** `ex03/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`, `Point.{h,hpp}`, `Point.cpp`, `bsp.cpp`  
**Allowed functions:** `roundf` (from `<cmath>`)

Implement Binary Space Partitioning (BSP) to determine if a point is inside a triangle.

**Create a `Point` class in Orthodox Canonical Form:**

**Private members:**
- `Fixed const` attribute `x`
- `Fixed const` attribute `y`

**Public members:**
- Default constructor (initializes x and y to 0)
- Constructor taking two constant floats
- Copy constructor
- Copy assignment operator
- Destructor

**Implement the BSP function:**
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

**Parameters:**
- `a`, `b`, `c` - the vertices of the triangle
- `point` - the point to check

**Returns:** `true` if the point is inside the triangle, `false` otherwise (including vertices and edges)

**Key Learning:** Practical application of the Fixed class and geometric algorithms.

*Note: This exercise is optional and not required to pass the module.*

## Project Structure

```
CPP02/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
├── ex03/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   ├── Point.hpp
│   ├── Point.cpp
│   └── bsp.cpp
└── README.md
```

## Installation

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/yourusername/CPP02.git
   cd CPP02
   ```

2. **Build the Desired Exercise:**

   ```sh
   cd ex00 && make
   ```

## Usage

Each exercise produces its own executable. Navigate to the exercise directory and run:

**Exercise 00:**
```sh
./fixed
```

**Exercise 01:**
```sh
./fixed
```

**Exercise 02:**
```sh
./fixed
```

**Exercise 03:**
```sh
./bsp
```

## Submission and Peer Evaluation

- Submit your project through the designated Git repository.
- Only the files within your Git repository will be evaluated during defense.
- Double-check that all file names and structures match the subject requirements.
- Ensure your Makefile compiles without relinking and includes all required rules.
- Verify that all classes follow the Orthodox Canonical Form.

## Acknowledgments

- Thanks to the 42 community, mentors, and fellow students for their guidance and support.
- Special thanks to resources on fixed-point arithmetic and operator overloading:
  - Berkeley University articles on fixed-point numbers
  - C++ documentation on operator overloading

## Disclaimer

**IMPORTANT**:
This project was developed solely as part of the educational curriculum at 42 School. The code in this repository is published only for demonstration purposes to showcase my programming and C++ development skills.

**Academic Integrity Notice**:
It is strictly prohibited to copy or present this code as your own work in any academic submissions at 42 School. Any misuse or uncredited use of this project will be considered a violation of 42 School's academic policies.

## License

This repository is licensed under the Creative Commons - NonCommercial-NoDerivatives (CC BY-NC-ND 4.0) license. You are free to share this repository as long as you:

- Provide appropriate credit.
- Do not use it for commercial purposes.
- Do not modify, transform, or build upon the material.

For further details, please refer to the CC BY-NC-ND 4.0 license documentation.

Developed with dedication and in strict adherence to the high standards of 42 School.

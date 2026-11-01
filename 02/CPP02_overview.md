# C++ Module 02 — Overview

**Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form**

This module develops a fixed-point number class and then uses it to represent points and test whether a point lies strictly inside a triangle. The exercises build on one another and target C++98.

## Exercises at a glance

| Exercise | Name | Main focus |
|---|---|---|
| ex00 | My First Class in Orthodox Canonical Form | Object construction, copying, assignment, and destruction |
| ex01 | Towards a more useful fixed-point number class | Numeric conversion and stream insertion |
| ex02 | Now we're talking | Arithmetic, comparisons, increment/decrement, and overloaded min/max |
| ex03 | BSP | Immutable points and geometric orientation tests |

## Core idea: fixed-point representation

The class stores an integer raw value and uses eight fractional bits. Its scale is therefore 2^8 = 256.

- Real value = raw value / 256.
- Encoding an integer multiplies it by 256.
- Encoding a floating-point value scales it and rounds to a representable raw integer.
- One raw unit represents 1/256, or 0.00390625, in real value.

For example, raw value 640 represents 2.5. No decimal point is physically stored in the integer; the class consistently interprets the integer using its fixed scale. Not every decimal fraction is exactly representable.

## ex00 — Orthodox Canonical Form

Create Fixed with a private integer raw value and a shared static constant specifying eight fractional bits. Provide getRawBits() and setRawBits() to access the stored representation.

The four required special members are:

| Member | Purpose |
|---|---|
| Default constructor | Create a new object with raw value zero |
| Copy constructor | Initialize a new object from an existing object |
| Copy assignment operator | Copy into an object that already exists |
| Destructor | Handle the end of the object's lifetime |

A copy constructor and copy assignment are different operations. A declaration such as `Fixed b(a)` constructs a new object; `b = a` assigns to an existing one.

Fixed stores an ordinary integer, so copying its value is sufficient. It does not need dynamic allocation or deep-copy machinery. Diagnostic messages help reveal the order of calls.

**Learning goal:** Understand object lifetime and copy behavior rather than simply memorizing the four declarations.

## ex01 — Conversions and output

Extend Fixed with constructors accepting int and float, plus toInt() and toFloat().

- Constructors encode the supplied number into the raw representation.
- toFloat() decodes the stored number using floating-point division.
- toInt() returns an integer representation, discarding the fractional part in the division-based implementation used here.
- These conversion methods read the object without changing it and are const-qualified.

Overload the stream insertion operator so `std::cout << object` displays its floating-point representation. The non-member overload takes an output-stream reference and a const Fixed reference, and returns the same stream by reference so output operations can be chained.

**Learning goal:** Distinguish a value from its stored representation and understand how operator overloading integrates a class with streams.

## ex02 — Operators and min/max

Extend the class to behave like a numeric type.

### Comparisons

Implement >, <, >=, <=, ==, and !=. Since both operands use the same scale, their raw values can be compared directly. These operators return bool and should not modify either operand.

### Arithmetic

Arithmetic operators return a new Fixed object while preserving their operands. With raw operands A and B and scale S = 256:

| Operation | Raw result before any rounding |
|---|---|
| Addition | A + B |
| Subtraction | A - B |
| Multiplication | (A × B) / S |
| Division | (A × S) / B |

Store a calculated raw result as raw data. Passing it to the integer constructor would scale it a second time.

Choose intermediate types before performing arithmetic: converting an already-overflowed int result afterward does not repair it. Our implementation also adds overflow exceptions and a division-by-zero exception; these are design choices beyond the basic operator requirements. The subject explicitly permits a crash on division by zero.

### Increment and decrement

Each operation changes the raw value by one, meaning the real value changes by 1/256.

| Operator | Effect | Conventional return type |
|---|---|---|
| ++a | Increment and expose the updated object | Fixed& |
| a++ | Increment but return the previous value | Fixed |
| --a | Decrement and expose the updated object | Fixed& |
| a-- | Decrement but return the previous value | Fixed |

The unused int parameter in a postfix overload distinguishes it from the prefix overload. It does not specify the step size. A postfix implementation preserves the previous state with a copy before modifying the original.

### min and max

Provide two static overloads each for min and max:

- Mutable references in, mutable reference out.
- Const references in, const reference out.

Return a reference to one of the supplied objects rather than constructing a new result. Static functions need no current object and can be called through the class name.

**Learning goal:** Understand ad-hoc polymorphism, const-correctness, and when an operation should return a value versus a reference.

## ex03 — BSP

Create a Point class containing two const Fixed coordinates, x and y. Constructors initialize them through initialization lists. The copy constructor initializes coordinates from the source point.

Because the coordinates are const, ordinary copy assignment cannot overwrite them. Our chosen assignment implementation leaves the destination unchanged; this behavior should be documented and understood. Modifying truly const members through const_cast is not a valid workaround.

Implement the standalone function:

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

The first three points are triangle vertices. The fourth is the point being tested. A point on an edge or vertex must return false. Exercise 03 is optional for passing the module according to the subject.

### Geometry used

For an oriented edge A → B and test point P, build vectors AB = B − A and AP = P − A. Their two-dimensional cross value is:

```text
cross(AB, AP) = AB.x × AP.y − AB.y × AP.x
```

In standard Cartesian coordinates:

- Positive means P is to the left of the directed edge.
- Negative means P is to the right.
- Zero means P lies on the edge's infinite supporting line.

The magnitude is twice the area of triangle ABP. For the containment test, the sign is the useful part.

Check the oriented edges A → B, B → C, and C → A. A point is strictly inside when all three cross values are positive or all three are negative. Mixed signs indicate an outside point, and a zero result excludes the point. Collinear or repeated vertices do not form a triangle with an interior.

This is a half-plane intersection test; it does not require building a complete Binary Space Partitioning tree. Our implementation uses double intermediates decoded from raw coordinates to avoid first reducing precision through float. Floating-point orientation tests can still lose accuracy in extreme cases.

**Learning goal:** Apply class composition and numeric operators to a geometric problem, and connect mathematical orientation with program conditions.

## Build and test

Compile each exercise with:

```text
c++ -Wall -Wextra -Werror -std=c++98
```

Keep class definitions in guarded, self-contained headers and implementations in source files. Use the required directory and file names. Do not use STL containers or algorithms, external libraries, using namespace, or friend. The later exercises authorize roundf from <cmath>.

For ex03, the source list includes main.cpp, Fixed.cpp, Point.cpp, and bsp.cpp.

Useful tests include:

- Copy construction, assignment, and independence of copied values.
- Positive, negative, zero, and fractional numeric inputs.
- Every comparison and arithmetic operator.
- Prefix/postfix return values and changes to the original object.
- Const and mutable min/max overloads, including returned-object identity.
- Overflow and division-by-zero behavior if those checks are implemented.
- Triangle interior, exterior, every edge and vertex, reversed vertex order, degenerate triangles, and points one Fixed step from a boundary.

Passing the subject's sample alone does not verify every operation or numeric edge case.

## Source and learning note

Based on the supplied C++ Module 02 subject, version 9.1, and the implementation discussed during study. This overview summarizes objectives and design decisions; it is not a certification of every code path.

AI assistance was used for explanations, code feedback, test suggestions, and preparing this overview. Each implementation should be tested independently and understood well enough to explain and modify during evaluation.

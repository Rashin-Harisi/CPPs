# C++ Module 01 — Overview

Memory allocation, references, pointers to members, and switch statements.

This module explores object lifetime, the difference between pointers and references, file streams, and selecting behavior through member function pointers. All exercises target C++98.

## Exercises at a glance

| Exercise | Name | Main focus |
|---|---|---|
| ex00 | BraiiiiiiinnnzzzZ | Automatic and dynamic object lifetime |
| ex01 | Moar brainz! | Dynamically allocated arrays of objects |
| ex02 | HI THIS IS BRAIN | Pointers, references, addresses, and values |
| ex03 | Unnecessary violence | Required and optional relationships between objects |
| ex04 | Sed is for losers | File streams and string processing |
| ex05 | Harl 2.0 | Pointers to member functions |
| ex06 | Harl filter | Switch statements and intentional fall-through |

## ex00 — BraiiiiiiinnnzzzZ

Implement a Zombie class with a private name and an announce() method. Its destructor prints a message containing the zombie's name.

- newZombie(name) dynamically creates a named zombie and returns a pointer. The caller can use it after the function returns and must eventually delete it.
- randomChump(name) creates a local zombie and makes it announce itself. Its destructor runs automatically when its scope ends.

**Learning goal:** Choose an appropriate object lifetime and understand when constructors and destructors run. An ordinary local object has automatic storage duration; an object created with new survives until it is deleted.

## ex01 — Moar brainz!

Implement zombieHorde(N, name), which creates N Zombie objects in one allocation, gives every zombie the supplied name, and returns a pointer to the first object.

The caller announces each zombie and releases the entire array with delete[]. This is an array of objects, not an array of individually allocated pointers.

**Learning goal:** Understand default construction of array elements, indexing through a pointer, and matching new[] with delete[]. Validate the chosen behavior for nonpositive N and check for leaks.

## ex02 — HI THIS IS BRAIN

Create a string initialized to "HI THIS IS BRAIN", a pointer to it, and a reference to it. Print their associated addresses and then their values.

The pointer stores the string object's address. The reference is another name for the same object. Taking the address of the reference gives the address of that object; dereferencing the pointer gives access to it.

**Learning goal:** Distinguish an address from a value and compare pointer and reference syntax. A std::string pointer points to the string object, rather than being a C-style character string.

## ex03 — Unnecessary violence

Implement Weapon, HumanA, and HumanB. Weapon stores a type, exposes it through a const reference, and allows it to be changed with setType(). Both humans can announce an attack using their weapon's current type.

| Class | Relationship to Weapon | Reason |
|---|---|---|
| HumanA | Reference supplied to its constructor | It must have a weapon from construction |
| HumanB | Pointer, initially NULL, assigned through setWeapon() | It may exist without a weapon |

Both humans use the existing weapon rather than keeping a separate copy. Changing that weapon's type must affect subsequent attacks. HumanB checks its pointer before using it. Neither human owns the weapon merely because it holds a reference or pointer; the weapon must remain alive while it is used.

**Learning goal:** Model required versus optional relationships, initialize reference members through constructor initialization lists, and understand object lifetime and const-reference return types.

## ex04 — Sed is for losers

Accept a filename, s1, and s2. Copy the input into a new file named filename.replace, replacing every occurrence of s1 with s2. Preserve all other content, including line breaks and whether the file ends with a newline.

- Use C++ file streams; C file manipulation functions are forbidden.
- std::string::replace() is forbidden. Searching and building strings with find() and substr() is one possible approach.
- Continue searching beyond inserted text so replacement text is not repeatedly processed.
- Define behavior for empty s1 and handle argument, file-opening, reading, and writing errors.
- In C++98, use c_str() when passing a std::string filename to file-stream constructors or open().

**Learning goal:** Combine string processing with file I/O and distinguish normal end-of-file from failure. Whole-content processing also allows matches containing newlines.

Suggested tests include repeated matches, no matches, empty replacement text, replacement text containing s1, empty files, missing files, and files without a final newline. The subject requires submitting your own tests.

## ex05 — Harl 2.0

Implement four private methods: debug(), info(), warning(), and error(). The public complain(level) method selects the appropriate message.

Pointers to member functions are mandatory. One approach pairs an array of level names with an array of member function pointers, finds the matching index, and invokes the selected method on the current object. A simple comparison inside a loop is compatible with this design; a long if/else dispatch chain defeats the exercise's purpose.

**Learning goal:** Store a choice of behavior in a variable. A non-static member function pointer identifies a method and requires an object for invocation. Private methods can be accessed from other methods of the same class.

## ex06 — Harl filter

Build an executable named harlFilter that accepts one log level and displays that level and all higher levels. A switch statement is mandatory.

| Input | Levels displayed |
|---|---|
| DEBUG | DEBUG, INFO, WARNING, ERROR |
| INFO | INFO, WARNING, ERROR |
| WARNING | WARNING, ERROR |
| ERROR | ERROR |
| Unknown level | The subject's default message |

Map the input string to an integer before using switch. Case labels are compile-time integral constants, not strings. Initialize the selected index to an invalid value so unknown input reaches default safely.

With intentional fall-through, execution starts at the matching case and continues through subsequent cases until a break. The index does not change, and case conditions are not repeatedly tested. A recognized fall-through comment can document this intent and suppress GCC's implicit-fallthrough warning under the relevant warning settings; C++17's [[fallthrough]] attribute is not available in C++98.

**Learning goal:** Understand switch control flow and severity filtering. Exercise 06 is optional for passing the module according to the subject.

## General project rules

- Compile with c++ and -Wall -Wextra -Werror; keep compatibility with -std=c++98.
- Organize exercises in ex00 through ex06 and follow the required file and class names.
- Put class declarations in guarded, self-contained headers and ordinary function definitions in .cpp files.
- Avoid memory leaks. Match new with delete and new[] with delete[].
- Do not use using namespace, friend, external libraries, C++11 features, printf-family functions, malloc-family functions, or free().
- STL containers and algorithms are not permitted in this module.
- Be ready to explain your implementation and make a small modification during evaluation.

## Study and source note

This overview summarizes the C++ Module 01 subject, version 11.1, and the concepts discussed while developing the exercises. It describes the exercises rather than certifying that every implementation is complete. In particular, ex04's read-error handling was still under review when this overview was prepared.

AI assistance was used for concept explanations, code feedback, test ideas, and preparing this overview. Verify behavior with your own tests and be able to explain every submitted line.

# C++ Module 00 — Exercise Overview

This module introduces C++ and the foundations of object-oriented programming using **C++98**. The exercises progress from text processing to class design and shared class state.

| Exercise | Program | Main focus |
|---|---|---|
| ex00 | Megaphone | Command-line arguments, character conversion, and output streams |
| ex01 | My Awesome PhoneBook | Classes, encapsulation, input validation, and arrays of objects |
| ex02 | The Job Of Your Dreams | Reconstructing an implementation, static members, and object lifetime |

## ex00 — Megaphone

### What the program does

The program reads command-line arguments and prints their characters in uppercase. Arguments are concatenated without adding extra spaces, and the output ends with a newline. When no arguments are supplied, it prints:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### Concepts practiced

- Accessing command-line arguments through `argc` and `argv`.
- Iterating through null-terminated character strings.
- Using `std::toupper` from `<cctype>` to convert individual characters.
- Converting characters to `unsigned char` before passing them to `std::toupper` to avoid invalid negative inputs.
- Printing through `std::cout` and using the `std::` namespace prefix.
- Compiling with a Makefile and `-Wall -Wextra -Werror -std=c++98`.

## ex01 — My Awesome PhoneBook

### What the program does

The program maintains an in-memory phonebook and accepts three commands: `ADD`, `SEARCH`, and `EXIT`. Other commands are ignored. Contacts are lost when the program exits.

- **ADD:** Collects a first name, last name, nickname, phone number, and darkest secret. No saved field may be empty. The phonebook stores at most eight contacts; adding another contact replaces the oldest one.
- **SEARCH:** Displays saved contacts in a table containing an index, first name, last name, and nickname. The user then selects an index to display all five fields of that contact. This is selection by index, rather than a search by name or phone number.
- **EXIT:** Ends the program.

Each table column is ten characters wide and right-aligned, with `|` separators. Text longer than ten characters is displayed as its first nine characters followed by a dot. The original contact information remains unchanged.

### Class responsibilities

| Class | Responsibility |
|---|---|
| Contact | Stores one contact's information and provides methods to set, read, and display it |
| PhoneBook | Manages the fixed contact array, saved-contact count, next insertion position, and ADD/SEARCH operations |

### Concepts practiced

- Defining classes, creating objects, and accessing public members with `.`.
- Encapsulation through `private` data and `public` methods.
- Setters and getters for controlled access to contact information.
- Separating class definitions and method declarations in headers from method implementations in `.cpp` files.
- Include guards, header dependencies, and the `ClassName::` syntax.
- Constructors for establishing an initial state.
- Using `std::string` for text and phone numbers.
- Fixed arrays of objects without dynamic allocation.
- Keeping the saved-contact count separate from the next insertion index: eight contacts occupy indices zero through seven.
- Reading complete lines with `std::getline`, rejecting empty fields, and handling EOF.
- Formatting output with `<iomanip>`, `std::setw`, and `std::right`.
- Using `substr` to shorten display copies without changing stored values.
- String streams for index formatting and integer-input validation.
- Const member functions that read or display information without modifying the object.

## ex02 — The Job Of Your Dreams

### What the program does

The missing `Account.cpp` is reconstructed using the interface in `Account.hpp`, the supplied `tests.cpp`, and a reference log. Accounts are created with initial balances, deposits and withdrawals are performed, and individual status and overall statistics are printed with timestamps.

A withdrawal is refused when the balance is insufficient. A refused withdrawal leaves the balance and counters unchanged. The withdrawal method returns a boolean indicating success or failure.

Output must match the reference log except for timestamps. Destructor order may also differ depending on the compiler and operating system.

### Method responsibilities

| Method or component | Responsibility |
|---|---|
| Constructor with an initial deposit | Initializes the account, assigns its index, updates shared statistics, and prints `created` |
| Destructor | Prints `closed` when the account's lifetime ends |
| makeDeposit | Updates the account balance and deposit counters and prints transaction details |
| makeWithdrawal | Accepts or refuses a withdrawal and returns `true` or `false` |
| checkAmount | Returns the current account balance |
| displayStatus | Displays one account's balance and transaction counters |
| displayAccountsInfos | Displays the shared account count, total balance, and transaction counters |
| Static getters | Return shared account statistics |
| _displayTimestamp | Prints the current local time in `[YYYYMMDD_HHMMSS] ` format |

### Concepts practiced

- Implementing an existing interface and inferring behavior from tests and logs.
- Distinguishing per-object members from `static` members shared by all objects.
- Defining and initializing static data members outside functions in a `.cpp` file.
- Updating shared totals without resetting them whenever a new account is constructed.
- Parameterized constructors, destructors, and automatic object lifetime behavior.
- Constructor access control: the no-argument constructor is private, while construction with an initial deposit is public.
- Distinguishing the constructor parameter `initial_deposit` from the persistent balance member `_amount`.
- Static member functions and const member functions.
- Type aliases: `Account::t` names the `Account` type and does not create an object.
- Time formatting using `<ctime>`, `time`, `localtime`, and `strftime`.
- Matching output labels, separators, spacing, and values precisely.

The reference log does not establish whether shared statistics change in the destructor, because it does not display overall statistics after account closure.

> Completing ex02 is not mandatory to pass this module, according to the subject.

## Shared Module Rules and Practices

- Use C++98-compatible code.
- Do not use `using namespace`, `friend`, printf-family functions, or C memory-allocation functions.
- Keep method implementations in `.cpp` files and protect headers with include guards.
- Name class files according to their class names.
- `.h` and `.hpp` both serve as headers; the extension is a naming convention.
- Compile `.cpp` files; track headers as build dependencies.
- Do not add STL containers or algorithms to your own implementation. Their existing use in the supplied ex02 test belongs to that provided test code.

## AI Usage

AI was used during learning to explain C++ concepts, review code snippets, interpret compiler errors, and analyze the reference log. This overview summarizes the exercises; it does not replace reading the subject or understanding and being able to modify the implementation during evaluation.

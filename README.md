# C++ Library Project

A small C++ project for practicing object-oriented programming.

## Features

- Books and magazines inherit from `LibraryItem`
- Polymorphism through virtual methods
- Automatic item and member IDs
- Borrowing and returning items
- Loans are the source of truth for borrowed status
- Unit tests using `assert`

## Project structure

- `include/` — header files
- `src/` — implementation files
- `tests/` — test files
- `main.cpp` — application entry point

## Compile the application

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src\*.cpp main.cpp -o app
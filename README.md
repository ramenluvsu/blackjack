# Blackjack in C++
C++ OOP Blackjack game — CSE142 Project

A fully functional terminal-based Blackjack game built in C++ for CSE142 - Object Oriented Programming Techniques (Spring 2026).

## How to Play

- You and the Dealer are each dealt 2 cards
- **Hit** to take another card, **Stand** to stop
- Get as close to 21 as possible without busting
- Dealer must hit until they reach 17+
- Closest to 21 wins

## Build and Run

Make sure you have `g++` installed, then:

```bash
make
./blackjack
```

To clean the build:

```bash
make clean
```

## Project Structure
blackjack/
├── include/        # Header files (.h)
├── src/            # Source files (.cpp)
└── Makefile

## OOP Concepts Used

| Concept | Where |
|---|---|
| Encapsulation | Private members + getters/setters in all classes |
| Inheritance | `HumanPlayer` and `Dealer` inherit from `Player` |
| Polymorphism | `makeMove()` behaves differently per derived class |
| Abstract Class | `Player` with pure virtual `makeMove() = 0` |
| Operator Overloading | `operator<<` in `Card` |
| Templates | `GameStack<T>` generic stack |
| Exception Handling | Empty deck/stack throws `runtime_error` |
| Recursion | `calculateTotal()` in `Hand` |
| STL Containers | `vector`, `map` throughout |
| Friend Class | `Dealer` is friend of `Hand` |

## Author

Raahim Imran — [GitHub](https://github.com/ramenluvsu)

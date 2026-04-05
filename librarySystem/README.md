# 📚 Modular Library Management System (OOP)

A professional C++ console application for managing library resources, members, and book issuance. This project demonstrates high-level **Object-Oriented Programming (OOP)** principles, specifically focusing on **Composition** and **File Handling**.

## 🚀 Key Features

- **Object-Oriented Architecture**: Cleanly separated logic using `Book`, `Member`, and `Library` classes.
- **Composition (Has-A Relationship)**: The `Library` class manages collections of `Book` and `Member` objects.
- **Book Issuance System**: Track which member has borrowed which book, including availability checks.
- **Persistence**: Automatically exports a report of all issued books and their current holders to `IssuedBooks.txt`.
- **Modular Design**: Split into header-only files (`.hpp`) for better organization and scalability.
- **Operator Overloading**: Implements custom equality operators for efficient book searching.

## 🛠️ Technical Stack

- **Language:** C++ (Standard 11 or higher)
- **Concepts:** 
  - **Encapsulation**: Private and Protected data protection.
  - **Composition**: Building complex systems by combining objects.
  - **File I/O**: Persistent data storage using `std::ofstream`.
  - **Modular Headers**: Use of Header Guards (`#ifndef`) to prevent redefinition errors.

## 📁 Project Structure

- `book.hpp`: Defines the book entity with properties like author and issuance status.
- `member.hpp`: Manages library member profiles and unique identification.
- `library.hpp`: The core system controller that manages the book inventory and member records.
- `main.cpp`: The entry point showcasing the system in action.

# 1. Clone the repository
git clone https://github.com/abdulrehman78-cyber/cpp-oop-projects.git

# 2. Enter the project folder
cd hotelManagmentSystem

# 3. Compile and Run
g++ main.cpp -o HotelApp
./HotelApp

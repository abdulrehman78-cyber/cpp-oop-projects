# Hotel Management System (OOP)

A modular C++ application managing hotel operations using advanced OOP principles.

##  Key Features
- **Inheritance & Polymorphism**: Handles Dine-In and Delivery orders via a base Order class.
- **Smart Pointers**: Uses `std::unique_ptr` for automatic memory management (No memory leaks!).
- **Composition**: The Waiter class manages a Menu object and processes Orders.
- **File Persistence**: Saves all transaction records to `order.txt`.
- **Input Normalization**: Case-insensitive item searching (e.g., "pIzZa" works!).

## Technical Stack
- C++14/17
- STL Containers (std::map)
- Header-only Modular Architecture

## 🔧 How to Run

1. **Clone the entire collection**:
   ```bash
   git clone https://github.com/abdulrehman78-cyber/cpp-oop-projects.git
   g++ -std=c++14 main.cpp -o App
   ./App

# ⚔️ RPG Battle System (C++ OOP)
A terminal-based RPG battle engine designed to demonstrate robust **Object-Oriented Programming** architecture.

## 🚀 Key Features
*   **Turn-Based Combat:** Dynamic battle loop between Player and Enemy.
*   **Weapon System:** Scaling attack power based on inventory.
*   **Persistence:** Saves final game state to `save.txt`.

## 🏗️ OOP Architecture
*   **Abstraction:** Abstract `Character` base class with pure virtual functions.
*   **Inheritance:** Derived `Player` and `Enemy` classes.
*   **Composition:** `Player` has-an `Inventory`, which has-many `Weapon` objects.
*   **Encapsulation:** Protected/Private attributes with public getters/setters.

# 1. Clone the repository
git clone https://github.com/abdulrehman78-cyber/cpp-oop-projects.git

# 2. Enter the project folder
cd miniGame

# 3. Compile and Run
g++ main.cpp -o game
./game

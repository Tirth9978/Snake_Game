
# 🐍 Snake Game

---

## 📌 Table of Contents
- [📖 Introduction](#-introduction)
- [✨ Features](#-features)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure](#-code-structure)
- [📊 Data Structure Analysis](#-data-structure-analysis)
- [📜 Detailed Code Explanation](#-detailed-code-explanation)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)

---

## 📖 Introduction
This game is made by Bitwise Wizards.This project is a console-based Snake Game implemented in C++. It follows an object-oriented approach using classes and inheritance to manage game components like the snake, fruit, and game board.**Our code is for Windows and Linux.It will work in both OS.**

---

## ✨ Features
- 🎯 Grid-based gameplay.
- 🎮 Snake movement using keyboard controls.
- 🍏 Normal and special fruits for scoring.
- 🚧 Obstacles appear as the game progresses.
- 🧱 Wall collision mode (can be enabled or disabled).
- 🔄 Dynamic difficulty adjustment.
- 📺 Clear UI with instructions and score tracking.

---


## 🎮 How to Play
- Control the snake using `W, A, S, D` or arrow keys.
- 🍏 Eat fruits (`@` for normal, `$` for special) to grow and score points.
- 🚧 Avoid walls and obstacles (`#`).
- ☠️ Game over if the snake collides with itself or obstacles.
- 🔄 Restart or exit after game over.

---

## 🎯 Game Controls
| 🎮 Key | 🏹 Action |
|--------|-----------|
| `W / ⬆️` | Move Up |
| `S / ⬇️` | Move Down |
| `A / ⬅️` | Move Left |
| `D / ➡️` | Move Right |
| `P` | Pause |
| `R` | Resume |
| `X` | Reset Game |
| `ESC` | Exit Game |

---

## 🕹️ Game Mechanics
- 🐍 The snake moves continuously in the last chosen direction.
- 🍏 Eating a normal fruit (@) increases the score by **5 points**.
- 💰 Eating a special fruit ($) increases the score by **20 points**.
- 🚧 Once the score reaches **50**, obstacles appear.
- 🔼 The difficulty increases dynamically with score progression.

---

## 💡 Code Structure
The game is implemented using **Object-Oriented Programming (OOP) principles**:
- 🛠️ `Game` (Base Class): Defines the core game logic and properties.
- 🐍 `Snake` (Inherits from Game): Handles the snake’s movement.
- 🍏 `Fruit` (Inherits from Snake): Manages fruit generation.
- 🎮 `Main` (Inherits from Fruit): Controls the game loop, rendering, and input handling.

---

## 📊 Data Structure Analysis
### 📂 **Data Structures Used**
- 📌 **Arrays (`int Tail_X[], Tail_Y[]`)**: Stores the position of the snake's tail.
- 📊 **Vector (`vector<pair<int, int>> obstacles`)**: Stores obstacle positions efficiently.
- 🔢 **Enum (`enum direction`)**: Represents movement directions (`LEFT, RIGHT, UP, DOWN, STOP`).

### 🔍 **Object Structure**
1. **Game Class**: Initializes board size, score, and game state.
2. **Snake Class**: Extends Game by adding movement and tail logic.
3. **Fruit Class**: Extends Snake to generate food at random locations.
4. **Main Class**: Controls the entire game flow, rendering, and input processing.

---

## 📜 Detailed Code Explanation
### 📌 **Variables & Their Purpose**
| Variable | Data Type | Purpose |
|----------|----------|---------|
| `width, height` | `const int` | Defines the game board size. |
| `SnakeX, SnakeY` | `int` | Stores the position of the snake’s head. |
| `fruitX, fruitY` | `int` | Stores the position of the fruit. |
| `score` | `int` | Tracks player’s score. |
| `Tail_Length` | `int` | Stores snake length. |
| `Tail_X[], Tail_Y[]` | `int arrays` | Stores tail coordinates. |
| `obstacles` | `vector<pair<int, int>>` | Stores obstacle positions. |
| `Dir` | `enum direction` | Tracks movement direction. |
| `isGameOver` | `bool` | Checks if game has ended. |

---

## 🚀 Future Enhancements
- 🎮 Multiple levels with increasing complexity.
- 👫 Multiplayer mode with two snakes.
- 🏆 High score tracking system.
- 🤖 AI-controlled opponent snakes.
- 🎨 GUI-based version using a graphics library.

---

## 👥 Contributors
- 🏅 Tirth Patel (202401157)
- 🏅 Raj Patel (202401152)
- 🏅 Shlok Patel (202401156)
- 🏅 Prakriti Pandey (202401164)

---

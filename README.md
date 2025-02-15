# 🐍 Classic Snake Game in C++ | Console-Based Open-Source Project

---

## 📌 Table of Contents
- [📚 Introduction](#-introduction)
- [✨ Features](#-features)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure & OOP Concepts](#-code-structure--oop-concepts)
- [📊 Data Structures Used](#-data-structures-used)
- [📝 Code Explanation](#-code-explanation)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)
- [⭐ Star & Contribute](#-star--contribute)

---

## 📚 Introduction
This **Classic Snake Game** is a **console-based** game built using **C++ and Object-Oriented Programming (OOP)** principles. It runs seamlessly on **Windows & Linux**, requiring no external libraries. This project is **open-source**, making it a valuable resource for beginners interested in **C++ game development**.

🔥 **Why Choose This Game?**
- Learn **C++ game development** from scratch.
- Explore **OOP principles (classes, inheritance, encapsulation, abstraction)**.
- Develop problem-solving skills with **data structures & algorithms**.
- Experience **real-time user input handling** and game logic implementation.

---

## ✨ Features
- 🎯 **Classic grid-based gameplay**.
- 🎮 **Smooth snake movement** with real-time input handling.
- 🍏 **Normal & Special Fruits** for different score values.
- 🛠 **Configurable difficulty levels**.
- 🌟 **Score tracking system**.
- 🔴 **Dynamic obstacles** appear as the game progresses.
- 🛡 **Wall collision mode** (toggleable).
- 👀 **User-friendly UI with game stats**.

---

## 🎮 How to Play
- Control the snake using `W, A, S, D` or **arrow keys**.
- 🍏 **Eat normal fruits (`@`)** to gain **5 points**.
- 💰 **Eat special fruits (`$`)** to gain **20 points**.
- 🚫 **Avoid walls, obstacles (`#`), and self-collision**.
- ☠️ **Game Over** if the snake collides with itself or an obstacle.
- ↺ Restart or exit after game over.

---

## 🎯 Game Controls
| 🎮 Key | 🛠 Action |
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
- 🍏 Eating a **normal fruit (`@`)** increases score by **5 points**.
- 💰 Eating a **special fruit (`$`)** increases score by **20 points**.
- 🛠 **Obstacles appear** once the score reaches **50**.
- 🌟 The difficulty **dynamically increases** as score progresses.

---

## 💡 Code Structure & OOP Concepts
This project follows **Object-Oriented Programming (OOP)** principles:

- 🛠 **Game (Base Class)** → Defines core game logic.
- 🐍 **Snake (Inherits from Game)** → Handles movement & tail growth.
- 🍏 **Fruit (Inherits from Snake)** → Manages fruit generation.
- 🎮 **Main (Inherits from Fruit)** → Controls the **game loop**, rendering, and input handling.

---

## 📊 Data Structures Used
### **🔹 Data Structures Implemented**
| Data Structure | Purpose |
|---------------|---------|
| **Arrays** (`int Tail_X[], Tail_Y[]`) | Stores the snake’s tail positions. |
| **Vector** (`vector<pair<int, int>> obstacles`) | Efficiently stores obstacle positions. |
| **Enum** (`enum direction`) | Represents movement directions (`LEFT, RIGHT, UP, DOWN, STOP`). |

---

## 📝 Code Explanation
### **🔹 Important Variables**
| Variable | Data Type | Purpose |
|----------|----------|---------|
| `width, height` | `const int` | Defines board size. |
| `SnakeX, SnakeY` | `int` | Snake’s head position. |
| `fruitX, fruitY` | `int` | Fruit’s position. |
| `score` | `int` | Player’s current score. |
| `Tail_Length` | `int` | Stores snake’s length. |
| `Tail_X[], Tail_Y[]` | `int arrays` | Stores tail coordinates. |
| `obstacles` | `vector<pair<int, int>>` | Stores obstacle positions. |
| `Dir` | `enum direction` | Tracks movement direction. |
| `isGameOver` | `bool` | Checks if game is over. |

---

## 🚀 Future Enhancements
Planned features for future updates:
- 🌟 **Multiple Levels** with increasing difficulty.
- 🎉 **Multiplayer Mode** for competitive gameplay.
- 🏆 **High Score System** for tracking performance.
- 🤖 **AI-controlled Snakes** as opponents.
- 🎨 **Graphical UI Version** using a graphics library.

**Have ideas? Open an issue or contribute!** 🚀  

---

## 👥 Contributors
- 🏅 **Tirth Patel (202401157)**
- 🏅 **Raj Patel (202401152)**
- 🏅 **Shlok Patel (202401156)**
- 🏅 **Prakriti Pandey (202401164)**

👏 **Special thanks to all contributors!**

---

## ⭐ Star & Contribute  
If you find this project useful, please **star ⭐ the repo** and share it!  

👉 **GitHub Repository:** [Snake Game in C++](https://github.com/Tirth9978/Snake_Game)

📈 **Want to contribute?** Fork the repo, make improvements, and submit a pull request! 🚀  


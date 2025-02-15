# 🐍 Classic Snake Game in C++ | Console-Based Open-Source Project  

---

## 📌 Table of Contents
- [📖 Introduction](#-introduction)
- [✨ Features](#-features)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure & OOP Concepts](#-code-structure--oop-concepts)
- [📊 Data Structures Used](#-data-structures-used)
- [📜 Code Explanation](#-code-explanation)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)
- [⭐ Star & Contribute](#-star--contribute)

---

## 📖 Introduction
This **classic Snake Game** is developed by **Bitwise Wizards** in **C++** using **Object-Oriented Programming (OOP)**.  
It is a **console-based game** that runs on **Windows and Linux** without external libraries.  
The project is **fully open-source**, making it a great resource for beginners in **C++ game development**.

🔥 **Why This Game?**  
- Learn **C++ game development** from scratch.  
- Explore **OOP principles (classes, inheritance)**.  
- Improve problem-solving skills with **data structures & algorithms**.  

---

## ✨ Features
- 🎯 **Classic grid-based gameplay**.
- 🎮 **Smooth snake movement** using keyboard controls.
- 🍏 **Normal & Special Fruits** for scoring.
- 🚧 **Dynamic obstacles** appear as the game progresses.
- 🧱 **Wall collision mode** (can be enabled/disabled).
- 📺 **Simple UI with live score tracking**.
- 🔄 **Difficulty increases dynamically** as score progresses.

---

## 🎮 How to Play
- Move the snake using `W, A, S, D` or **arrow keys**.
- 🍏 **Eat normal fruits (`@`)** to gain **5 points**.
- 💰 **Eat special fruits (`$`)** to gain **20 points**.
- 🚧 Avoid **walls & obstacles (`#`)**.
- ☠️ **Game Over** if the snake collides with itself or an obstacle.
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
- 🍏 Eating a **normal fruit (`@`)** increases score by **5 points**.
- 💰 Eating a **special fruit (`$`)** increases score by **20 points**.
- 🚧 **Obstacles appear** once the score reaches **50**.
- 🔼 The difficulty **dynamically increases** as you score higher.

---

## 💡 Code Structure & OOP Concepts
This project follows **Object-Oriented Programming (OOP)** principles:  

- 🛠️ **Game (Base Class)** → Defines core game logic.  
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

## 📜 Code Explanation
### **📌 Important Variables**
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
We plan to add **more exciting features**:
- 🎮 **Multiple Levels** with increasing complexity.
- 👫 **Multiplayer Mode** with two snakes.
- 🏆 **High Score System** to track best performances.
- 🤖 **AI-controlled Snakes** as opponents.
- 🎨 **GUI-based version** using a graphics library.

Have ideas? **Open an issue or contribute!** 🚀  

---

## 👥 Contributors
- 🏅 **Tirth Patel (202401157)**
- 🏅 **Raj Patel (202401152)**
- 🏅 **Shlok Patel (202401156)**
- 🏅 **Prakriti Pandey (202401164)**

🙌 **Special thanks to all contributors!**

---

## ⭐ Star & Contribute  
If you find this project useful, please consider **starring ⭐ the repo**!  

🔗 **GitHub Repository:** [Snake Game in C++](https://github.com/Tirth9978/Snake_Game)  

💡 **Want to contribute?** Fork the repo, make improvements, and submit a pull request! 🚀  

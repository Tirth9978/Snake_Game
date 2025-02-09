# 🐍 Snake Game

---
# Snake Game Documentation

## 📌 Table of Contents
- [📖 Introduction](#-introduction)
- [✨ Features](#-features)
- [⚙️ Installation](#-installation)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure](#-code-structure)
- [📊 Data Structure Analysis](#-data-structure-analysis)
- [🔧 Code Breakdown](#-code-breakdown)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)

## 📖 Introduction
This project is a console-based Snake Game implemented in C++. It follows an object-oriented approach using classes and inheritance to manage game components like the snake, fruit, and game board.

## ✨ Features
- 🎯 Grid-based gameplay.
- 🎮 Snake movement using keyboard controls.
- 🍏 Normal and special fruits for scoring.
- 🚧 Obstacles appear as the game progresses.
- 🧱 Wall collision mode (can be enabled or disabled).
- 🔄 Dynamic difficulty adjustment.
- 📺 Clear UI with instructions and score tracking.

## ⚙️ Installation
```bash
git clone https://github.com/Tirth9978/Snake_Game.git
cd Snake_Game
g++ -o main main.cpp
./main  # (Linux/macOS)
main.exe  # (Windows)
```

## 🎮 How to Play
- Control the snake using **W, A, S, D** or **Arrow keys**.
- 🍏 Eat fruits (@ for normal, $ for special) to grow the snake and increase the score.
- 🚧 Avoid hitting the walls (if enabled) and obstacles (#).
- ☠️ Game over if the snake collides with itself or an obstacle.
- 🔄 After the game ends, you can restart or exit.

## 🎯 Game Controls
| Key | Action |
|---|---|
| W / ⬆️ | Move Up |
| S / ⬇️ | Move Down |
| A / ⬅️ | Move Left |
| D / ➡️ | Move Right |
| ⏸️ P | Pause |
| ▶️ R | Resume |
| 🔄 X | Reset Game |
| ❌ ESC | Exit Game |

## 🕹️ Game Mechanics
- The 🐍 snake moves continuously in the last chosen direction.
- 🍏 Eating a normal fruit (@) increases the score by **5 points**.
- 💰 Eating a special fruit ($) increases the score by **20 points**.
- 🚧 Once the score reaches **50**, obstacles start appearing.
- 🔼 The difficulty dynamically increases as the score rises.

## 💡 Code Structure
The game is implemented using **Object-Oriented Programming (OOP)** principles:
- **🛠️ Game (Base Class):** Defines the core game logic and properties.
- **🐍 Snake (Inherits from Game):** Handles the snake’s position and movement.
- **🍏 Fruit (Inherits from Snake):** Manages fruit generation.
- **🎮 Main (Inherits from Fruit):** Controls the game loop, rendering, and input handling.

## 📊 Data Structure Analysis
### 📂 Data Structures Used:
#### 📌 Arrays
```cpp
int *Tail_X, *Tail_Y;  // Stores snake tail positions dynamically
```
- Allows the snake to grow dynamically.

#### 📊 Vectors
```cpp
vector<pair<int, int>> obstacles;  // Stores obstacles' positions
```
- Efficiently manages obstacles on the game board.

#### 🔢 Enum (direction)
```cpp
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;
```
- Keeps track of the snake's movement direction.

## 🔧 Code Breakdown
### 1️⃣ Game Initialization
```cpp
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score, tailLength;
bool gameOver;
```
- Initializes board size, snake position, fruit position, score, and game state.

### 2️⃣ Setup Function
```cpp
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2; y = height / 2;
    fruitX = rand() % width; fruitY = rand() % height;
    score = 0; tailLength = 0;
}
```
- Sets the **initial snake position**, **places the fruit randomly**, and **resets score**.

### 3️⃣ Game Loop
```cpp
while (!gameOver) {
    Draw();
    Input();
    Logic();
}
```
- The game runs continuously until `gameOver = true`.

### 4️⃣ Draw Function
```cpp
void Draw() {
    system("cls");
    // Draw game board, snake, fruit, and obstacles
}
```
- Clears the screen and **redraws the game board** each frame.

### 5️⃣ Input Function
```cpp
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}
```
- Detects **keyboard input** and updates the snake’s **direction**.

### 6️⃣ Logic Function
```cpp
void Logic() {
    // Move the snake
    // Check for collisions
    // Grow the snake if fruit is eaten
}
```
- Moves the snake, **checks collisions**, and **handles fruit eating**.

## 🚀 Future Enhancements
- 🎮 Implementing multiple levels with increasing complexity.
- 👥 Multiplayer mode for two players.
- 🏆 High score tracking system.
- 🤖 AI-controlled snakes.
- 🎨 GUI-based version using graphics libraries.

## 👥 Contributors
🏅 Tirth Patel  
🏅 Raj Patel  
🏅 Shlok Patel  
🏅 Prakriti Panday  

---

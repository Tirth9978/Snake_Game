# 🐍 Snake Game

## 📌 Table of Contents
- [📖 Introduction](#📖-introduction)
- [✨ Features](#✨-features)
- [⚙️ Installation](#⚙️-installation)
- [🎮 How to Play](#🎮-how-to-play)
- [🎯 Game Controls](#🎯-game-controls)
- [🕹️ Game Mechanics](#🕹️-game-mechanics)
- [💡 Code Structure](#💡-code-structure)
- [📊 Data Structure Analysis](#📊-data-structure-analysis)
- [🚀 Future Enhancements](#🚀-future-enhancements)
- [👥 Contributors](#👥-contributors)

---

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
1. Clone the repository:
   ```sh
   git clone https://github.com/Tirth9978/Snake_Game.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Snake_Game
   ```
3. Compile the code using g++ (for Linux/macOS):
   ```sh
   g++ -o main main.cpp
   ```
   For Windows (using MinGW):
   ```sh
   g++ -o main.exe main.cpp
   ```
4. Run the executable:
   ```sh
   ./main  # (Linux/macOS)
   main.exe  # (Windows)
   ```

## 🎮 How to Play
- Control the snake using **W, A, S, D** or **arrow keys**.
- 🍏 Eat fruits (@ for normal, $ for special) to grow the snake and increase the score.
- 🚧 Avoid hitting the walls (if enabled) and obstacles (#).
- ☠️ Game over if the snake collides with itself or an obstacle.
- 🔄 After the game ends, you can restart or exit.

## 🎯 Game Controls
| 🎮 Key   | 🏹 Action |
|-------|--------|
| W / ⬆️ Up Arrow   | Move Up |
| S / ⬇️ Down Arrow | Move Down |
| A / ⬅️ Left Arrow | Move Left |
| D / ➡️ Right Arrow | Move Right |
| ⏸️ P | Pause |
| ▶️ R | Resume |
| 🔄 X | Reset Game |
| ❌ ESC | Exit Game |

## 🕹️ Game Mechanics
- The 🐍 snake moves continuously in the last chosen direction.
- 🍏 Eating a **normal fruit** (@) increases the score by **5 points**.
- 💰 Eating a **special fruit** ($) increases the score by **20 points**.
- 🚧 Once the score reaches **50**, obstacles start appearing.
- 🔼 The difficulty dynamically increases as the score rises.

## 💡 Code Structure
The game is implemented using Object-Oriented Programming (OOP) principles:

- **🛠️ `Game` (Base Class)**: Defines the core game logic and properties.
- **🐍 `Snake` (Inherits from Game)**: Handles the snake’s position and movement.
- **🍏 `Fruit` (Inherits from Snake)**: Manages fruit generation.
- **🎮 `Main` (Inherits from Fruit)**: Controls the game loop, rendering, and input handling.

## 📊 Data Structure Analysis
### 📂 Data Structures Used:
- **📌 Arrays (`int *Tail_X, *Tail_Y`)**:
  - Used to store the position of the snake's tail dynamically.
  - Allows flexible snake growth by increasing memory allocation.

- **📊 Vector (`vector<pair<int, int>> obstacles`)**:
  - Stores positions of randomly generated obstacles.
  - Enables efficient obstacle placement and collision detection.

- **🔢 Enum (`enum direction`)**:
  - Represents movement directions (`LEFT`, `RIGHT`, `UP`, `DOWN`, `STOP`).
  - Makes direction control easy and readable.

### 🔍 Object Structure:
- `Game` class initializes **width, height, score, and game state**.
- `Snake` class extends `Game` by adding **snake movement and tail handling**.
- `Fruit` class extends `Snake` to **generate food at random locations**.
- `Main` class controls **game logic, collision handling, rendering, and input processing**.

## 🚀 Future Enhancements
- 🎮 Implementing **multiple levels** with increasing complexity.
- 👥 We can add **Multiplayer Mode** where two players can play with their own snakes.
- 🏆 Adding a **high score tracking system**.
- 🤖 Introducing **AI-controlled snakes** as opponents.
- 🎨 Creating a **GUI-based version** using a graphics library.

---

   ## 👥 Contributors
- 🏅 Tirth Patel
- 🏅 Raj Patel
- 🏅 Shlok Patel
- 🏅 Prakriti Panday
- # 🐍 Snake Game

## 📌 Table of Contents
- [📖 Introduction](#-introduction)
- [✨ Features](#-features)
- [⚙️ Installation](#-installation)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure](#-code-structure)
- [📊 Data Structure Analysis](#-data-structure-analysis)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)
- [📝 Understanding the Code](#-understanding-the-code)

---

## 📖 Introduction
This project is a console-based **Snake Game** implemented in **C++**. It follows an object-oriented approach using **classes and inheritance** to manage game components like the **snake, fruit, and game board**.

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

## ⚙️ Installation
### Clone the repository:
```sh
git clone https://github.com/Tirth9978/Snake_Game.git
```
### Navigate to the project directory:
```sh
cd Snake_Game
```
### Compile the code using g++ (for Linux/macOS):
```sh
g++ -o main main.cpp
```
### For Windows (using MinGW):
```sh
g++ -o main.exe main.cpp
```
### Run the executable:
```sh
./main  # (Linux/macOS)
main.exe  # (Windows)
```

---

## 🎮 How to Play
- Control the snake using **W, A, S, D** or **arrow keys**.
- 🍏 **Eat fruits (@ for normal, $ for special)** to grow the snake and increase the score.
- 🚧 **Avoid hitting the walls (if enabled) and obstacles (#).**
- ☠️ **Game over if the snake collides with itself or an obstacle.**
- 🔄 After the game ends, you can **restart or exit**.

---

## 🎯 Game Controls
| 🎮 Key | 🏹 Action |
|--------|------------|
| **W / ⬆️ Up Arrow** | Move Up |
| **S / ⬇️ Down Arrow** | Move Down |
| **A / ⬅️ Left Arrow** | Move Left |
| **D / ➡️ Right Arrow** | Move Right |
| **⏸️ P** | Pause |
| **▶️ R** | Resume |
| **🔄 X** | Reset Game |
| **❌ ESC** | Exit Game |

---

## 🕹️ Game Mechanics
- 🐍 The snake moves **continuously** in the last chosen direction.
- 🍏 Eating a **normal fruit (@)** increases the score by **5 points**.
- 💰 Eating a **special fruit ($)** increases the score by **20 points**.
- 🚧 Once the **score reaches 50**, obstacles start appearing.
- 🔼 The **difficulty dynamically increases** as the score rises.

---

## 💡 Code Structure
The game is implemented using **Object-Oriented Programming (OOP)** principles:

- 🛠️ **Game (Base Class):** Defines the **core game logic** and properties.
- 🐍 **Snake (Inherits from Game):** Handles the **snake’s position and movement**.
- 🍏 **Fruit (Inherits from Snake):** Manages **fruit generation**.
- 🎮 **Main (Inherits from Fruit):** Controls the **game loop, rendering, and input handling**.

---

## 📊 Data Structure Analysis
### 📂 Data Structures Used:
- 📌 **Arrays (`int *Tail_X, *Tail_Y`)**:
  - Stores the **position of the snake's tail dynamically**.
  - Allows **flexible snake growth** by increasing memory allocation.

- 📊 **Vector (`vector<pair<int, int>> obstacles`)**:
  - Stores **positions of randomly generated obstacles**.
  - Enables **efficient obstacle placement and collision detection**.

- 🔢 **Enum (`enum direction`)**:
  - Represents movement **directions (LEFT, RIGHT, UP, DOWN, STOP)**.
  - Makes direction control **easy and readable**.

---

## 📝 Understanding the Code
### **📌 1. How the Game Works Step-by-Step**
1. **The Game Starts** 🚀
   - The game board is set up.
   - The snake is placed in the middle.
   - A random fruit appears.
2. **The Player Controls the Snake** 🎮
3. **The Snake Moves** 🐍
4. **Obstacles Appear** 🚧
5. **Collision Checks** ⚠️
6. **Game Over or Restart?** ❌🔄

### **📌 2. Main Functions Explained**
✅ **`setup()`** 🎬 - Initializes game components.
✅ **`draw()`** 🎨 - Draws the game screen.
✅ **`input()`** ⌨️ - Reads user input.
✅ **`logic()`** 🔄 - Moves the snake, handles collisions.
✅ **`generateFruit()`** 🍏 - Places fruit randomly.
✅ **`generateObstacles()`** 🚧 - Places obstacles.
✅ **`checkCollision()`** 💥 - Detects crashes.
✅ **`run()`** 🏃‍♂️ - Runs the game loop.

---

## 🚀 Future Enhancements
- 🎮 **Multiplayer Mode** → Two-player mode.
- 🏆 **High Score Tracking** → Save highest scores.
- 🤖 **AI Opponents** → Bots that play.
- 🎨 **Graphical Version** → GUI using graphics library.

---

## 👥 Contributors
- 🏅 Tirth Patel
- 🏅 Raj Patel
- 🏅 Shlok Patel
- 🏅 Prakriti Panday

---

Enjoy coding and improving your **Snake Game**! 🎮🐍



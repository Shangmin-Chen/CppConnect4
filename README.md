# CppConnect4

## Overview
This project is a **Connect4 game implementation** written in C++. It supports:
- **Human vs Human** gameplay.
- **Human vs AI**, where the AI uses a lookahead strategy to make decisions.
- Configurable board size and AI difficulty.

The game demonstrates object-oriented programming principles, recursive algorithms for AI decision-making, and effective board management.

---

## Features
1. **Configurable Gameplay**:
   - Set custom board dimensions (rows and columns).
   - Enable or disable AI for Player 2.
   - Specify AI difficulty using lookahead depth.

2. **Human vs AI**:
   - The AI analyzes possible moves up to a specified depth (lookahead) and prioritizes the best option based on a scoring system.

3. **Win Detection**:
   - Horizontal, vertical, and diagonal win conditions are implemented.

4. **Board State Management**:
   - Drop pieces, undo moves, and check for valid moves efficiently.

---

## Project Structure
```
CppConnect4/
├── build/
│   ├── Makefile  // Compile the program
├── include/
│   ├── board.h   // Board management logic
│   ├── game.h    // Game management logic
│   ├── ai.h      // AI decision-making logic
├── src/
│   ├── board.cpp // Board management implementation
│   ├── game.cpp  // Game management implementation
│   ├── ai.cpp    // AI decision-making implementation
│   ├── main.cpp  // Entry point of the application
├── README.md     // Project documentation
├── Makefile      // Build automation (if applicable)
```

---

## How to Build and Run
### Prerequisites
- **C++11 or newer**
- A C++ compiler (e.g., `g++`)

### Build Steps
1. Navigate to the project directory:
   ```bash
   cd connect4/build
   ```
2. Compile the program using `Make` file:
   ```bash
   make
   ```
3. Run the compiled program:
   ```bash
   ./connect4
   ```

---

## How to Play
1. Start the program and configure the game:
   - Enter the board dimensions (rows and columns).
   - Choose whether to enable AI for Player 2.
   - If AI is enabled, specify the difficulty level (lookahead depth).

2. Players take turns entering the column number where they want to drop their piece.
   - Player 1: **X**
   - Player 2: **O** (or AI-controlled)

3. The game ends when a player connects 4 pieces in a row (horizontally, vertically, or diagonally) or when the board is full (draw).

---

## Key Classes
### 1. `Board`
- Manages the board state.
- Handles piece placement and removal.
- Detects win conditions and valid moves.

### 2. `Game`
- Manages the game loop and player turns.
- Interfaces with the `Board` and `AI` classes.

### 3. `AI`
- Implements a scoring system to evaluate board states.
- Uses a recursive lookahead strategy to make optimal moves.
- Supports configurable tiebreaker strategies (e.g., leftmost, rightmost, random).

---

## Example Gameplay
```
Welcome to Connect4!
Enter number of rows: 6
Enter number of columns: 7
Enable AI for Player 2? (y/n): y
Enter AI difficulty (lookahead depth): 3
Player 1's turn. Enter column: 3
Player 2 (AI) chooses column: 4
...
Player 1 wins!
```

---

## Future Enhancements
- Add a GUI for an improved user experience.
- Enhance the AI with smarter heuristics (e.g., Minimax with alpha-beta pruning).
- Add online multiplayer support.

---

## License
This project is open-source and available under the MIT License.


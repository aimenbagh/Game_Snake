# Game_Snake

A classic Snake game implemented in C using the Windows Console API. This project features a console-based interface with customizable difficulty levels and traditional snake gameplay mechanics.

## Table of Contents
- [Game\_Snake](#game_snake)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Controls](#controls)
  - [Difficulty Levels](#difficulty-levels)
  - [How to Play](#how-to-play)
  - [Technologies Used](#technologies-used)
    - [Programming Language:](#programming-language)
    - [Libraries:](#libraries)
    - [Tools:](#tools)
  - [Technical Details](#technical-details)
  - [Compilation](#compilation)
  - [Authors](#authors)

## Features

**Classic Snake Gameplay:**
 Control a snake that grows when it eats food while avoiding walls and its own tail.
 **Multiple Difficulty Levels:**
 Choose from Easy, Normal, and Hard modes with different game speeds.

**Score System:**
 Track your score as you collect food items.

**Smooth Controls:**
 Responsive keyboard controls using arrow keys or ZQSD (French AZERTY layout).

**Visual Appeal:**
 Uses custom border characters for a polished look.

## Controls

**Arrow Keys or ZQSD (AZERTY layout):**

- Up: ↑ Arrow or Z
- Down: ↓ Arrow or S
- Left: ← Arrow or Q
- Right: → Arrow or D

## Difficulty Levels

1. Easy: Slowest game speed (200ms delay)
2. Normal: Medium game speed (100ms delay)
3. Hard: Fastest game speed (50ms delay)

## How to Play

1. Run the executable to start the game
2. Use the menu to:
- Select "Play" to start the game
- Select "Difficult" to change difficulty level
- Select "Exit" to quit
3. Control the snake to eat food (& symbols)
4. Avoid hitting the walls (░ symbols) or your own tail (* symbols)
5. Try to achieve the highest score possible!

## Technologies Used

### Programming Language: 
- langage c

### Libraries:
- Standard C Libraries (stdlib.h, stdio.h)
- Windows API (windows.h)
- Console Input/Output (conio.h)

### Tools:
- Windows Console API for cursor manipulation
- Keyboard input handling
- Terminal/Console-based graphics

## Technical Details

- Built with standard C libraries
- Uses Windows API for console manipulation
- Implements snake movement logic with body segment tracking
- Features random food generation and initial direction selection
- Includes cursor hiding for a cleaner visual experience

## Compilation
Compile with any standard C compiler (e.g., GCC, MinGW):

```bash
gcc main.c -o snake.exe
```
Requirements
- Windows operating system
- C compiler with Windows API support

## Authors

- Baghdadi Nadjib Aimen 
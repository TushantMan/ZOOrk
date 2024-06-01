# ZOOrk - A Text-Based Adventure Game

ZOOrk is a text-based adventure game inspired by the classic game "Zork". It takes you on an exciting journey through a mysterious world filled with challenges, puzzles, and hidden treasures. Explore various locations, interact with objects and characters, and unravel the secrets of ZOOrk!

## Features

- Engaging text-based gameplay
- Multiple rooms and locations to explore
- Inventory system to collect and manage items
- Puzzles and challenges to solve
- Guide characters in each room to provide hints
- Intuitive command-based interface

## Getting Started

### Prerequisites

- C++ compiler (supporting C++20)
- CMake (version 3.23 or higher)

### Installation

1. Clone the repository:
   ```
   git clone https://github.com/TushantMan/ZOOrk.git
   ```

2. Navigate to the project directory:
   ```
   cd zoork
   ```

3. Create a build directory and navigate to it:
   ```
   mkdir build
   cd build
   ```

4. Generate the build files using CMake:
   ```
   cmake ..
   ```

5. Build the project:
   ```
   make
   ```

### Running the Game

1. From the build directory, run the game executable:
   ```
   ./ZOOrk
   ```

2. Follow the on-screen instructions and enjoy playing ZOOrk!

## Gameplay

- Use the `go <direction>` command to move between rooms (e.g., `go north`, `go east`).
- Use the `look <item>` or `inspect <item>` command to examine an item (e.g., `look key`, `look gem` ) or the current room description using `look ` or `inspect` command.
- Use the `take <item>` or `get <item>` command to pick up an item from the room.
- Use the `drop <item>` command to drop an item from your inventory.
- Use the `inventory`, `inv`, or `i` command to check your inventory.
- Use the `ask guide` command to ask the guide in the current room for a hint.
- Use the `quit` command to quit the game.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- Inspired by the classic game "Zork".
- Developed using C++ and CMake.

Enjoy playing ZOOrk and have a fantastic adventure!
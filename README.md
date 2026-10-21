# 🎮 cub3D

A 3D maze game built in C using raycasting and the MLX42 graphics library, inspired by classic first-person games.

## 📖 About the Project

**cub3D** is a graphics project from the 42 curriculum that explores the fundamentals of raycasting and 3D rendering.

The goal is to create a first-person perspective inside a maze using a 2D map. By calculating the distance between the player and walls, the program creates a 3D-like environment that the player can explore in real time.

This project provides hands-on experience with computer graphics, mathematical calculations, file parsing, and game development in C.

## ✨ Features

- **Raycasting:** Render a 3D perspective from a 2D map.
- **Texture Mapping:** Apply textures to walls to create a more realistic environment.
- **Map Parsing:** Read and process `.cub` configuration files.
- **Player Movement:** Navigate through the environment.
- **Graphics Programming:** Render and display a real-time game environment.
- **Memory Management:** Manage allocated resources and handle cleanup.
- **Modular Architecture:** Organize the implementation into reusable functions and components.

## 🛠️ Technologies

- **C** — Core programming language.
- **MLX42** — Graphics library.
- **Libft** — Custom C utility library.
- **Makefile** — Build automation.
- **Git** — Version control.

## 🚀 Getting Started

### Prerequisites

You will need:

- A C compiler.
- GNU Make.
- CMake.
- Git.
- The dependencies required by MLX42.

### Installation

Clone the repository:

```bash
git clone https://github.com/balhamad/cub3D.git
cd cub3D
```

### Compilation

Compile the project using:

```bash
make
```

### Running the Game

Launch the game with a valid `.cub` configuration file:

```bash
./cub3D test.cub
```

The configuration file defines the environment used to generate the game world.

## 🗺️ Map Configuration

The `.cub` file describes the environment, including its map layout and rendering configuration.

A typical configuration includes:

- Wall texture paths.
- Floor and ceiling colors.
- A map grid.
- The player's starting position and orientation.

The map represents the world in two dimensions, which the raycasting engine transforms into a first-person perspective.

## 📁 Project Structure

```text
cub3D/
├── MLX42/       # Graphics library
├── libft/       # Custom C utility library
├── src/         # Game implementation
├── textures/    # Texture assets
├── test.cub     # Example map configuration
└── Makefile     # Compilation rules
```

## 🧠 What I Learned

Working on cub3D helped me explore:

- The mathematics behind raycasting and 3D perspective.
- Graphics rendering and texture mapping.
- Parsing and validating structured configuration files.
- Managing memory and resources in C.
- Organizing a graphics project into modular components.
- Using mathematical concepts to create an interactive environment.

---

*Developed as part of the 42 programming curriculum.*

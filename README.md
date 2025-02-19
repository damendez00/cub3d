# Cub3D - A Raycasting Game

## Introduction
Cub3D is a 3D raycasting game inspired by Wolfenstein 3D, implemented using the MLX graphics library. The game features a first-person perspective with textured walls and basic movement controls.

## Technologies Used
- **MLX**: MiniLibX graphics library for rendering
- **Libft**: Custom C library for utility functions

## Core Concepts

### Raycasting
The game uses raycasting to create a 3D perspective from a 2D map. Key features include:
- Digital Differential Analyzer (DDA) algorithm for wall detection
- Calculation of wall distances and slice heights
- Handling of different wall orientations (North, South, East, West)

### Map Parsing
The game reads and validates map files with the following features:
- Custom .cub file format for map definition
- Wall and texture configuration
- Player starting position validation

### Rendering
The rendering process includes:
- MLX-based graphics pipeline
- Texture mapping for walls
- Continuous rendering loop for smooth gameplay

## Installation
1. Clone the repository
2. Run `make` to compile the project
3. Execute with `./cub3d maps/map1.cub`

## Usage
- **WASD**: Movement
- **Arrow Keys**: Camera rotation
- **ESC**: Exit game

## Screenshot
![Game Screenshot](#) *Placeholder for future screenshot*

## License
This project is licensed under the MIT License.

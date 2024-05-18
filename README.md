# Cube3D Project

![Cube3D Screenshot (ADD PHOTO)]()

**Welcome to the Cube3D Project, a venture into creating 3D game environments with raycasting technology, reminiscent of classic first-person shooters.**

## Table of Contents

<h3 align="center">
	<a href="#about">[About]</a>
	<span> · </span>
	<a href="#key-features">[Key Features]</a>
	<span> · </span>
	<a href="#gallery">[Gallery]</a>
	<span> · </span>
    <a href="#usage">[Usage]</a>
    <span> · </span>
	<a href="#controls">[Controls]</a>
    <span> · </span>
	<a href="#resources">[Resources]</a>
</h3>

## About

Cube3D, a part of the 42 school's challenging curriculum, requires students to craft a basic yet functional 3D game engine. This engine uses the C language and MiniLibX library to simulate a player navigating through a maze, employing a raycasting algorithm to render a pseudo-3D perspective.

## Index

### Project Objectives

The primary goals of the Cube3D project are:
- Develop a basic 3D game engine using C and MiniLibX.
- Implement raycasting technology to render a 3D maze from a first-person perspective.
- Create a user interface that includes real-time movements and camera adjustments.
- Equip the engine with basic game functionalities like texture mapping, sprite handling, and collision detection.

### Implemented Features

The current version of Cube3D boasts the following functionalities:
- Real-time navigation through a textured 3D maze.
- Ability to look around the maze using mouse or keyboard controls.
- Textured walls and sprite rendering to enhance the visual depth of the maze.
- Heads-Up Display (HUD) showing player stats including direction and current FPS.
- Responsive controls for movement and viewpoint adjustment.

### Non-Implemented Features

While Cube3D achieves many of its foundational goals, there are several features yet to be implemented:
- Network multiplayer functionality.
- Complex enemy AI behaviors.
- Advanced lighting and shadow effects.
- Support for loading multiple and larger map configurations.
- Additional optimization for higher frame rates on standard hardware.


## Gallery

![Cube3D Game View (ADD A PHOTO)]()

## Usage

### Instructions for Running the Game

**1. Compile and Launch**

To get started, compile and run the game using:

```shell
make all
./cube3D your_map.cub
```
Replace `your_map.cub` with the path to your custom map file. The map file defines the layout of the 3D environment, including the textures, sprite positions, and player starting position.

**2. Special Compiling Rules**

To compile the program with valgrind, run:

```shell
$ make leak
```

## Controls

- `↑` or 'w' : Move forward.
- `↓` or 's' : Move backward.
- `a` : Move left.
- `d` : Move right.
- `←` : Look left.
- `→` : Look right.
- `esc` : close program.

## Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/)
- [Cub3D Documentation](https://harm-smits.github.io/42docs/projects/cub3d)
- [Algorithm Cub3D](https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit?pli=1#heading=h.bd9zh49nig4r)
- [Cub3D Tutorial](http://forums.mediabox.fr/wiki/tutoriaux/flashplatform/affichage/3d/raycasting)
- [Lode Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Wolf Explications](https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/)

by [gberthol](https://github.com/Pastequeisntreal) & [mbrousse](https://github.com/maxdegers).
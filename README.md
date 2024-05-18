# Cube3D Project

![Cube3D Screenshot](https://i.imgur.com/o6p3z7t.png)

**Welcome to the Cube3D Project, a venture into creating 3D game environments with raycasting technology, reminiscent of classic first-person shooters.**

## Table of Contents

<h3 align="center">
	<a href="#overview">[Overview]</a>
	<span> · </span>
	<a href="#key-features">[Key Features]</a>
	<span> · </span>
	<a href="#gallery">[Gallery]</a>
	<span> · </span>
	<a href="#getting-started">[Getting Started]</a>
    <span> · </span>
	<a href="#controls">[Controls]</a>
    <span> · </span>
	<a href="#resources">[Resources]</a>
    <span> · </span>
	<a href="#authors">[Authors]</a>
</h3>

## Overview

Cube3D, a part of the 42 school's challenging curriculum, requires students to craft a basic yet functional 3D game engine. This engine uses the C language and MiniLibX library to simulate a player navigating through a maze, employing a raycasting algorithm to render a pseudo-3D perspective.

## Key Features

- Movement through a detailed maze environment textured to enhance depth perception.
- Camera controls that allow the player to look around in real-time.
- A dynamic heads-up display (HUD) that provides essential gameplay information such as current coordinates, view direction, and frame rate.
- Implementation of sprites within the game world to create a more immersive experience.

## Gallery

![Cube3D Game View](https://i.imgur.com/o6p3z7t.png)

## Getting Started

### Instructions for Running the Game

**1. Compile and Launch**

To get started, compile and run the game using:

```shell
make all
./cube3D your_map.cub
```
Replace `map.cub` with the path to your custom map file. The map file defines the layout of the 3D environment, including the textures, sprite positions, and player starting position.

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

## Authors

- [Arthur Ascedu](https://github.com/aascedu)
- [Thea Wang](https://github.com/Zwhea)
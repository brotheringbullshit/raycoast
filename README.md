# Raycoast

tried of making 2D games with SDL2 and now want to try something new like creating a raycast game with c?

well raycoast is the perfect libary for you!

Raycoast is a simple 2.5D raycasting library for creating raycasting games using SDL2.

## Features

- Basic raycasting engine
- Player movement and rotation
- Easy to use

## Installation
make the lib first with `make`
and now. use `sudo make install` to install the lib. now you can use it!

### Prerequisites

- SDL2 and SDL2_image (because you can use images and colors as the walls)
- A C compiler (e.g., GCC)

### Building the Library

1. Clone the repository:
   ```sh
   git clone https://github.com/botheringbullshit/raycoast.git
   cd raycoast

### How To Use Raycoast
now that you have the lib. it is time to use!

if you want to add. colored walls. it is easy too!

```c
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};
```

now the walls can be colors. using these numbers:
0 means white.
1 means blue.
2 means red.
3 means green.
4 means yellow.
5 means orange.
thats all the colors! yes thats the map too.

### enjoy!

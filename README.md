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

to set the map. you'll have to use:
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

If you feel in the mood to add textures or a color. this has it!
but you'll need SDL2_image or it'll not work.

insert

```c
SDL_Texture *loadTexture(const char *file, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, file);
    if (!texture) {
        fprintf(stderr, "IMG_LoadTexture Error: %s\n", IMG_GetError());
        return NULL;
    }
    return texture;
}

int main(int argc, char *argv[]) {
    if (!initializeSDL()) {
        return 1;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        fprintf(stderr, "IMG_Init Error: %s\n", IMG_GetError());
        closeSDL();
        return 1;
    }

    // Load textures
    SDL_Texture *textures[1];
    textures[0] = loadTexture("wall_texture.png", renderer);
    if (!textures[0]) {
        IMG_Quit();
        closeSDL();
        return 1;
    }
```

the "wall_texture.png" is supposed to be your wall image. while you can make the wall a color. it is basically like this:
```c
SDL_Texture *wallTextures[4];
    wallTextures[0] = loadTexture("wall_texture_red.png");
    wallTextures[1] = loadTexture("wall_texture_green.png");
    wallTextures[2] = loadTexture("wall_texture_blue.png");
    wallTextures[3] = NULL; // No texture for default walls

    // Define wall colors
    Wall walls[MAP_HEIGHT][MAP_WIDTH] = {
        {{false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255},
         {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[0]}, {true, wallTextures[3]}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {true, wallTextures[3]}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[3]}, {true, wallTextures[1]}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {true, wallTextures[3]}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]},
         {true, wallTextures[3]}, {false, 255, 255, 255}, {true, wallTextures[3]}, {false, 255, 255, 255}},
        {{false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255},
         {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}, {false, 255, 255, 255}}
```

so i recommend using the wall texture.

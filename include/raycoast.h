#ifndef RAYCOAST_H
#define RAYCOAST_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define TILE_SIZE 64
#define FOV 60
#define NUM_RAYS SCREEN_WIDTH

#define MOVE_SPEED 2.0
#define ROTATE_SPEED 2.0

typedef struct {
    Uint8 r, g, b; // RGB color values for the wall
} Wall;

typedef struct {
    float x;
    float y;
    float angle;
} Player;

bool initializeSDL();
void closeSDL();
void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
void castRays(Player *player, Wall walls[MAP_HEIGHT][MAP_WIDTH]);
void handleInput(Player *player, bool *quit);
void renderFrame(Player *player, Wall walls[MAP_HEIGHT][MAP_WIDTH]);

#endif // RAYCOAST_H

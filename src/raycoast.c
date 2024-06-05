#include "raycoast.h"
#include <math.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Raycoast Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              0);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

float dist(float ax, float ay, float bx, float by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

void castRays(Player *player, Wall walls[MAP_HEIGHT][MAP_WIDTH]) {
    float rayAngle = player->angle - (FOV / 2);
    float deltaAngle = (float)FOV / NUM_RAYS;

    for (int ray = 0; ray < NUM_RAYS; ray++) {
        float rayX = player->x;
        float rayY = player->y;
        float rayCos = cos(rayAngle * M_PI / 180.0);
        float raySin = sin(rayAngle * M_PI / 180.0);

        float distanceToWall = 0;
        bool hitWall = false;
        int wallType = 0;
        int mapX, mapY; // Declare mapX and mapY here

        while (!hitWall && distanceToWall < SCREEN_WIDTH) {
            rayX += rayCos;
            rayY += raySin;
            distanceToWall += 1;

            mapX = (int)(rayX / TILE_SIZE);
            mapY = (int)(rayY / TILE_SIZE);

            if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT) {
                if (walls[mapY][mapX].r != 255 || walls[mapY][mapX].g != 255 || walls[mapY][mapX].b != 255) {
                    hitWall = true;
                    wallType = mapX;
                }
            }
        }

        int wallHeight = (int)(SCREEN_HEIGHT / distanceToWall * TILE_SIZE);

        if (wallType >= 0 && wallType < MAP_WIDTH) {
            Uint8 r = walls[mapY][wallType].r;
            Uint8 g = walls[mapY][wallType].g;
            Uint8 b = walls[mapY][wallType].b;
            drawRect(ray, (SCREEN_HEIGHT - wallHeight) / 2, 1, wallHeight, r, g, b);
        }

        rayAngle += deltaAngle;
    }
}

void handleInput(Player *player, bool *quit) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_ESCAPE]) {
        *quit = true;
    }

    if (state[SDL_SCANCODE_W]) {
        player->x += MOVE_SPEED * cos(player->angle * M_PI / 180.0);
        player->y += MOVE_SPEED * sin(player->angle * M_PI / 180.0);
    }

    if (state[SDL_SCANCODE_S]) {
        player->x -= MOVE_SPEED * cos(player->angle * M_PI / 180.0);
        player->y -= MOVE_SPEED * sin(player->angle * M_PI / 180.0);
    }

    if (state[SDL_SCANCODE_A]) {
        player->angle -= ROTATE_SPEED;
    }

    if (state[SDL_SCANCODE_D]) {
        player->angle += ROTATE_SPEED;
    }
}

void renderFrame(Player *player, Wall walls[MAP_HEIGHT][MAP_WIDTH]) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Cast rays
    castRays(player, walls);

    // Update screen
    SDL_RenderPresent(renderer);
}

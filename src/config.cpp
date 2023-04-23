#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"

const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 360;

bool init(SDL_Window* window, SDL_Renderer* renderer)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error:\n" << SDL_GetError() << "\n";
        //printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    //Initialize SDL_Image
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "SDL_image could not initialize! SDL_image Error:\n" << IMG_GetError() << "\n";
        //printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    //Create a window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error:\n" << SDL_GetError() << "\n";
        //printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cout << "Renderer could not be created! SDL_Error:\n" << SDL_GetError() << "\n";
        //printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    return 0;

}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
    //Destroy renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, char* path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, path);
    return texture;
}

void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, SDL_RendererFlip flip, float resize)
{
    SDL_Rect dest1;
    dest1.x = 0;
    dest1.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &dest1.w, &dest1.h);

    SDL_Rect dest2;
    dest2.x = x;
    dest2.y = y;
    dest2.w = (int)dest1.w * resize;
    dest2.h = (int)dest1.h * resize;

    SDL_RenderCopyEx(renderer, texture, &dest1, &dest2, 0, NULL, flip);
}
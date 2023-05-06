#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "config.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 750;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
    if (window == nullptr)
    {
        std::cout << "Window could not be created! SDL_Error:\n" << SDL_GetError() << "\n";
        //printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "Renderer could not be created! SDL_Error:\n" << SDL_GetError() << "\n";
        //printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    return 0;

}

void close()
{
    //Destroy renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


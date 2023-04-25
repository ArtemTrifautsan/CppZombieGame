#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "config.h"

void mainLoop(SDL_Renderer* renderer);

int main(int argv, char** args)
{
    init();
    mainLoop(renderer);
    close();
    return 0;
}

void mainLoop(SDL_Renderer* renderer)
{
    bool runningGame = true;
    while (runningGame)
    {
        SDL_Delay(1000);
        std::cout << renderer << std::endl;
        std::cout << &renderer << std::endl;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) runningGame = false;
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) runningGame = false;

            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_a) std::cout << "A is pressed\n";
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x467, 0xf14, 0xaa4, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        SDL_Rect rect1 = { 10, 10, 50, 50 };
        SDL_RenderFillRect(renderer, &rect1);

        SDL_RenderPresent(renderer);
    }
}

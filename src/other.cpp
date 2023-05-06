#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "other.h"

SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, path.c_str());
    return texture;
}

void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, SDL_RendererFlip flip, float resize)
{
    SDL_Rect srcRest;
    srcRest.x = 0;
    srcRest.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &srcRest.w, &srcRest.h);

    SDL_Rect dstRest;
    dstRest.x = x;
    dstRest.y = y;
    dstRest.w = (int)srcRest.w * resize;
    dstRest.h = (int)srcRest.h * resize;

    SDL_RenderCopyEx(renderer, texture, &srcRest, &dstRest, 0, NULL, flip);
}

Timer::Timer() { this->startTime = -1; }

void Timer::start() { this->startTime = SDL_GetTicks(); }

void Timer::stop() { this->startTime = -1; }

void Timer::sleep(int ms) { SDL_Delay(ms); }

int Timer::getCurrentTime() { return (SDL_GetTicks() - this->startTime); }

int Timer::getStartTime() { return this->startTime; }

bool Timer::isRunning()
{
    if (this->startTime == -1) return false;
    else return true;
}
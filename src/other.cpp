#include <SDL.h>
#include <SDL_image.h>
#include "other.h"

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
#ifndef CONFIG_H
#define CONFIG_H


#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH;
const int SCREEN_HEIGHT;

bool init(SDL_Window* window, SDL_Renderer* renderer);
void close(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer, char* path);
void displayTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, SDL_RendererFlip flip, float resize);


#endif

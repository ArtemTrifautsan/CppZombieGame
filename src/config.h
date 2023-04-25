#ifndef CONFIG_H
#define CONFIG_H


#include <SDL.h>
#include <SDL_image.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

int init();
void close();
SDL_Texture* loadTexture(SDL_Renderer* renderer, char* path);
void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, SDL_RendererFlip flip, float resize);


#endif

#ifndef OTHER_H
#define OTHER_H


#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, SDL_RendererFlip flip, float resize);

class Timer {
public:
	Timer();
	void start();
	void stop();
	void sleep(int ms);
	int getCurrentTime();
	int getStartTime();
	bool isRunning();
private:
	int startTime;
};


#endif
#ifndef BUTTON_H
#define BUTTON_H


#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

class Button {
public:
	Button(SDL_Renderer* renderer, char* texturePath, int x, int y, int width, int height, std::string text);
	void draw();
	void hover();
	void click();
	void update(int mouseX, int mouseY);
private:
	int x, y, width, height;
	std::string state;
	std::string text;
	SDL_Texture* texture;
};


#endif
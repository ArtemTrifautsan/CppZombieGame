#include <SDL.h>
#include <SDL_image.h>

#include "button.h"
#include "../other.h"

Button::Button(SDL_Renderer* renderer, char* texturePath, int x, int y, int width, int height, std::string text)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->text = text;
	this->state = "none";
	this->texture = loadTexture(renderer, texturePath);
}
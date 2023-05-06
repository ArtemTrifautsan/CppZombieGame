#include <SDL.h>
#include <SDL_image.h>
#include "menu.h"
#include "button.h"
#include "../other.h"

Menu::Menu(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	this->state = "run";
	this->backgroundTexture = loadTexture(renderer, "images/UI/backgroundMenu.png");
	//this->createButtons();
}

void Menu::run()
{
	this->handleEvents();
	this->draw();
}

void Menu::draw()
{
	// Cleare screen
	SDL_SetRenderDrawColor(renderer, 0x467, 0xf14, 0xaa4, 0x00);
	SDL_RenderClear(renderer);

	// Draw background
	drawTexture(this->renderer, this->backgroundTexture, 0, 0, SDL_FLIP_NONE, 1);

	SDL_RenderPresent(renderer);
}

void Menu::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) { this->state = "quit"; }
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) { this->state = "quit"; }

		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_a) {}
		}
	}
}

std::string Menu::getState() { return this->state; }
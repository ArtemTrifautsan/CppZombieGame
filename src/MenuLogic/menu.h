#ifndef MENU_H
#define MENU_H


#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "button.h"
#include "../other.h"

class Menu {
public:
	Menu(SDL_Renderer* renderer);
	void run();
	void draw();
	std::string getState();
	void handleEvents();
	void choseWeapon();
	void choseSkin();
	void getChosenWeapons();
	void getChosenSkins();
private:
	SDL_Renderer* renderer = nullptr;
	std::string state;
	SDL_Texture* backgroundTexture;
	Timer timer;
	std::vector<Button> buttons;
	std::vector<int> chosenWeapons;
	std::vector<int> chosenSkins;

	void createButtons();
	void drawButtons();
};


#endif

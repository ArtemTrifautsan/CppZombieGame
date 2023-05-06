#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include "config.h"
#include "other.h"
#include "MenuLogic/menu.h"

void mainLoop();
void tickFPS(Timer timer, int FPS);

int main(int argv, char** args)
{
    init();
    mainLoop();
    close();
    return 0;
}

void mainLoop()
{
    Timer timer;
    timer.start();

    Menu menu(renderer);

    bool runningGame = true;
    while (runningGame)
    {
        // Menu processing
        std::string menuState = menu.getState();
        if (menuState == "run") menu.run();
        else if (menuState == "close")
        {
            // This is where the game round will start
        }
        else if (menuState == "quit") runningGame = false;

        tickFPS(timer, 60);
    }
}

void tickFPS(Timer timer, int FPS)
{
    if (timer.getCurrentTime() < (1000 / FPS))
    {
        timer.sleep(1000 / FPS - timer.getCurrentTime());
        timer.start();
    }
    else timer.start();
}
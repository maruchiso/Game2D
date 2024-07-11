#pragma once
#include "Object.h"
#include <iostream>
#include <SDL.h>
#include <map>
#include "const.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	void handleEvent(SDL_Event& e);
	void update(char direction);
	void render(SDL_Renderer* ren);
	SDL_Rect getPlayer();
	


private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;

};

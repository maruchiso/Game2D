#pragma once
#include <SDL.h>
#include "Player.h"
class Tear
{
public:
	Tear(int x, int y, int w, int h);
	void update();
	void render(SDL_Renderer* ren);
	

private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	int tearSpeed = 20;
	int radius = 5;
};


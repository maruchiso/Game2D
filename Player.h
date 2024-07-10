#pragma once
#include <iostream>
#include <SDL.h>
#include "Player.h"
#include "const.h"
#include "Object.h"
#include <map>
#include "ColisionSystem.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	void handleEvent(SDL_Event& e, bool colision);
	void update();
	void render(SDL_Renderer* ren);
	std::map<char, int> getPosition();
	
	

private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	
};


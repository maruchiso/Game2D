#pragma once
#include "lib.h"
#include "dynamic_lib.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	void handleEvent(SDL_Event& e);
	void update();
	void render(SDL_Renderer* ren);
	std::map<char, int> getPosition();
	void checkColisionWithObject(Object& object, colisionDirection isColision);


private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;

};


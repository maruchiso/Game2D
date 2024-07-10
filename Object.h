#pragma once
#include "lib.h"

class Object
{
public:
	Object(int x, int y, int w, int h);
	void render(SDL_Renderer* ren);
	std::map <char, int> getPosition();

private:
	SDL_Rect rect;

};


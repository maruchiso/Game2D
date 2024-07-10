#pragma once
#include <iostream>
#include <SDL.h>
#include "Player.h"
#include "const.h"
#include "Object.h"
#include <map>
#include "ColisionSystem.h"
Object::Object(int x, int y, int w, int h) : rect{ x, y, w, h } {};

void Object::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	SDL_RenderFillRect(ren, &rect);
}

std::map<char, int> Object::getPosition() {
	std::map<char, int> position;
	position['x'] = rect.x;
	position['y'] = rect.y;
	position['h'] = rect.h;
	position['w'] = rect.w;

	return position;
}
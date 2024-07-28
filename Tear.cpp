#include "Tear.h"
#include "lib.h"
#include "dynamic_lib.h"
#include "Player.h"

Tear::Tear(int x, int y, int w, int h) : rect {x, y, w, h}, xVelocity(0), yVelocity(0) {}

void Tear::update() {
	rect.x += xVelocity;
	rect.y += yVelocity;
}

void Tear::render(SDL_Renderer* ren){
	SDL_SetRenderDrawColor(ren, 0, 0, 175, 255);
	SDL_RenderFillRect(ren, &rect);
}


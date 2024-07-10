#pragma once
#include <iostream>
#include <SDL.h>
#include "Player.h"
#include "const.h"
#include "Object.h"
#include <map>
#include "ColisionSystem.h"

Player::Player(int x, int y, int w, int h) : rect{x, y, w, h}, xVelocity(0), yVelocity(0) {}

void Player::handleEvent(SDL_Event& e, bool colision) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0 && !colision) {
		
		switch (e.key.keysym.sym) {
		case SDLK_UP: yVelocity -= 10;  break;
		case SDLK_DOWN: yVelocity += 10; break;
		case SDLK_RIGHT: xVelocity += 10; break;
		case SDLK_LEFT: xVelocity -= 10; break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0 && !colision) {
		
		switch (e.key.keysym.sym) {
		case SDLK_UP: yVelocity += 10; break;
		case SDLK_DOWN: yVelocity -= 10; break;
		case SDLK_RIGHT: xVelocity -= 10; break;
		case SDLK_LEFT: xVelocity += 10; break;
		}
	}
}
//TODO: Width and Height not hardcode
void Player::update() {
	rect.x += xVelocity;
	rect.y += yVelocity;

	if (rect.x < 0) rect.x = 0;
	if (rect.x + rect.w > WINDOW_WIDTH) rect.x = WINDOW_WIDTH - rect.w;
	if (rect.y < 0) rect.y = 0;
	if (rect.y + rect.h > WINDOW_HEIGHT) rect.y = WINDOW_HEIGHT - rect.h;

}

void Player::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
	SDL_RenderFillRect(ren, &rect);
}
/* tu jest coœ nie tak 
void Player::checkColision(Object& object) {
	std::map<char, int> position = object.getPosition();
	int xceterPlayer = rect.w / 2 + rect.x;
	int xcenterObject = position['w'] / 2 + position['x'];
	//check right side
	if (rect.x + rect.w + position['x'] <= xcenterObject + xceterPlayer) isColision = true;
	else isColision = false;
}
*/

std::map<char, int> Player::getPosition() {
	std::map<char, int> position;
	position['x'] = rect.x;
	position['y'] = rect.y;
	position['w'] = rect.w;
	position['h'] = rect.h;

	return position;
}

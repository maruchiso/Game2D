#include "Player.h"
#include "lib.h"
#include "dynamic_lib.h"

Player::Player(int x, int y, int w, int h) : rect{ x, y, w, h }, xVelocity(0), yVelocity(0) {}

void Player::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP:    yVelocity -= 10; break;
		case SDLK_DOWN:  yVelocity += 10; break;
		case SDLK_RIGHT: xVelocity += 10; break;
		case SDLK_LEFT:  xVelocity -= 10; break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP:    yVelocity += 10; break;
		case SDLK_DOWN:  yVelocity -= 10; break;
		case SDLK_RIGHT: xVelocity -= 10; break;
		case SDLK_LEFT:  xVelocity += 10; break;
		}
	}
}

void Player::update(char direction) {
	
	if (xVelocity > 0 && direction != 'R'){
		rect.x += xVelocity;
		rect.y += yVelocity;
	}
	else if (xVelocity < 0 && direction != 'L') {
		rect.x += xVelocity;
		rect.y += yVelocity;
	}
	else if (yVelocity > 0 && direction != 'D') {
		rect.x += xVelocity;
		rect.y += yVelocity;
	}
	else if (yVelocity < 0 && direction != 'U'){
		rect.x += xVelocity;
		rect.y += yVelocity;
	}
	if (rect.x < 0) rect.x = 0;
	if (rect.x + rect.w > WINDOW_WIDTH) rect.x = WINDOW_WIDTH - rect.w;
	if (rect.y < 0) rect.y = 0;
	if (rect.y + rect.h > WINDOW_HEIGHT) rect.y = WINDOW_HEIGHT - rect.h;

}

void Player::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
	SDL_RenderFillRect(ren, &rect);
}


SDL_Rect Player::getPlayer() {
	return rect;
}
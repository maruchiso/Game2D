#include "Player.h"

Player::Player(int x, int y, int w, int h) : rect{ x, y, w, h }, xVelocity(0), yVelocity(0) {}

void Player::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP: if (canMoveUp) yVelocity -= 10;  break;
		case SDLK_DOWN: if (canMoveDown) yVelocity += 10; break;
		case SDLK_RIGHT: if (canMoveRight) xVelocity += 10; break;
		case SDLK_LEFT: if (canMoveLeft) xVelocity -= 10; break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP: yVelocity += 10; break;
		case SDLK_DOWN: yVelocity -= 10; break;
		case SDLK_RIGHT: xVelocity -= 10; break;
		case SDLK_LEFT: xVelocity += 10; break;
		}
	}
}

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

std::map<char, int> Player::getPosition() {
	std::map<char, int> position;
	position['x'] = rect.x;
	position['y'] = rect.y;
	position['w'] = rect.w;
	position['h'] = rect.h;

	return position;
}

void Player::checkColisionWithObject(Object& object, colisionDirection isColision) {

	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;
	canMoveUp = true;

	if (isColision == LEFT) canMoveLeft = false;
	else if (isColision == RIGHT) canMoveRight = false;
	else if (isColision == UP) canMoveUp = false;
	else if (isColision == DOWN) canMoveDown = false;
}
#include "Player.h"
#include "lib.h"
#include "dynamic_lib.h"



Player::Player(int x, int y, int w, int h) : rect{ x, y, w, h }, xVelocity(0), yVelocity(0) {}

void Player::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP:    yVelocity -= playerSpeed; break;
		case SDLK_DOWN:  yVelocity += playerSpeed; break;
		case SDLK_RIGHT: xVelocity += playerSpeed; break;
		case SDLK_LEFT:  xVelocity -= playerSpeed; break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP:    yVelocity += playerSpeed; break;
		case SDLK_DOWN:  yVelocity -= playerSpeed; break;
		case SDLK_RIGHT: xVelocity -= playerSpeed; break;
		case SDLK_LEFT:  xVelocity += playerSpeed; break;
		}
	}
}


void Player::update(std::vector<char> directionList) {

	
		if (std::find(directionList.begin(), directionList.end(), 'R') != directionList.end()) {
			if (xVelocity < 0) rect.x += xVelocity;
			rect.y += yVelocity;
		}
		else if (std::find(directionList.begin(), directionList.end(), 'L') != directionList.end()) {
			if (xVelocity > 0) rect.x += xVelocity;
			rect.y += yVelocity;
		}
		else if (std::find(directionList.begin(), directionList.end(), 'D') != directionList.end()) {
			if (yVelocity < 0) rect.y += yVelocity;
			rect.x += xVelocity;
		}
		else if (std::find(directionList.begin(), directionList.end(), 'U') != directionList.end()) {
			if (yVelocity > 0) rect.y += yVelocity;
			rect.x += xVelocity;
		}
		else {
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

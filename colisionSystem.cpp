#include "colisionSystem.h"

colisionDirection isColision(Player& player, Object& object) {
	std::map<char, int> playerPosition = player.getPosition();
	std::map<char, int> objectPosition = object.getPosition();

	if (objectPosition['x'] + objectPosition['w'] >= playerPosition['x'] &&
		playerPosition['x'] + playerPosition['w'] >= objectPosition['x'] &&
		objectPosition['y'] + objectPosition['h'] >= playerPosition['y'] &&
		playerPosition['y'] + playerPosition['h'] >= objectPosition['y']) {

		//find center coords and detrmine direction of colision
		int playerCenterX = playerPosition['x'] + playerPosition['w'] / 2;
		int playerCenterY = playerPosition['y'] + playerPosition['h'] / 2;
		int objectCenterX = objectPosition['x'] + objectPosition['w'] / 2;
		int objectCenterY = playerPosition['y'] + playerPosition['h'] / 2;

		int diffrenceX = playerCenterX - objectCenterX;
		int diffrenceY = playerCenterY - objectCenterY;

		int absdX = std::abs(diffrenceX);
		int absdY = std::abs(diffrenceY);

		if (absdX > absdY) {
			if (diffrenceX > 0) return LEFT;
			else return RIGHT;
		}
		else {
			if (diffrenceY > 0) return UP;
			else return DOWN;
		}
	}

	return NONE;

}
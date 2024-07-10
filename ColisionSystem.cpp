#pragma once
#include <iostream>
#include <SDL.h>
#include "Player.h"
#include "const.h"
#include "Object.h"
#include <map>
#include "ColisionSystem.h"

bool isColision(Player& player, Object& object) {
	std::map<char, int> playerPosition = player.getPosition();
	std::map<char, int> objectPosition = object.getPosition();

	if (objectPosition['x'] + objectPosition['w'] >= playerPosition['x'] &&
		playerPosition['x'] + playerPosition['w'] >= objectPosition['x'] &&
		objectPosition['y'] + objectPosition['h'] >= playerPosition['y'] &&
		playerPosition['y'] + playerPosition['h'] >= objectPosition['y']) return true;
	else return false;
}
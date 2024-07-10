#pragma once
#include "dynamic_lib.h"

enum colisionDirection {UP, DOWN, LEFT, RIGHT, NONE};

colisionDirection isColision(Player& player, Object& object);
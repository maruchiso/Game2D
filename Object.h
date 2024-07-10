#pragma once
#include <iostream>
#include <SDL.h>
#include "Player.h"
#include "const.h"
#include "Object.h"
#include <map>
#include "ColisionSystem.h"

class Object 
{
public:
    Object(int x, int y, int w, int h);
    void render(SDL_Renderer* ren);
    std::map<char, int> getPosition();

private:
    SDL_Rect rect;
};


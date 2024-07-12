# 2D Game Engine
Basically I want to make a metroidvania game something like Blasphemous without any game engine using only SDL
Etaps:
1. Collsion System
2. Player Mechanics
3. Objects
4. Simple levels
5. Fighting system
6. ......

Game concept:
player has to move/jump on the platforms to avoid "opponents". I am thinking about moving whole scene rather than moving a character (something like geometry dash?). Player has 3 tries (hearths), if player touch ground or opponents, he will lose 1 hearth. Maybe add fighting system.

Now I have collision system (thanks Andrzej for helping:P)
Now i want to generate objects(plataforms), then i needed to modify collision sytem to checking collision between multiple objects and player (not only one!).

I find the bug, if the object is not a square, the collsion is not working properly, it's because my collision system depends on poor center points comparison. Sadly i have to change collision system:(

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include "Game.h"

#include "GameController.h"
#include "Common.h"
#include <string>
#include <streambuf>
#include <iostream>
#include <sstream>

/////////////////////////////////////////////////////////////////////////////////////////////////
// GraphicObject: Draw, Show...
// AstBase, Triangle, Rectangle, ...
//Gun, Laser, Rocket

// Factory: random generating of enemies.

/////////////////////////////////////////////////////////////////////////////////////////////////


// Game Regime: menu, Game

// Keys handler
// LevelGenerator... ?

// GraphicObject: Draw, Show...
// AstBase, Triangle, Rectangle, ...
// WeaponBase, Gun, Laser, Rocket



int main(int argc, char** argv)
{
	

	if (!Game::NewGame(argc, argv))
	{
		return -1;


	}

	if (!Game::HaltGame())
	{
		return -1;
	}

	return 0;


}




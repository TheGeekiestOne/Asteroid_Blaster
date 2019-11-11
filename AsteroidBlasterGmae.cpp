
/*ASTEROID BLASTER- An Object Oriented approach to ASteroids game.
Copyright (C) 2019  - Ayran Olckers aka The Geekiest One
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

//Asteroids is a space - themed multidirectional shooter arcade game 
//designed by Lyle Rains, Ed Logg, and Dominic Walshand released in 
//November 1979 by Atari, Inc.The player controls a single spaceship 
//in an asteroid field which is periodically traversed by flying saucers

#include <string.h>
#include "Game.h"
#include "Common.h"
//#include "Menu.h"
/// 
/// 
/// 
Game* Game::_playerInstance = 0;


/// 
/// Main game function to call everything in initiate the game instance
/// 
Game::Game(int windowNumber)
{
	_playerController = new GameController(windowNumber);



}

/// 
/// 
/// 
Game::~Game()
{
	if (_playerController != 0)
	{
		delete _playerController;
		_playerController = 0;
	}
}

/// 
/// 
/// 
bool Game::NewGame(int argc, char** argv)
{
	// Don't let halt current Game. Only if user knows what he does by hald_Game().
	if (_playerInstance == 0 && IsGameFinished())
	{
		_playerInstance = new Game(_InitDisplay(argc, argv));

		bool result = _playerInstance != 0;

		if (result)
		{
			_InitHandlers();

			_playerInstance->_playerController->Initialize();
		}

		return result;
	}
	else
	{
		return false;
	}
}

/// 
/// Window size and titles
/// 
int Game::_InitDisplay(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	

	if (argc > 1 && !strcmp(argv[1], "-fullscreen"))
	{
		// Simply create window in fullscreen mode.
		glutGameModeString("640x640:16@60");
		return glutEnterGameMode(); // Need return? Or just 0?
	}
	else
	{
		glutInitWindowSize(640, 640);

		return glutCreateWindow("AsteroidBlaster-v1.0 - Created by Ayran Olckers (The Geekiest One)");


		
	}

	

}

//
// Links handlers.
//
void Game::_InitHandlers()
{
	glutIgnoreKeyRepeat(1);

	glutKeyboardFunc(&Game::KeyPressed);
	glutSpecialFunc(&Game::SpecialKeyPressed);
	glutSpecialUpFunc(&Game::SpecialKeyUpPressed);
	glutDisplayFunc(&Game::Display);
	glutVisibilityFunc(&Game::Visible);


}

/// 
/// Checks to see if the game finished - Not working
/// 
bool Game::IsGameFinished()
{
	if (_playerInstance != 0 && _playerInstance->_playerController != 0)
	{
		return !_playerInstance->_playerController->IsInitialized();
	}

	return true;
}

/// 
/// this should pause the game, but not working
/// 
bool Game::HaltGame()
{
	bool result = _playerInstance != 0;

	if (result)
	{
		delete _playerInstance;
		_playerInstance = 0;
	}

	return result;
}

/// 
/// 
/// 
void Game::KeyPressed(unsigned char key, int px, int py)
{
	_playerInstance->_playerController->KeyPressed(key, px, py);
}

/// 
/// 
/// 
void Game::SpecialKeyPressed(int key, int x, int y)
{
	_playerInstance->_playerController->SpecialKeyPressed(key, x, y);
}

/// 
/// 
/// 
void Game::SpecialKeyUpPressed(int key, int x, int y)
{
	_playerInstance->_playerController->SpecialKeyUpPressed(key, x, y);
}



/// 
/// 
/// 
void Game::Display()
{
	_playerInstance->_playerController->Display();

	
}



/// 
/// 
/// 
void Game::Update()
{
	_playerInstance->_playerController->Update();
	 

}

/// 
/// 
/// 
void Game::Visible(int vis)
{
	if (vis == GLUT_VISIBLE)
	{
		//if (!paused) {
		glutIdleFunc(&Game::Update);
		//}
	}
	else
	{
		glutIdleFunc(NULL);
	}
}


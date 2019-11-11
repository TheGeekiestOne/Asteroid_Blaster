
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

#include <string.h>
#include "Game.h"
#include "Common.h"
//#include "Menu.h"
/// 
/// 
/// 
Game* Game::_pInstance = 0;


/// 
/// Main game function to call everything in initiate the game instance
/// 
Game::Game(int windowNumber)
{
	_pController = new GameController(windowNumber);



}

/// 
/// 
/// 
Game::~Game()
{
	if (_pController != 0)
	{
		delete _pController;
		_pController = 0;
	}
}

/// 
/// 
/// 
bool Game::NewGame(int argc, char** argv)
{
	// Don't let halt current Game. Only if user knows what he does by hald_Game().
	if (_pInstance == 0 && IsGameFinished())
	{
		_pInstance = new Game(_InitDisplay(argc, argv));

		bool result = _pInstance != 0;

		if (result)
		{
			_InitHandlers();

			_pInstance->_pController->Initialize();
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
	if (_pInstance != 0 && _pInstance->_pController != 0)
	{
		return !_pInstance->_pController->IsInitialized();
	}

	return true;
}

/// 
/// this should pause the game, but not working
/// 
bool Game::HaltGame()
{
	bool result = _pInstance != 0;

	if (result)
	{
		delete _pInstance;
		_pInstance = 0;
	}

	return result;
}

/// 
/// 
/// 
void Game::KeyPressed(unsigned char key, int px, int py)
{
	_pInstance->_pController->KeyPressed(key, px, py);
}

/// 
/// 
/// 
void Game::SpecialKeyPressed(int key, int x, int y)
{
	_pInstance->_pController->SpecialKeyPressed(key, x, y);
}

/// 
/// 
/// 
void Game::SpecialKeyUpPressed(int key, int x, int y)
{
	_pInstance->_pController->SpecialKeyUpPressed(key, x, y);
}



/// 
/// 
/// 
void Game::Display()
{
	_pInstance->_pController->Display();

	
}



/// 
/// 
/// 
void Game::Update()
{
	_pInstance->_pController->Update();
	 

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


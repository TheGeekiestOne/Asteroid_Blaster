#pragma once
#ifndef __gamecontroller_h__
#define __gamecontroller_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include <vector>
#include "Player.h"
#include "AsteroidDust.h"
#include "Asteroid.h"
#include "Score.h"

// Manage all the game resources and logic.

class GameController
{
public:
	// Constructor.
	GameController(int windowNumber);
	// Clears resources.
	virtual ~GameController();

	// Initializes current instance of the game.
	void Initialize();
	// Determines is game initialized.
	bool IsInitialized();

	// Handles key presses.
	void KeyPressed(unsigned char key, int px, int py);
	// Handles key presses of Arrow buttons, F1, F2, etc.
	void SpecialKeyPressed(int key, int x, int y);
	// Handles key Up presses of Arrow buttons, F1, F2, etc.
	void SpecialKeyUpPressed(int key, int x, int y);
	// Draws all parts of the game.
	void Display();
	// Updates all the game logic during OpenGL Idle time.
	void Update();

private:
	// Initializes display to show game.
	void _InitDisplay();
	// Updates logic related to asteroids.
	void _UpdateAsteroids(int time);
	// Solves all collisions between player, asteroids and rockets.
	void _SolveCollisions();
	// Shows initial screen.
	void _ShowInitialScreen();
	// Show information screen.
	void _ShowStatistics();

	void DrawBox();
	void DrawGrid();

private:
	// Windows.
	int _originalWindow;
	int _currentWindow;
	//
	int _cursor;
	// Player data.
	Player* _player;

	// Some time intervals using for live/visibility time.
	int _initialAppearInterval;
	int _enemyAppearInterval;
	int _lastAppearTime;

	// control of states.
	bool _isInitialState;
	bool _isGameState;

	// name score
	Statistics _statistics;

	// Collection of dust (ast trash) objects.
	std::vector<AsteroidDust*> _dust;
	// Collection of enemies itself: asteroids.
	std::vector<Asteroid*> _asteroids;
};

#endif /* __gamecontroller_h__ */


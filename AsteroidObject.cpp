/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include "AsteroidObject.h"
#include "Common.h"

//
AsteroidObject::AsteroidObject()
{
	_angle = 0;
	_distance = 0;
	_x = 0;
	_y = 0;
	_lastTime = glutGet(GLUT_ELAPSED_TIME);
	_movementType = 0;
}

//
float AsteroidObject::_GetInitialDistance()
{
	return sqrt(2 * pow(ORTHO_MAX_D / 2, 2));
}

//
float AsteroidObject::_GetRandomAngle()
{
	return _GetRandomNumber(360);
}

//
int AsteroidObject::_GetRandomTypeOfMovement()
{
	return (int)_GetRandomNumber(3); // 3 types of movement
}

//
float AsteroidObject::_GetRandomNumber(int max)
{
	static int inc = 10;
	srand(time(NULL) - inc);

	float result = rand() % max;

	inc -= result * 10;

	return result;
}

//
float AsteroidObject::GetX()
{
	return _x;
}

//
float AsteroidObject::GetY()
{
	return _y;
}
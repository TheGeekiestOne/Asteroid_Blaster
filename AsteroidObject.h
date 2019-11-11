#pragma once
#ifndef __baseenemy_h__
#define __baseenemy_h__
/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/


// 
// Base asteroid object with necessary common functions and fields.
// 
class AsteroidObject
{
public:
	AsteroidObject();

	float GetX();
	float GetY();

	//
	virtual float GetOuterRadius() = 0;

protected:
	// 
	float _GetInitialDistance();
	// 
	float _GetRandomAngle();
	// 
	int _GetRandomTypeOfMovement();
	//
	float _GetRandomNumber(int max);
	// 
	float _angle;
	float _distance;
	float _x;
	float _y;
	int _lastTime;
	int _movementType;
};

#endif /* __baseenemy_h__ */
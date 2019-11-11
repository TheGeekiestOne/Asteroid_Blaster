#pragma once
#ifndef __enemydust_h__
#define __enemydust_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include "GraphicObject.h"
#include "AsteroidObject.h"

// 
// class for the asteroid dust particles that fire in a circle after the asteroid is destroyed.
// 
class AsteroidDust : public AsteroidObject, public GraphicObject
{
public:
	// 
	AsteroidDust(void);
	// 
	virtual ~AsteroidDust();
	// 
	virtual void Draw();
	// 
	virtual void Update(int time, int delta = 0);
	//
	virtual float GetOuterRadius();
};

#endif /* __enemydust_h__ */
#pragma once
#ifndef __bullet_h__
#define __bullet_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

//Class for the bullet fired by the ship
struct Bullet
{
	//constant varialble names 
	bool inuse;

	float x;
	float y;

	float v;
	float xv;
	float yv;

	int expire;
};

#endif /* __bullet_h__ */


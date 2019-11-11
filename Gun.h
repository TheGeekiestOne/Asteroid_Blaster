#pragma once
#ifndef __machinegun_h__
#define __machinegun_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include <vector>
#include "Bullet.h"
#include "GraphicObject.h"
#include "Position.h"
#include "Asteroid.h"

/// 
/// class for the Gun, which calls the bullet to the ship
/// 
class Gun : public GraphicObject
{
public:
	Gun();
	virtual void Draw();
	virtual void Update(int time, int delta);
	void MakeShot(int time, Position playerPosition);
	bool IsDamagedByBullets(Asteroid* ast);

private:
	//get bullet
	int _GetBulletToShow(void);
	//initiate the bullet on fire
	void _InitBullet(int i, int time, Position playerPosition);

	std::vector<Bullet> _bullets;
};

#endif /* __machinegun_h__ */


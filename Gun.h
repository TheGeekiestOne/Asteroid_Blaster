#pragma once
#ifndef __machinegun_h__
#define __machinegun_h__

#include <vector>
#include "Bullet.h"
#include "GraphicObject.h"
#include "Position.h"
#include "Asteroid.h"

/// 
/// 
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
	int _GetBulletToShow(void);
	void _InitBullet(int i, int time, Position playerPosition);

	std::vector<Bullet> _bullets;
};

#endif /* __machinegun_h__ */


#pragma once
#ifndef __player_h__
#define __player_h__

#include "Gun.h"
#include "GraphicObject.h"
#include "Position.h"
#include "Asteroid.h"

/// 
/// 
/// 
class Player : public GraphicObject
{
public:
	// 
	Player();

	virtual void Draw();
	virtual void Update(int time, int delta = 0);

	void RestorePosition();
	void SpecialKeyPressed(int key, int time);
	void SpecialKeyUpPressed(int key);
	void MakeShot(int time);
	Position* GetPosition();
	bool IsHit(Asteroid* ast);
	bool IsDamagedByAst(Asteroid* ast);

private:
	int _left;
	int _leftTime;
	int _right;
	int _rightTime;
	int _thrust;
	int _thrustTime;
	int _back;
	int _backTime;

	int _lastTime;
	Position _position;
	float _v;

	int _currentWeapon;

	Gun* _BlasterGun;
};

#endif /* __player_h__ */


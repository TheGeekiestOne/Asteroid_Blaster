
#include "Player.h"
#include "Common.h"

// 
Player::Player()
{
	// Default weapon.
	_BlasterGun = new Gun();

	_position.x = ORTHO_MAX / 2;
	_position.y = ORTHO_MAX / 2;

	_left = 0;
	_leftTime = 0;
	_right = 0;
	_rightTime = 0;
	_thrust = 0;
	_thrustTime = 0;
	_back = 0;
	_backTime = 0;

	_lastTime = 0;
	_position.xv = 0;
	_position.yv = 0;
	_v = 0;

	_position.angle = 0.0;
}

// Draw player ship
void Player::Draw()
{
	//float rad;

	glPushMatrix();
	glTranslatef(_position.x, _position.y, 0.0);
	glRotatef(_position.angle, 0.0, 0.0, 1.0);

	if (_thrust)
	{	//thruster properties 
		glColor3f(1.0, 0.0, 0.0); //red
		glBegin(GL_LINE_STRIP);
		glVertex2f(-0.75, -0.5);
		glVertex2f(-1.75, 0);
		glVertex2f(-0.75, 0.5);
		glEnd();
	}

	glColor3f(1.0, 1.0, 0.0); //yellow

	// TODO Use stipples.
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.0, 0.0);
	glVertex2f(-1.0, -1.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-1.0, 1.0);
	glVertex2f(2.0, 0.0);
	glEnd();

	glPopMatrix();

	// Draw any other parts.

	if (_BlasterGun != 0)
	{
		_BlasterGun->Draw();
	}
}

// physics of ship
void Player::Update(int time, int delta)
{
	if (_left)
	{
		delta = time - _leftTime;
		_position.angle = _position.angle + delta * 0.4;
		_leftTime = time;
	}
	if (_right)
	{
		delta = time - _rightTime;
		_position.angle = _position.angle - delta * 0.4;
		_rightTime = time;
	}
	if (_thrust)
	{

		delta = time - _thrustTime;
		_v = delta * 0.00004;
		_position.xv = _position.xv + cos(_position.angle * M_PI / 180.0) * _v;
		_position.yv = _position.yv + sin(_position.angle * M_PI / 180.0) * _v;
		_thrustTime = time;
	}

	delta = time - _lastTime;
	float x = _position.x + _position.xv * delta;
	x = x / ORTHO_MAX_D;
	x = (x - floor(x)) * ORTHO_MAX_D;

	if (x < 1 || x > ORTHO_MAX_D - 1)
	{
		//_position.xv = -_position.xv;  // < ---- MODE 2. Remove this lines and your ship will be in continuos without side limits.

		x = _position.x + _position.xv * delta;
		x = x / ORTHO_MAX_D;
		x = (x - floor(x)) * ORTHO_MAX_D;

		//_position.xv = 0;  // < ---- MODE 1. Remove this and your ship will bump up like a crazy =).
	}

	float y = _position.y + _position.yv * delta;
	y = y / ORTHO_MAX_D;
	y = (y - floor(y)) * ORTHO_MAX_D;

	if (y < 1 || y > ORTHO_MAX_D - 1)
	{
		//_position.yv = -_position.yv;  // < ---- MODE 2

		y = _position.y + _position.yv * delta;
		y = y / ORTHO_MAX_D;
		y = (y - floor(y)) * ORTHO_MAX_D;

		//_position.yv = 0;  // < ---- MODE 1
	}

	_position.x = x;
	_position.y = y;

	_lastTime = time;

	// Update other parts

	if (_BlasterGun != 0)
	{
		_BlasterGun->Update(time, delta);
	}
}

// 
void Player::RestorePosition()
{
	_position.x = ORTHO_MAX / 2;
	_position.y = 0;
	_position.xv = 0;
	_position.yv = 0;
}

// 
void Player::SpecialKeyPressed(int key, int time)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		_thrust = 1;
		_thrustTime = time;
		break;
	case GLUT_KEY_LEFT:
		_left = 1;
		_leftTime = time;
		break;
	case GLUT_KEY_RIGHT:
		_right = 1;
		_rightTime = time;
		break;
	case GLUT_KEY_DOWN:
		_back = 1;
		_backTime = time;
		break;
	}
}

// 
void Player::SpecialKeyUpPressed(int key)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		_thrust = 0;
		break;
	case GLUT_KEY_LEFT:
		_left = 0;
		break;
	case GLUT_KEY_RIGHT:
		_right = 0;
		break;
	case GLUT_KEY_DOWN:
		_back = 0;
		break;
	}
}

//
void Player::MakeShot(int time)
{
	// TODO Check _currentWeapon

	if (_BlasterGun != 0)
	{
		_BlasterGun->MakeShot(time, _position);
	}

}

// TODO !!!!!!!! Read only pointer
Position* Player::GetPosition()
{
	return &_position;
}

//
bool Player::IsHit(Asteroid* ast)
{
	// TODO Check _currentWeapon

	if (_BlasterGun != 0)
	{
		return _BlasterGun->IsDamagedByBullets(ast);
	}

	return false;
}

//
bool Player::IsDamagedByAst(Asteroid* ast)
{
	float enemyX = ast->GetX();
	float enemyY = ast->GetY();

	// Find intersection
	float r = sqrt(pow(abs(_position.x - enemyX), 2) + pow(abs(_position.y - enemyY), 2));

	if (r <= ast->GetOuterRadius() + 1.0) // TODO
	{
		return true;
	}

	return false;
}

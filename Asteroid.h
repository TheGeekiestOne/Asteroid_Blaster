#pragma once
#ifndef __asteroidenemy_h__
#define __asteroidenemy_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/

#include <vector>
#include "Vertex.h"
#include "GraphicObject.h"
#include "AsteroidObject.h"
#include "Position.h"

class Asteroid : public AsteroidObject, public GraphicObject
{
public:
	//
	Asteroid(float playerX, float playerY);
	//
	virtual ~Asteroid();
	//
	virtual void Draw();
	// 
	virtual void Update(int time, int delta = 0);
	//
	virtual float GetOuterRadius();

	bool IsVisible();
	void SetVisible(bool visibility);

	bool IsVisibleInViewport();

	std::vector<Asteroid*> SplitToPieces();

	bool HasEffectiveDamage();

private:
	int _GetRandomCountOfVertexes();
	int _GetTrianglesCount();

	std::vector<Vertex> _vertexes;
	float _radius;
	bool _isVisible;

	bool _isDust;

	bool _isPiece;
	float _deltaX;
	float _deltaY;

	float _pieceAngle;

	int shapeType;
};

#endif /* __asteroidenemy_h__ */

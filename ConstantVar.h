#ifndef __constants_h__
#define __constants_h__

/*********************************
******     Copyright (c)    ******
***        Ayran Olckers       ***
**           W1654684           **
**           11/2019            **
******                      ******
**********************************/
//Constant variebles for calculations and strings to call from

#include <string>

const int ORTHO_MAX = 100;
const float ORTHO_MAX_D = 100.0;

const int MAX_BULLETS = 10; //maxx bullets to live 
const float M_PI = 3.14159265358979323846; //some Math libraries dont include PI
const float SIDE_MOVING_ACC = 0.1;

//max triangle from asteroid
const int PENTAGON_RIBERS_NUMBER = 5;

//radius of asteroid
const float DEFAULT_ASTEROID_RADIUS = 5; 

//
const float PENTAGON_TRIANGLE_ANGLES = 72;

//how long bullet lives in scene
const int TIME_BULLETS_ALIVE = 1500;
//how long the initail title screen lasts
const int TIME_INITIAL_SCREEN_ALIVE = 4000;

//starting lives for player - 
//const int DEFAULT_LIVES_COUNT = 5;

const std::string GAME_NAME = ( "ASTEROID BLASTER") ;
const std::string GAME_AUTHOR = ("A Game Created by Ayran Olckers");
const std::string GAME_CONTROL1 = ("Game Controls: ");
const std::string GAME_CONTROL2 = ("To Move: Up/Dwn/Left/Rght");
const std::string GAME_CONTROL3 = ("To Shoot: SpaceBar");
const std::string POINTS_LABEL = "Points: ";
const std::string LEVEL_LABEL = "Level: ";
const std::string LIVES_LABEL = " lives";

#endif /* __constants_h__ */


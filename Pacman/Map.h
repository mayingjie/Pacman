//
//  Map.h
//  Pacman
//
//  Created by Yingjie Ma on 12/7/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#ifndef Pacman_Map_h
#define Pacman_Map_h

#include "Map.h"
#include "SDL/SDL.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// Size of distance
const int MAP_CELL = 20;

// Size of walls
const int WALL_HEIGHT = 20;
const int WALL_WIDTH = 20;

// Size of foods
const int FOOD_HEIGHT = 4;
const int FOOD_WIDTH = 4;

class Map{
private:
    vector<SDL_Rect *> walls;
    vector<SDL_Rect *> foods;
    int foodsTotal;

public:
    Map();
    ~Map();
    bool loadMap( string file );
    
    vector<SDL_Rect *>& getWalls();
    vector<SDL_Rect *>& getFoods();
    
    int getFoodsEatenCount();
    
    bool isRectCollision( SDL_Rect *A, SDL_Rect *B );
    bool isMultiRectCollision( SDL_Rect *A );
    
};

#endif

//
//  Pacman.h
//  Pacman
//
//  Created by Yingjie Ma on 12/7/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#ifndef Pacman_Pacman_h
#define Pacman_Pacman_h

#include "Pacman.h"
#include "SDL/SDL.h"

#include <iostream>
#include <fstream>

// Size of pacman
const int PACMAN_HEIGHT = 20;
const int PACMAN_WIDTH = 20;

class Pacman{
private:
    SDL_Rect box;
    // Velocity
    int xVel;
    int yVel;
public:
    Pacman();
    Pacman( std::string );
    bool loadPacman( std::string );
    int* getPosition();
    void handle_input();
    void move( SDL_Rect * );
    void render();
};


#endif

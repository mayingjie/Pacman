//
//  Pacman.cpp
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#include "Pacman.h"

Pacman::Pacman() {
    
    if( !loadPacman( "map.txt" ) ) {
        // if not load pacman position, set default
        box.x = 0;
        box.y = 0;
    }
    box.w = PACMAN_WIDTH;
    box.h = PACMAN_HEIGHT;
    xVel = 0;
    yVel = 0;
    
}

bool Pacman::loadPacman( std::string filename ) {
    
    std::string str;
    bool pacmanFound = false;
    int row = 0, col = 0;
    
    std::ifstream map( filename );
    if( !map.good() ){
        return false;
    }
    
    while( !pacmanFound && getline( map, str ) ){
        
        for( int i = 0; i < str.length(); ++i ){
            if( str[i] == 'P' ){
                box.x = col*PACMAN_WIDTH;
                box.y = row*PACMAN_HEIGHT;
                pacmanFound = true;
                break;
            }
            col++;
        }
        row++;
        col = 0;
    }
    
    map.close();
    
    return true;
}

// Takes key presses
void Pacman::getInput( SDL_Event *event ){
    if( event->type == SDL_KEYDOWN ) {
        switch ( event->key.keysym.sym ) {
            // Pacman wouldn keep moving with key press
            case SDLK_UP: {
                yVel = -PACMAN_MOVE_DISTANCE;
                xVel = 0;
                break;
            }
            case SDLK_DOWN: {
                yVel = PACMAN_MOVE_DISTANCE;
                xVel = 0;
                break;
            }
            case SDLK_LEFT: {
                xVel = -PACMAN_MOVE_DISTANCE;
                yVel = 0;
                break;
            }
            case SDLK_RIGHT: {
                xVel = PACMAN_MOVE_DISTANCE;
                yVel = 0;
                break;
            }
            default: break;
        }
    }
}

void Pacman::move( Map *map, SDL_Rect *screen ) {
    box.x += xVel;
    
    // check boarder of screen and walls
    
    if( box.x < screen->x || box.x+box.w > screen->x+screen->w ||
       map->isMultiRectCollision( &box ) ){
        box.x -= xVel;
    }
    
    box.y += yVel;
    if( box.y < screen->y|| box.y+box.h > screen->y+screen->h ||
       map->isMultiRectCollision( &box ) ){
        box.y -= yVel;
    }
}

SDL_Rect &Pacman::getRect(){
    return box;
}





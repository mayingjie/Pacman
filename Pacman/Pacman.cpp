//
//  Pacman.cpp
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#include "Pacman.h"

Pacman::Pacman() {}

Pacman::Pacman( std::string filename ){
    
    if( !loadPacman( filename ) ) {
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
void Pacman::handle_input() { }
//    if( event.type == SDL_KEYDOWN ) {
//        switch ( event.key.keysym.sym ) {
//                // Pacman would keep moving with key press
//            case SDLK_UP: yVel -= MAP_CELL; break;
//            case SDLK_DOWN: yVel += MAP_CELL; break;
//            case SDLK_LEFT: xVel -= MAP_CELL; break;
//            case SDLK_RIGHT: xVel += MAP_CELL; break;
//            default: break;
//        }
//    }
//    else if ( event.type == SDL_KEYUP ) {
//        switch ( event.key.keysym.sym ) {
//                // Undo the change in vel when release key
//            case SDLK_UP: yVel += MAP_CELL; break;
//            case SDLK_DOWN: yVel -= MAP_CELL; break;
//            case SDLK_LEFT: xVel += MAP_CELL; break;
//            case SDLK_RIGHT: xVel -= MAP_CELL; break;
//            default: break;
//        }
//    }
//}

void Pacman::move( SDL_Rect *screen ) {
    box.x += xVel;
    
    // check boarder of screen and walls
    
    if( box.x < screen->x || box.x+box.w > screen->x+screen->w ){
       //isMultiRectCollision( &box, map->getWalls() )
        box.x -= xVel;
    }
//    else if( isMultiRectCollision( &box, map->getFoods() ) ){
//        // eat food
//        map->eatFood( &box );
//    }
    
    box.y += yVel;
    if( box.y < screen->y|| box.y+box.h > screen->y+screen->h ){
       //isMultiRectCollision( &box, map->getWalls() )
        box.y -= yVel;
    }
//    else if( isMultiRectCollision( &box, map->getFoods() ) ){
//        // eat food
//        map->eatFood( &box );
//    }
}

void Pacman::render(){
    //apply_surface( box.x, box.y, pacmanSurface, screen );
}

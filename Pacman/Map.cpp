//
//  Map.cpp
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#include "Map.h"

Map::Map(){}

Map::Map( std::string filename ){
    
    walls = std::vector<SDL_Rect *>();
    foods = std::vector<SDL_Rect *>();
    foodsTotal = 0;
    
    loadMap( filename );
}

Map::~Map(){
    // 用vector<数据类型>().swap(vector变量名)释放vector所占的内存;
    for( auto it = walls.begin(); it != walls.end(); ++it ){
        delete *it;
    }
    for( auto it = foods.begin(); it != foods.end(); ++it ){
        delete *it;
    }}

bool Map::loadMap( string filename ){
    
    std::string str;
    int row = 0, col = 0;
    
    std::ifstream pacmanMap( filename );
    
    if( !pacmanMap.good() ){
        return false;
    }
    
    
    while( getline( pacmanMap, str ) ){
        
        for( int i = 0; i < str.length(); ++i ){
            if( str[i] == '%') {
                SDL_Rect *wall = new SDL_Rect;
                wall->x = col*MAP_CELL;
                wall->y = row*MAP_CELL;
                wall->w = WALL_WIDTH;
                wall->h = WALL_HEIGHT;
                walls.push_back( wall );
            }
            
            if( str[i] == '.' ) {
                SDL_Rect *food = new SDL_Rect;
                food->x = col*MAP_CELL+8;
                food->y = row*MAP_CELL+8;
                food->w = FOOD_WIDTH;
                food->h = FOOD_HEIGHT;
                foods.push_back( food );
                foodsTotal++;
            }
            col++;
        }
        row++;
        col = 0;
        
    }
    
    pacmanMap.close();
    
    return true;
}


std::vector<SDL_Rect *>& Map::getWalls() {
    return walls;
}

std::vector<SDL_Rect *>& Map::getFoods() {
    return foods;
}

void Map::eatFood( SDL_Rect *pacman ) {
    
    for( auto it = foods.begin(); it != foods.end(); ++it ){
        if( isRectCollision( pacman, *it ) ) {
            delete *it;
            foods.erase( it );
            break;
        }
    }
}

int Map::getFoodsEatenCount() {
    return foodsTotal-(int)foods.size();
}

bool Map::isMultiRectCollision( SDL_Rect *A, vector<SDL_Rect *> &Bs ){
    bool isCollision = false;
    
    for( auto it = Bs.begin(); it != Bs.end(); ++it ){
        if( isRectCollision( A, *it ) ){
            isCollision = true;
        }
    }
    return isCollision;
}

bool Map::isRectCollision( SDL_Rect *A, SDL_Rect *B ){
    
    // Calculate the sides of A and B
    int leftA, rightA, topA, bottomA;
    int leftB, rightB, topB, bottomB;
    
    leftA = A->x;
    rightA = A->x+A->w;
    topA = A->y;
    bottomA = A->y+A->h;
    leftB = B->x;
    rightB = B->x+B->w;
    topB = B->y;
    bottomB = B->y+B->h;
    
    // Check collision
    bool isCollision = true;
    
    if( leftA >= rightB || rightA <= leftB || topA >= bottomB || bottomA <= topB ){
        isCollision = false;
    }
    
    return isCollision;
}

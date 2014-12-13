//
//  Window.h
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#ifndef __Pacman__Window__
#define __Pacman__Window__

#include "Window.h"
#include "Timer.h"
#include "Map.h"
#include "Pacman.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_image/SDL_image.h"

#include <iostream>
#include <fstream>
#include <string>



// Screen attributes
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// The frames per second

// Event structure

class Window{
private:
    // The surfaces
    SDL_Surface* pacmanSurface = NULL;
    SDL_Surface* scoreSurface = NULL;
    SDL_Surface* wallSurface = NULL;
    SDL_Surface* background = NULL;
    SDL_Surface* screen = NULL;
    SDL_Surface* foodSurface = NULL;
    
    // Event
    SDL_Event event;

    // Text
    TTF_Font *font = NULL;
    SDL_Color textColor = { 255, 255, 255 };
    
    SDL_Rect screenRect;
    bool quit = false;
    
    // Memeber
    Timer _fps;
    Map _map;
    Pacman _pacman;
    
public:
    Window();
    ~Window();
    
    void init();
    void load_file();

    SDL_Surface* load_image( std::string filename, bool colorKey = false);
    void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest );
    SDL_Surface* load_message( std::string txt );
    void loop();
    
    // Show
    void pacmanRender();
    void mapRender();
};

#endif /* defined(__Pacman__Window__) */


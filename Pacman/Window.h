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
#include "SDL/SDL.h"
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
SDL_Event event;

class Window{
private:
    // The surfaces
    SDL_Surface* pacmanSurface = NULL;
    SDL_Surface* scoreSurface = NULL;
    SDL_Surface* wallSurface = NULL;
    SDL_Surface* background = NULL;
    SDL_Surface* screen = NULL;
    SDL_Surface* foodSurface = NULL;

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
    SDL_Surface* load_image( std::string filename, bool colorKey = false);
    void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest );
    bool init();
    SDL_Surface* load_message( std::string txt );
    bool load_file();
    void loop();
    ~Window();
};

#endif /* defined(__Pacman__Window__) */


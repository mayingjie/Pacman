//
//  Window.cpp
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#include "Window.h"

Window::Window(){
    init();
    load_file();
    
    // init map, pacman
    
}
/*load the image, then returns a pointer to the optimized
 version of the loaded image. */
SDL_Surface* Window::load_image( std::string filename, bool colorKey ) {
    
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;
    
    // IMG_load( file ) is revised version of the image loading function
    loadedImage = IMG_Load( filename.c_str() );
    
    if( loadedImage != NULL ) {
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        SDL_FreeSurface( loadedImage );
    }
    
    return optimizedImage;
}

/* surface blitting function. */
void Window::apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest ) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    
    SDL_BlitSurface( src, NULL, dest, &offset );
}

void Window::init() {
    
    screenRect = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
        throw exception();
    }
    
    if( TTF_Init() == -1){
        throw exception();
    }
    
    // Set window caption
    SDL_WM_SetCaption( "Pacman", NULL );
    
    // Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if( screen == NULL) {
        throw exception();
    }
    
}

SDL_Surface* Window::load_message( std::string txt ) {
    
    SDL_Surface *message = TTF_RenderText_Solid( font, txt.c_str(), textColor );
    
    return message;
}

// Show
void Window::mapRender() {
    vector<SDL_Rect *> walls = _map.getWalls();
    for( auto it = walls.begin(); it != walls.end(); ++it ){
        apply_surface( (*it)->x, (*it)->y, wallSurface, screen );
    }
    
    vector<SDL_Rect *> foods = _map.getFoods();
    for( auto it = foods.begin(); it != foods.end(); ++it ){
        apply_surface( (*it)->x, (*it)->y, foodSurface, screen);
    }
    
}
void Window::pacmanRender() {
    SDL_Rect pacmanRect = _pacman.getRect();
    apply_surface( pacmanRect.x, pacmanRect.y, pacmanSurface, screen );
}


void Window::load_file() {
    background = load_image( "blue.jpg" );
    pacmanSurface = load_image( "pacman.png", true );
    wallSurface = load_image( "wall.jpg" );
    foodSurface = load_image( "food.jpg" );
    
    font = TTF_OpenFont( "huiming.ttf", 24 );
    
    if( background == NULL ){
        std::cout << "blackground load fail" << std::endl;
        throw exception();
    }
    
    if( pacmanSurface == NULL ){
        std::cout << "pacman load fail" << std::endl;
        throw exception();
    }
    
    if( wallSurface == NULL ){
        std::cout << "wall load fail" << std::endl;
        throw exception();
    }
    
    if( font == NULL ){
        std::cout << "font load fail" << std::endl;
        throw exception();
    }
    
}
void Window::loop(){
    

    while( quit == false ) {
        
        _fps.start();
        // Events
        while( SDL_PollEvent( &event )) {
            
            _pacman.getInput( &event );
            
            if( event.type == SDL_QUIT ) {
                quit = true;
            }
        }
        
        // Logic
        _pacman.move(&_map, &screenRect);
        
        // Rendering
        apply_surface( 0, 0, background, screen );

        mapRender();
        pacmanRender();
        
        // Score
        string txt = "Score: "+std::to_string( 20*_map.getFoodsEatenCount() );
        scoreSurface = load_message( txt );
        apply_surface( 20, SCREEN_HEIGHT-50, scoreSurface, screen );
        
        // Update screen
        if( SDL_Flip( screen ) == -1 ) {
            return;
        }
        
        //Cap the frame rate
        if( _fps.getTicks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - _fps.getTicks() );
        }
    }
}



Window::~Window(){
    // Free the surface
    SDL_FreeSurface( background );
    SDL_FreeSurface( pacmanSurface );
    SDL_FreeSurface( wallSurface );
    SDL_FreeSurface( scoreSurface );
    SDL_FreeSurface( foodSurface );
    
    TTF_CloseFont( font );
    
    TTF_Quit();
    SDL_Quit();
}







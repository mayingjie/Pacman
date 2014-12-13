//
//  Timer.cpp
//  Pacman
//
//  Created by Yingjie Ma on 12/12/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#include "Timer.h"

Timer::Timer(){
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

void Timer::start(){
    started = true;
    paused = false;
    // Get milliseconds since the SDL library initialization.
    startTicks = SDL_GetTicks();
}

void Timer::stop(){
    started = false;
    paused = false;
}

bool Timer::isStarted(){
    return started;
}

bool Timer::isPaused(){
    return paused;
}

int Timer::getTicks(){
    if( started ){
        if( paused ){
            return pausedTicks;
        }
        else{
            return SDL_GetTicks()-startTicks;
        }
    }
    return 0;
}

void Timer::pause(){
    if( started ){
        if( !paused ){
            paused = true;
            pausedTicks = SDL_GetTicks()-startTicks;
        }
    }
}

void Timer::unpause(){
    if( started ){
        if( paused ){
            paused = false;
            // Why Foo says startTicks = SDL_GetTicks() - pausedTicks;
            startTicks = SDL_GetTicks();
            pausedTicks = 0;
        }
    }
}


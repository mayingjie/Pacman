//
//  Timer.h
//  Pacman
//
//  Created by Yingjie Ma on 12/7/14.
//  Copyright (c) 2014 YingJ Ma. All rights reserved.
//

#ifndef Pacman_Timer_h
#define Pacman_Timer_h

#include "Timer.h"
#include "SDL/SDL.h"

const int FRAMES_PER_SECOND = 2;

class Timer{
private:
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;
    
public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    
    bool isStarted();
    bool isPaused();
    
    int getTicks();
};

#endif

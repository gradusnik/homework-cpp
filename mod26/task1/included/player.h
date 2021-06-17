#pragma once
#include "tracks.h"

enum Indicator {
    STOPPED,
    PLAYING,
    PAUSED,
};

class Player {
    //indicator  0 - stopped, 1 - playing, 2 - paused
    Indicator indicator = STOPPED;
    int currentTrack = 0;
public:
    Track tracks[5];
    int findTrack(std::string presumedName);
    void display();
    void setCurrentTrack(int n);
    void nextTrack();
    void changeIndicator(Indicator ind);
    int getIndicator();
    void play();
    void paused();
    void next();
    void stop();
};

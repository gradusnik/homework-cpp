#pragma once
#include "tracks.h"
#include <vector>

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
    std::vector<Track> tracks;
    void addTrack(std::string trackName);
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

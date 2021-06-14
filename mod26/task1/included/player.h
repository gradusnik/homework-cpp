#pragma once
#include "tracks.h"

class Player {
    int indicator = 0;// 0 - stopped, 1 - playing, 2 - paused
    int currentTrack = 0;
    //int nextTrack = 0;
public:
    Track tracks[5];
    int findTrack(std::string presumedName) {
      for (int i = 0; i < 5; ++i) {
        if (tracks[i].getTrackName() == presumedName) return i;
      }
      return -1;
    }

    void display() {
      std::cout << tracks[currentTrack].getTrackName() << " "
                << tracks[currentTrack].getTrackCreationDate() << " "
                << tracks[currentTrack].getTrackDuration() << std::endl;
    }

    void setCurrentTrack(int n) {
      currentTrack = n;
    }

    void nextTrack() {
      currentTrack = rand() % 5;
    }

    void changeIndicator(int ind) {
      indicator = ind;
    }

    int getIndicator() {
      return indicator;
    }
};

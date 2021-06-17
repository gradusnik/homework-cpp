#include "player.h"
#include <iostream>

void Player::addTrack(std::string trackName) {
  Track tempTrack;
  tempTrack.setValues();
  tempTrack.setName(trackName);
  tracks.push_back(tempTrack);
}

int Player::findTrack(std::string presumedName) {
  for (int i = 0; i < 5; ++i) {
    if (tracks[i].getTrackName() == presumedName) return i;
  }
  return -1;
}

void Player::display() {
  std::cout << tracks[currentTrack].getTrackName() << " "
            << tracks[currentTrack].getTrackCreationDate() << " "
            << tracks[currentTrack].getTrackDuration() << std::endl;
}

void Player::setCurrentTrack(int n) {
  currentTrack = n;
}

void Player::nextTrack() {
  currentTrack = rand() % 5;
}

void Player::changeIndicator(Indicator ind) {
  indicator = ind;
}

int Player::getIndicator() {
  return indicator;
}
// 0 - stopped, 1 - playing, 2 - paused
void Player::play() {
  if(getIndicator() == STOPPED) {
    std::string prTrack;
    std::cout << "enter the track name: ";
    std::getline(std::cin, prTrack);
    int trackNumber = findTrack(prTrack);
    if (trackNumber != -1) {
      changeIndicator(PLAYING);
      setCurrentTrack(trackNumber);
      display();
    } else std::cout << "no track" << std::endl;
  } else if (getIndicator() == PAUSED) {
    changeIndicator(PLAYING);
    display();
  }
}

void Player::paused() {
  if (getIndicator() == PLAYING) {
    changeIndicator(PAUSED);
    std::cout << "pause..." << std::endl;
  }
}

void Player::next() {
  nextTrack();
  changeIndicator(PLAYING);
  display();
}

void Player::stop() {
  if (getIndicator() != STOPPED) {
    changeIndicator(STOPPED);
    std::cout << "stopped" << std::endl;
  }
}
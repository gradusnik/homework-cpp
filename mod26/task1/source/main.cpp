#include <iostream>
#include <string>
#include "player.h"

int main() {
  std::srand(std::time(nullptr));
  Player player;
  for (int i = 0; i < 5; ++i) {
    player.tracks[i].setValues();
  }
  player.tracks[0].setName("Filip Kirkorov");
  player.tracks[1].setName("Nikolay Baskov");
  player.tracks[2].setName("Egor Krid");
  player.tracks[3].setName("Timati");
  player.tracks[4].setName("Morgenstern");


  std::string command;
  while (command != "exit") {
    std::cout << "enter the command: ";
    std::cin >> command;
    std::cin.ignore();
    if (command == "play") {
      if(player.getIndicator() == 0) {
        std::string prTrack;
        std::cout << "enter the track name: ";
        std::getline(std::cin, prTrack);
        int trackNumber = player.findTrack(prTrack);
        if (trackNumber != -1) {
          player.changeIndicator(1);
          player.setCurrentTrack(trackNumber);
          player.display();
        } else std::cout << "no track" << std::endl;
      } else if (player.getIndicator() == 2) {
        player.changeIndicator(1);
        player.display();
      }
    } else if (command == "pause") {
      if (player.getIndicator() == 1) {
        player.changeIndicator(2);
        std::cout << "pause..." << std::endl;
      }
    } else if (command == "next") {
      player.nextTrack();
      player.changeIndicator(1);
      player.display();
    } else if (command == "stop") {
      if (player.getIndicator() != 0) {
        player.changeIndicator(0);
        std::cout << "stopped" << std::endl;
      }
    } else if (command == "exit") player.changeIndicator(0);
    else std::cout << "no such command" << std::endl;
  }
  return 0;
}

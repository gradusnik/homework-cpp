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
      player.play();
    } else if (command == "pause") {
      player.paused();
    } else if (command == "next") {
      player.next();
    } else if (command == "stop") {
      player.stop();
    } else if (command == "exit") player.changeIndicator(STOPPED);
    else std::cout << "no such command" << std::endl;
  }
  return 0;
}

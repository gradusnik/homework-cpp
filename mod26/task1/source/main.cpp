#include <iostream>
#include <string>
#include "player.h"

int main() {
  std::srand(std::time(nullptr));
  Player player;

  player.addTrack("Filip Kirkorov");
  player.addTrack("Nikolay Baskov");
  player.addTrack("Egor Krid");
  player.addTrack("Timati");
  player.addTrack("Morgenstern");


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

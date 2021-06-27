#include <iostream>
#include "monitor.h"

int main() {
  Monitor testMonitor;
  std::string command;
  while (command != "close") {
    std::cout << "enter the command(move, resize, display, close): ";
    std::cin >> command;
    if (command == "move") testMonitor.someWindow.move();
    else if (command == "resize") testMonitor.someWindow.resize();
    else if (command == "display") testMonitor.display();
    else if (command != "close") std::cout << "no such command" << std::endl;
  }
  return 0;
}

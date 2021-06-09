#include <iostream>
#include "ram.h"
#include "gpu.h"
#include "cpu.h"
#include "disk.h"
#include "kbd.h"

int main() {
  std::string command;
  while (command != "exit") {
    std::cout << "enter the command(sum, save, load, input, display, exit): ";
    std::cin >> command;
    if (command == "sum") compute(numbers);
    else if (command == "save") save(numbers);
    else if (command == "load") load(numbers);
    else if (command == "input") inputNumbers(numbers);
    else if (command == "display") display(numbers);
    else if (command != "exit") std::cout << "no such command!" << std::endl;
  }
  return 0;
}
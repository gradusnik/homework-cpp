#include <iostream>
#include "ram.h"
#include "gpu.h"
#include "cpu.h"
#include "disk.h"
#include "kbd.h"


int main() {
  std::string command;
  double numbers[8];
  while (command != "exit") {
    std::cout << "enter the command(sum, save, load, input, display, exit): ";
    std::cin >> command;
    if (command == "sum") {
      read(numbers);
      compute(numbers);
    }
    else if (command == "save") {
      read(numbers);
      save(numbers);
    }
    else if (command == "load") {
      load(numbers);
      write(numbers);
    }
    else if (command == "input") {
      inputNumbers(numbers);
      write(numbers);
    }
    else if (command == "display") {
      read(numbers);
      display(numbers);
    }
    else if (command != "exit") std::cout << "no such command!" << std::endl;
  }
  return 0;
}
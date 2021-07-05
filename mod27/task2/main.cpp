#include <iostream>
#include <string>
#include "figures.h"
#include "input.h"

int main() {
  std::string command;
  double x, y, a, b;
  Color col;
  while (command != "exit") {
    std::cout << "enter next command(circle, square, triangle, rectangle, exit): ";
    std::cin >> command;
    if (command == "circle") {
      inputColor(col);
      inputCenter(x, y);
      inputEdges(a);
      Circle circle1(col, x, y, a);
      std::cout << enumToStr(circle1.color) << " circle has area of "
                << circle1.area() << std::endl;
    } else if (command == "square") {
      inputColor(col);
      inputCenter(x, y);
      inputEdges(a);
      Square square1(col, x, y, a);
      std::cout << enumToStr(square1.color) << " square has area of "
                << square1.area() << std::endl;
    } else if (command == "triangle") {
      inputColor(col);
      inputCenter(x, y);
      inputEdges(a);
      Triangle triangle1(col, x, y, a);
      std::cout << enumToStr(triangle1.color) << " triangle has area of "
                << triangle1.area() << std::endl;
    } else if (command == "rectangle") {
      inputColor(col);
      inputCenter(x, y);
      inputEdges(a, b);
      Rectangle rectangle1(col, x, y, a, b);
      std::cout << enumToStr(rectangle1.color) << " rectangle has area of "
                << rectangle1.area() << std::endl;
    } else if (command != "exit") std::cout << "no command" << std::endl;
  }
  return 0;
}

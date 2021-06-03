#pragma once
#include <iostream>

struct Point {
    double coorX;
    double coorY;
};

void inputPoint(std::string message, Point& point) {
  std::cout << message << std::endl;
  std::cout << "\tenter X of point: ";
  std::cin >> point.coorX;
  std::cout << "\tenter Y of point: ";
  std::cin >> point.coorY;
}

std::string outputPoint(Point point) {
  return std::to_string(point.coorX) + "/" + std::to_string(point.coorY);
}

bool coincidence(Point a, Point b) {
  double delta = 0.3;
  if (a.coorX >= b.coorX - delta && a.coorX <= b.coorX + delta &&
      a.coorY >= b.coorY - delta && a.coorY <= b.coorY + delta) return true;
  return false;
}
#include <iostream>
#include "figures.h"

std::string enumToStr(Color col) {
  if (col == WHITE) return "white";
  else if (col == BLACK) return "black";
  else if (col == RED) return "red";
  else if (col == GREEN) return "green";
  else return "blue";
}

void inputColor(Color& c) {
  int inCol(0);
  std::cout << "\tenter the color of figure(0-white, 1-black, 2-red, 3-green, 4-blue): ";
  std::cin >> inCol;
  if (inCol < 1) c = WHITE;
  else if (inCol == 1) c = BLACK;
  else if (inCol == 2) c = RED;
  else if (inCol == 3) c = GREEN;
  else c = BLUE;
}

void inputCenter(double& x, double& y) {
  std::cout << "\tenter X coord of center: ";
  std::cin >> x;
  std::cout << "\tenter Y coord of center: ";
  std::cin >> y;
}

void inputEdges(double& e) {
  std::cout << "\tenter the edge(if it rectangle or triangle) or radius(if it circle): ";
  std::cin >> e;
}

void inputEdges(double& a, double& b) {
  std::cout << "\tenter first edge: ";
  std::cin >> a;
  std::cout << "\tenter second edge: ";
  std::cin >> b;
}
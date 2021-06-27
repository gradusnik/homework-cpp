#include "monitor.h"
#include <iostream>

void Monitor::display() {
  int xStart = someWindow.getXStart();
  int xEnd = someWindow.getXStart() + someWindow.getWidth();
  int yStart = someWindow.getYStart();
  int yEnd = someWindow.getYStart() + someWindow.getHeight();
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if ((x >= xStart && x < xEnd) && (y >= yStart && y < yEnd))
        std::cout << '1';
      else std::cout << '0';
    }
    std::cout << std::endl;
  }
}

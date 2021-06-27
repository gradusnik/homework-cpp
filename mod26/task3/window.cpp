#include "window.h"
#include <iostream>

void Window::setXStart(int x)  {
  if (x > 79) x_start = 79;
  else if (x < 0) x_start = 0;
  else x_start = x;
}
void Window::setYStart(int y) {
  if (y > 49) y_start = 49;
  else if (y < 0) y_start = 0;
  else y_start = y;
}
void Window::setWidth(int w) {
  if (w > 80) width = 80;
  else if (w < 1) width = 1;
  else width = w;
}
void Window::setHeight(int h) {
  if (h > 50) height = 50;
  else if (h < 1) height = 1;
  else height = h;
}
int Window::getXStart() {
  return x_start;
}
int Window::getYStart() {
  return y_start;
}
int Window::getWidth() {
  return width;
}
int Window::getHeight() {
  return height;
}
void Window::move() {
  int xShift(0), yShift(0);
  std::cout << "enter the X for move: ";
  std::cin >> xShift;
  std::cout << "enter the Y for move: ";
  std::cin >> yShift;
  setXStart(x_start + xShift);
  setYStart(y_start + yShift);
  std::cout << "new start coordinates: " << getXStart() << " " << getYStart() << std::endl;
}

void Window::resize() {
  int newWidth(0), newHeight(0);
  std::cout << "enter new width: ";
  std::cin >> newWidth;
  std::cout << "enter new height: ";
  std::cin >> newHeight;
  setWidth(newWidth);
  setHeight(newHeight);
  std::cout << "new size: " << getWidth() << " " << getHeight() << std::endl;
}
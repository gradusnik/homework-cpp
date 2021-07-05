#include "figures.h"
#include <cmath>

double pi = 3.14;

Circle::Circle(Color col, double x, double y, double r) {
  color = col;
  centerX = x;
  centerY = y;
  (r >= 0) ? radius = r : radius = 0;
}
double Circle::area() {
  return radius * radius * pi;
}

Triangle::Triangle(Color col, double x, double y, double e) {
  color = col;
  centerX = x;
  centerY = y;
  (e >= 0) ? edge = e : edge = 0;
}
double Triangle::area() {
  return std::sqrt(3) * edge * edge / 4;
}

Square::Square(Color col, double x, double y, double e) {
  color = col;
  centerX = x;
  centerY = y;
  (e >= 0) ? edgeA = e : edgeA = 0;
}
double Square::area() {
  return edgeA * edgeA;
}

Rectangle::Rectangle(Color col, double x, double y, double a, double b) : Square(col, x, y, a) {
  color = col;
  centerX = x;
  centerY = y;
  (a >= 0) ? edgeA = a : edgeA = 0;
  (b >= 0) ? edgeB = b : edgeB = 0;
}
double Rectangle::area() {
  return edgeA * edgeB;
}
#pragma once
#include "points.h"

void scalpel(Point a, Point b) {
  std::cout << "the slit has been made from " << outputPoint(a) <<
                " to " << outputPoint(b) << std::endl;
}

void hemostat(Point a) {
  std::cout << "the capture has been done in " << outputPoint(a) << std::endl;
}

void tweezers(Point a) {
  std::cout << "the grip has been done in " << outputPoint(a) << std::endl;
}

void suture(Point a, Point b) {
  std::cout << "the stitch has been made from " << outputPoint(a) <<
                " to " << outputPoint(b) << std::endl;
}
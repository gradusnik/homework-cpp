#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
  std::time_t time01 = std::time(nullptr);
  std::tm local = *std::localtime(&time01);
  std::cout << "enter min & sec for countdown (format mm:ss): ";
  std::cin >> std::get_time(&local, "%M:%S");
  int gap = local.tm_min * 60 + local.tm_sec;
  //std::cout << gap << std::endl;
  std::time_t currTime = std::time(nullptr);
  std::time_t targetTime = currTime + gap;
  std::time_t currTimeNew;
  while(currTime != targetTime) {
    currTimeNew = std::time(nullptr);
    if (currTimeNew != currTime) {
      currTime = currTimeNew;
      gap = targetTime - currTime;
      std::cout << gap / 60 << ":" << gap % 60 << std::endl;
    }
  }
  std::cout << "ding...ding" << std::endl;
  return 0;
}

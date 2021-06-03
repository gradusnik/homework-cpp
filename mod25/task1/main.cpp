#include "points.h"
#include "tools.h"

int main() {
  std::cout << "operation has started..." << std::endl;
  std::cout << "we gonna make a slit..." << std::endl;
  Point aForSlit, bForSlit;
  inputPoint("enter first point", aForSlit);
  inputPoint("enter last point", bForSlit);
  scalpel(aForSlit, bForSlit);
  std::string command;
  while(command != "suture") {
    std::cout << "enter the command (hemostat, tweezers, suture): ";
    std::cin >> command;
    if (command == "hemostat") {
      Point a;
      inputPoint("enter the point", a);
      hemostat(a);
    } else if (command == "tweezers") {
      Point a;
      inputPoint("enter the point", a);
      tweezers(a);
    } else if (command != "suture") std::cout << "no such command..." << std::endl;
  }
  Point aForStitch, bForStitch;
  std::cout << "we gonna make the stitch(need coordinates)" << std::endl;
  while (!coincidence(aForSlit, aForStitch) || !coincidence(bForSlit, bForStitch)) {
    inputPoint("enter first point", aForStitch);
    inputPoint("enter last point", bForStitch);
    if (!coincidence(aForSlit, aForStitch) || !coincidence(bForSlit, bForStitch)) {
      std::cout << "invalid coordinates for stitch" << std::endl;
    }
  }
  suture(aForStitch, bForStitch);
  std::cout << "seemingly successful operation" << std::endl;
  return 0;
}

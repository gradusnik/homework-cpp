#include "tree.h"
#include <cstdlib>
#include <iostream>

void message(std::string name, int n) {
  static int count(1);
  std::cout << "\t" << name << " (" << count << ") has "
            << n << " neighbours" << std::endl;
  count++;
}

MidBranch::MidBranch() {
  std::string inName;
  std::cout << "\tplease enter next elf name: ";
  std::cin >> inName;
  if (!(inName == "None" || inName == "none")) this->name = inName;
}

BigBranch::BigBranch() {
  std::string inName;
  std::cout << "please enter next elf name: ";
  std::cin >> inName;
  if (!(inName == "None" || inName == "none")) this->name = inName;
  int midBranches = 2 + std::rand() % 2;
  for (int i = 0; i < midBranches; ++i) {
    MidBranch midBranch = MidBranch();
    this->midBranches.push_back(midBranch);
  }
}

int BigBranch::countInhabitedHouses() {
  int count(0);
  if (!name.empty()) ++count;
  for (int i = 0; i < midBranches.size(); ++i) {
    if (!midBranches[i].name.empty()) ++count;
  }
  return --count;
}

Tree::Tree() {
  int bigBranches = 3 + std::rand() % 3;
  for (int i = 0; i < bigBranches; ++i) {
    BigBranch bigBranch = BigBranch();
    this->bigBranches.push_back(bigBranch);
  }
}

void Tree::findNameNeighbors(std::string name) {
  std::vector<BigBranch> result;
  int count(0);
  int num(0);
  for (int i = 0; i < bigBranches.size(); ++i) {
    if (bigBranches[i].name == name) {
      count++;
      num = bigBranches[i].countInhabitedHouses();
      message(name, num);
    }
    for (int k = 0; k < bigBranches[i].midBranches.size(); ++k) {
      if (bigBranches[i].midBranches[k].name == name) {
        count++;
        num = bigBranches[i].countInhabitedHouses();
        message(name, num);
      }
    }
  }
  if (count == 0) std::cout << "\tno match" << std::endl;
}
#include <iostream>
#include <string>
#include <map>

void addSurname(std::map<std::string, int> &baseMap, std::string& surname) {
  std::map<std::string, int>::iterator elem = baseMap.find(surname);
  if (elem != baseMap.end()) {
    baseMap[surname]++;
  } else {
    baseMap[surname] = 1;
  }
}

std::string getSurname(std::map<std::string , int> &baseMap) {
  std::string surname = baseMap.begin()->first;
  if (baseMap[surname] > 1) baseMap[surname]--;
  else baseMap.erase(baseMap.begin());
  return surname;
}

int main() {
  std::map<std::string, int> queue;
  std::string request;
  while (request != "-1") {
    std::cout << "enter the request: ";
    std::cin >> request;
    if (request == "next") {
      if (!queue.empty()) {
        std::cout << getSurname(queue) << std::endl;
      } else std::cout << "the queue is empty" << std::endl;
    } else {
      addSurname(queue, request);
    }
  }
  return 0;
}

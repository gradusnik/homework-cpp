#include <iostream>
#include <string>
#include <vector>
#include <map>

int trialRequest(std::string str, std::string &part1, std::string &part2) {
  str += ' ';
  int len = str.length();
  char* c = &str[0];
  int k(0);
  for (int i = 0; i < len; ++i) {
    if (*c != ' ' && k == 0) part1 += *c;
    else if (*c != ' ' && k == 1) part2 += *c;
    if (*c != ' ' && *(c + 1) == ' ') ++k;
    c++;
  }
  return k;
}

bool checkPart1(std::string str) {
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-') return false;
  }
  return true;
}

bool checkPart2(std::string str) {
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) return false;
  }
  return true;
}

int main() {
  std::string request;
  std::map<std::string, std::string> telMap;
  while (request != "-1") {
    std::cout << "enter the request: ";
    std::getline(std::cin, request);
    std::string part1, part2;
    int reqLen = trialRequest(request, part1, part2);
    if (reqLen == 2 && checkPart1(part1) && checkPart2(part2)) {
      telMap[part1] = part2;
    } else if (reqLen == 1 && checkPart1(part1)) {
      std::map<std::string, std::string>::iterator elemPtr = telMap.find(part1);
      if (elemPtr != telMap.end()) {
        std::cout << elemPtr->second << " has number you entered" << std::endl;
      } else std::cout << "there are NO such number" << std::endl;
    } else if (reqLen == 1 && checkPart2(part1)) {
      std::vector<std::string> elems;
      for (std::map<std::string, std::string>::iterator it = telMap.begin(); it != telMap.end(); ++it) {
        if (it -> second == part1) elems.push_back(it -> first);
      }
      if (!elems.empty()) {
        std::cout << "surname " << part1 << " abonents have following tels:" << std::endl;
        for (int i = 0; i < elems.size(); ++i) {
          std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
      } else std::cout << "there are NO such abonents" << std::endl;
    }
    else std::cerr << "wrong request" << std::endl;
  }
  return 0;
}

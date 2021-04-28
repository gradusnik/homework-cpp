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

bool checkNumber(std::string str) {
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-') return false;
  }
  return true;
}

bool checkSurname(std::string str) {
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) return false;
  }
  return true;
}

void addToMap(std::map<std::string, std::string> &mainMap,
              const std::string& number,
              const std::string& surname,
              std::map<std::string, std::vector<std::string>> &SurnameToNumber) {
  mainMap.insert(std::pair<std::string, std::string>(number, surname));
  SurnameToNumber[surname].push_back(number);
}

std::string numToSurname(std::map<std::string, std::string> &mainMap, std::string &number) {
  std::map<std::string, std::string>::iterator elemPtr = mainMap.find(number);
  if (elemPtr != mainMap.end()) {
    return elemPtr->second;
  }
  return "NO number";
}

std::vector<std::string> numbers(std::map<std::string,std::vector<std::string>> nums,
                                  const std::string& surname) {
  std::map<std::string, std::vector<std::string>>::iterator elemPtr = nums.find(surname);
  if (elemPtr != nums.end()) {
    return elemPtr->second;
  }
  std::vector<std::string> noNumbers = {"no", "numbers"};
  return noNumbers;
}

int main() {
  std::string request;
  std::map<std::string, std::string> telMap;
  std::map<std::string, std::vector<std::string>> surnameToNumber;
  while (request != "-1") {
    std::cout << "enter the request: ";
    std::getline(std::cin, request);
    std::string part1, part2;
    int reqLen = trialRequest(request, part1, part2);
    if (reqLen == 2 && checkNumber(part1) && checkSurname(part2)) {
      addToMap(telMap, part1, part2, surnameToNumber);
    } else if (reqLen == 1 && checkNumber(part1)) {
      std::cout << numToSurname(telMap, part1) << std::endl;
    } else if (reqLen == 1 && checkSurname(part1)) {
      std::vector<std::string> answer = numbers(surnameToNumber, part1);
      for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << " ";
      }
      std::cout << std::endl;
    }
    else std::cerr << "wrong request" << std::endl;
  }
  return 0;
}

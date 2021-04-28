#include <iostream>
#include <string>
#include <map>

void inputStrings(int n, std::string& line) {
  std::cout << "enter the string " << n << ": ";
  std::cin >> line;
}

void lineIntoMap(std::map<char, int>& Map, std::string& line) {
  int len = line.length();
  std::map<char, int>::iterator elem;
  for (int i = 0; i < len; ++i) {
    elem = Map.find(line[i]);
    if (elem == Map.end()) Map[line[i]] = 1;
    else Map[line[i]]++;
  }
}

bool inspectLineToAnagram(std::map<char, int> Map, std::string& line) {
  int len = line.length();
  std::map<char, int>::iterator elem;
  for (int i = 0; i < len; ++i) {
    elem = Map.find(line[i]);
    if (elem == Map.end()) return false;
    else if (elem->second > 1) elem->second--;
    else Map.erase(elem);
  }
  if (Map.empty()) return true;
  return false;
}

int main() {
  std::string line1, line2;
  inputStrings(1, line1);
  inputStrings(2, line2);
  std::map<char, int> mapOfchars;
  lineIntoMap(mapOfchars, line1);
  bool anagram = inspectLineToAnagram(mapOfchars, line2);
  std::cout << "string TWO " << (anagram ? "is" : "is Not") << " anagram of string ONE\n";
  return 0;
}

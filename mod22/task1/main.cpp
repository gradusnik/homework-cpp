#include <iostream>
#include <fstream>

int main() {
  std::string seekedWord;
  std::ifstream file;
  std::string curWord;
  int numSeekedWord(0);
  std::cout << "which word would you like to seek... ";
  std::cin >> seekedWord;

  file.open("D:\\SKILLBOX\\C++__Homework\\mod22\\task01.txt");
  while (!file.eof()) {
    file >> curWord;
    if (curWord == seekedWord) ++numSeekedWord;
  }
  file.close();

  std::cout << "\"" << seekedWord << "\"" << " is used "
            << numSeekedWord << " times.";
}

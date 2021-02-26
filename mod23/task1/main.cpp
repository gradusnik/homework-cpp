#include <iostream>
#include <fstream>

std::ofstream in_file("table01.txt", std::ios::app);

void writing (std::string message, char c) {
  std::string line;
  std::cout << message;
  std::cin >> line;
  in_file << line << c;
}

int main() {
  std::string line;
  int answ(1);
  if (in_file.is_open()) {
    while (answ) {
      std::cout << "would you like to make one more note?\n";
      std::cout << "if YES - press 1(and enter), if NO - press 0(and enter): ";
      std::cin >> answ;
      if (answ) {
        writing("enter the first name: ", ' ');
        writing("enter the last name: ", ' ');
        writing("enter the date(format dd.mm.yyyy): ", ' ');
        writing ("enter the sum: ", '\n');
      }
    }
    in_file.close();
  } else std::cout << "failure of opening file\n";
  return 0;
}

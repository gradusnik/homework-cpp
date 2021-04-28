#include <iostream>
#include <fstream>

int main() {
  std::string f_name;
  std::cout << "enter the valid path to the file: ";
  std::cin >> f_name;
  std::ifstream textFile;
  textFile.open(f_name, std::ios::binary);

  if (textFile.is_open()) {
    char buffer[100];
    buffer[99] = '\0';
    while (!textFile.eof()) {
      textFile.read(buffer, sizeof(buffer) - 1);

      if (textFile.eof()) {
        buffer[textFile.gcount()] = '\0';
      }
      std::cout << buffer;
    }
  } else std::cout << "fail of opening file.";
  return 0;
}
#include <iostream>
#include <string>
#include <fstream>

struct record {
    std::string name;
    std::string lastName;
    std::string date;
    int payment;
};

int main() {
  std::fstream file("table.txt");
  std::string operation;
  std::cout << "enter the operation: ";
  std::cin >> operation;
  if (file.is_open()) {
    if (operation == "list") {
      record currRecord;
      while (true) {
        file >> currRecord.name;
        if (file.eof()) break;
        file >> currRecord.lastName;
        file >> currRecord.date;
        file >> currRecord.payment;
        std::cout << currRecord.name << " "
                  << currRecord.lastName << " "
                  << currRecord.date << " "
                  << currRecord.payment << std::endl;
      }
    } else if (operation == "add") {
      record newRecord;
      file.seekg(0, std::ios::end);
      std::cout << file.tellg() << std::endl;
      std::cout << "making new record..." << std::endl
                << "enter the name: ";
      std::cin >> newRecord.name;
      file << newRecord.name << " ";
      std::cout << "enter the last name: ";
      std::cin >> newRecord.lastName;
      file << newRecord.lastName << " ";
      std::cout << "enter the date: ";
      std::cin >> newRecord.date;
      file << newRecord.date << " ";
      std::cout << "enter the payment: ";
      std::cin >> newRecord.payment;
      file << newRecord.payment << "\n";
    } else std::cerr << "invalid operation" << std::endl;
  } else std::cerr << "file not found" << std::endl;
  return 0;
}

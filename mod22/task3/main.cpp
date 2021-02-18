#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream table;
  table.open("table03.txt");
  if (table.is_open()) {
    std::string name, surname;
    double sumOfFee(0), maxFee(0);
    while (!table.eof()) {
      std::string date, currName, currLastName;
      double fee;
      table >> currName;
      table >> currLastName;
      table >> fee;
      table >> date;
      if (fee > maxFee) {
        maxFee = fee;
        name = currName;
        surname = currLastName;
      }
      sumOfFee += fee;
    }
    std::cout << name << " " << surname << " have max fee." << std::endl;
    std::cout << "summ of fees is " << sumOfFee;
  }
  return 0;
}

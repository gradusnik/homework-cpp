#include <iostream>
#include "mobile.h"

int main() {
  Mobile testMobile;
  string command;
  while (command != "exit") {
    std::cout << "enter the command: ";
    std::cin >> command;
    if (command == "add") testMobile.addContact();
    else if (command == "call") testMobile.call();
    else if (command == "sms") testMobile.sms();
    else if (command != "exit") std::cout << "no such command" << std::endl;
  }
  return 0;
}

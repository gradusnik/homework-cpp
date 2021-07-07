#include "hierarchy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

Task intToTask(int n) {
  if (n == 1) return A;
  else if (n == 2) return B;
  else return C;
}

Employee::Employee(): task(NONE){}
void Employee::receiveTask() {
  std::srand(std::time(nullptr));
  int num = 1 + std::rand() % 3;
  task = intToTask(num);
}
bool Employee::available() {
  return (task == NONE);
}

Manager::Manager(int empls) {
  for (int i = 0; i < empls; ++i) {
    Employee employee;
    employees.push_back(employee);
  }
}
int Manager::employeesNum() {
  return employees.size();
}
void Manager::giveTask(int num) {
  int i(0);
  while (i < employees.size() && num > 0) {
    if (employees[i].available()) {
      employees[i].receiveTask();
      num--;
    }
    i++;
  }
}
int Manager::getAvailableEmpls() {
  int count(0);
  for (int i = 0; i < employees.size(); ++i) {
    count += employees[i].available();
  }
  return count;
}

Chief::Chief(int n) {
  int empls(0);
  for (int i = 0; i < n; ++i) {
    std::cout << "\thow many employees does next manager have (enter the integer >= 0): ";
    std::cin >> empls;
    assert(empls >= 0);
    Manager manager(empls);
    managers.push_back(manager);
  }
}
void Chief::taskSeed(int n) {
  //assert(n > 0);
  int num;
  for (int i = 0; i < managers.size(); ++i) {
    std::srand(n + i);
    num = 1 + rand() % managers[i].employeesNum();
    managers[i].giveTask(num);
  }
}
int Chief::getAvailableEmpls() {
  int count(0);
  for (int i = 0; i < managers.size(); ++i) {
    count += managers[i].getAvailableEmpls();
  }
  return count;
}

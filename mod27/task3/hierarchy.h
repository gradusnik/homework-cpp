#pragma once
#include <vector>

//class Chief;

enum Task{
    NONE,
    A,
    B,
    C
};

class Employee{
    Task task;
public:
    Employee();
    void receiveTask();
    bool available();
};

class Manager{
    std::vector<Employee> employees;
public:
    explicit Manager(int);
    int employeesNum();
    void giveTask(int);
    int getAvailableEmpls();
};

class Chief{
    std::vector<Manager> managers;
public:
    explicit Chief(int);
    void taskSeed(int);
    int getAvailableEmpls();
};
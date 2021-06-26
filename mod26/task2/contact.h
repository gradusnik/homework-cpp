#pragma once
#include <string>

using std::string;

bool validTel(string t);
bool validName(string someName);

class Contact{
    string firstName;
    string lastName;
    string tel;
public:
    void setFirstName(string& f_name);
    void setlastName(string& l_name);
    void setTel(string& t);
    string getTel();
    string getName();
};

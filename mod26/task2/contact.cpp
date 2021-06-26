#include "contact.h"

bool validTel(string t) {
  for (int i = 0; i < t.length(); ++i) {
    if (t[i] < '0' || t[i] > '9') return false;
  }
  return true;
}

bool validName(string someName) {
  for (int i = 0; i < someName.length(); ++i) {
    if (someName[i] < 'A' || ( someName[i] > 'Z' && someName[i] < 'a') || someName[i] > 'z')
      return false;
  }
  return true;
}

void Contact::setFirstName(string& f_name) {
  firstName = f_name;
}
void Contact::setlastName(string& l_name) {
  lastName = l_name;
}
void Contact::setTel(string& t) {
  tel = t;
}
string Contact::getTel() {
  return tel;
}
string Contact::getName() {
  return firstName + " " + lastName;
}


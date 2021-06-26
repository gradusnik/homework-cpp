#include "mobile.h"
#include <iostream>

void Mobile::addContact() {
  string number;
  std::cout << "enter the phone number: ";
  std::cin >> number;
  string firstName("empty"), lastName("empty");
  std::cout << "enter first name: ";
  std::cin >> firstName;
  std::cout << "enter last name: ";
  std::cin >> lastName;
  if (validTel(number) && validName(firstName) && validName(lastName)) {
    Contact contact;
    contact.setTel(number);
    contact.setFirstName(firstName);
    contact.setlastName(lastName);
    if (findContact(number) == contacts.end()) {
      contacts.push_back(contact);
      std::cout << number << " has appended" << std::endl;
    } else std::cout << "you already have this contact" << std::endl;
  } else std::cout << "invalid data, try next time" << std::endl;
}

vector<Contact>::iterator Mobile::findContact(string assumedContact) {
  if (validTel(assumedContact)) {
    auto iter = contacts.begin();
    while (iter != contacts.end()) {
      if (iter->getTel() == assumedContact) return iter;
      iter++;
    }
  } else {
    auto iter = contacts.begin();
    while (iter != contacts.end()) {
      if (iter->getName() == assumedContact) return iter;
      iter++;
    }
    std::cout << "no such contact" << std::endl;
    return contacts.end();
  }
}

string Mobile::askCont() {
  string assumedContact;
  std::cout << "enter name or phone you want call: ";
  std::cin.ignore();
  std::getline(std::cin, assumedContact);
  return assumedContact;
}

void Mobile::call() {
  string assumedContact = askCont();
  auto iterToCont = findContact(assumedContact);
  if (iterToCont != contacts.end()) {
    std::cout << "CALL to " << iterToCont->getTel() << std::endl;
  } else std::cout << "no such contact" << std::endl;
}

void Mobile::sms() {
  string assumedContact = askCont();
  auto iterToCont = findContact(assumedContact);
  if (iterToCont != contacts.end()) {
    string smsText;
    std::cout << "enter the text for sms: ";
    std::cin.clear();
    std::getline(std::cin, smsText);
    std::cout << "sending sms to " << iterToCont->getTel() << ": " << std::endl;
    std::cout << "\t" << smsText << std::endl;
  } else std::cout << "no such contact" << std::endl;
}
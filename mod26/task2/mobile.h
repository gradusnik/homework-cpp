#pragma once
#include "contact.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Mobile {
    vector<Contact> contacts;
public:
    void addContact();
    vector<Contact>::iterator findContact(string assumedContact);
    static string askCont();
    void call();
    void sms();
};

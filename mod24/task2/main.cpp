#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using std::cout, std::cin, std::string;

struct birthD {
  string name;
  std::tm b_d;
};

bool inputBDay(std::vector<birthD>& birthDays) {
  birthD currBD;
  cout << "enter next person name: ";
  cin >> currBD.name;
  if (currBD.name == "end") return false;
  cout << "\tenter current person year of birth: ";
  cin >> currBD.b_d.tm_year;
  cout << "\tenter current person month of birth: ";
  cin >> currBD.b_d.tm_mon;
  cout << "\tenter current person day of birth: ";
  cin >> currBD.b_d.tm_mday;
  birthDays.push_back(currBD);
  return true;
}

void sortBDs(std::vector<birthD>& birthDays) {
  if (!birthDays.empty()) {
    for (int i = 0; i < birthDays.size() - 1; ++i) {
      for (int j = 0; j < birthDays.size() - 1 - i; ++j) {
        if (birthDays[j].b_d.tm_mon > birthDays[j + 1].b_d.tm_mon) {
          auto temp = birthDays[j];
          birthDays[j] = birthDays[j + 1];
          birthDays[j + 1] = temp;
        }
      }
    }
  }
}

int main() {
  std::vector<birthD> birthDays(0);
  while (inputBDay(birthDays));
  sortBDs(birthDays);
  //cout << "BDs size " << birthDays.size() << std::endl;
  std::time_t t = std::time(nullptr);
  std::tm today = *std::localtime(&t);
  ++today.tm_mon;

//  cout << "today " << today.tm_mon << "/" << today.tm_mday << "/" <<  std::endl;
//  for (int i = 0; i < birthDays.size(); ++i) {
//    cout << birthDays[i].name << " " << birthDays[i].b_d.tm_mon << "/" << birthDays[i].b_d.tm_mday << std::endl;
//  }

  // finding next BD
  for (int i = 0; i < birthDays.size(); ++i) {
    if (birthDays[i].b_d.tm_mon == today.tm_mon && birthDays[i].b_d.tm_mday == today.tm_mday) {
      cout << "happy BirthDay " << birthDays[i].name << std::endl;
      for (int j = i + 1; j < birthDays.size(); ++j) {
        if (birthDays[j].b_d.tm_mon == today.tm_mon && birthDays[j].b_d.tm_mday == today.tm_mday) {
          cout << "happy BirthDay " << birthDays[j].name << std::endl;
        } else break;
      }
      break;
    } else if (birthDays[i].b_d.tm_mon == today.tm_mon && birthDays[i].b_d.tm_mday >= today.tm_mday) {
      cout << "nearest BD have next persons: " << std::endl;
      cout << birthDays[i].name << " " << birthDays[i].b_d.tm_mon << "/" << birthDays[i].b_d.tm_mday << std::endl;
      for (int j = i + 1; j < birthDays.size(); ++j) {
        if (birthDays[j].b_d.tm_mon == birthDays[i].b_d.tm_mon && birthDays[j].b_d.tm_mday == birthDays[i].b_d.tm_mday) {
          cout << birthDays[j].name << " " << birthDays[j].b_d.tm_mon << "/" << birthDays[j].b_d.tm_mday << std::endl;
        } else break;
      }
      break;
    } else if (birthDays[i].b_d.tm_mon > today.tm_mon) {
      cout << "nearest BD have next persons: " << std::endl;
      cout << birthDays[i].name << " " << birthDays[i].b_d.tm_mon << "/" << birthDays[i].b_d.tm_mday << std::endl;
      for (int j = i + 1; j < birthDays.size(); ++j) {
        if (birthDays[j].b_d.tm_mon == birthDays[i].b_d.tm_mon && birthDays[j].b_d.tm_mday == birthDays[i].b_d.tm_mday) {
          cout << birthDays[j].name << " " << birthDays[j].b_d.tm_mon << "/" << birthDays[j].b_d.tm_mday << std::endl;
        } else break;
      }
      break;
    }
    if (i == birthDays.size() - 1) cout << "no near BD" << std::endl;
  }
  return 0;
}

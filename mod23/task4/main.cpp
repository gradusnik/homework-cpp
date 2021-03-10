#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

int nominal(char c) {
  if (c == '1') return 100;
  else if (c == '2') return 200;
  else if (c == '3') return 500;
  else if (c == '4') return 1000;
  else if (c == '5') return 2000;
  else if (c == '6') return 5000;
  return 0;
}

int SUM(std::vector<char> arr){
  int sum(0);
  for (int i = 0; i < arr.size(); ++i) {
    sum += nominal(arr[i]);
  }
  return sum;
}

bool seekSum(std::vector<char> arr, std::vector<char>& res, int sum) {
  int currSum = SUM(arr);
  if (currSum == sum) {
    for (int i = 0; i < arr.size(); ++i) {
      res.push_back(arr[i]);
    }
    return true;
  } else if (currSum > sum){
    for (int i = 0; i < arr.size(); ++i) {
      std::vector<char> subArr(0);
      for (int j = 0; j < arr.size(); ++j) {
        if (j == i) continue;
        subArr.push_back(arr[j]);
        if (seekSum(subArr, res, sum)) return true;
      }
    }
  }
  return false;
}

void takingNotes(std::vector<char> &arr, std::vector<char> notes) {
  for (int i = 0; i < notes.size(); ++i) {
    for (int j = arr.size() - 1; j >= 0; --j) {
      if (notes[i] == arr[j]) {
        arr[j] = arr.back();
        arr.pop_back();
        break;
      }
    }
  }
}

int main() {
  std::srand(std::time(nullptr));
  std::ifstream ATM("atm.bin", std::ios::binary);
  std::vector<char> banknotes(0);
  int size(0);
  if (ATM.is_open()) {
    ATM.seekg(0, std::ios::end);
    if (ATM.tellg() == -1) {
      size = 0;
    } else {
      size = ATM.tellg();
    }
    ATM.seekg(0);
    for (int i = 0; i < size; ++i) {
      char c[1];
      ATM.read(c, 1);
      banknotes.push_back(*c);
    }
    ATM.close();
    //std::cout << "size: " << size << std::endl;
  } else std::cout << "failure of opening file" << std::endl;

  char mode;
  std::cout << "for charge ATM enter \"+\", else if you wanna get money enter \"-\": ";
  std::cin >> mode;
  std::ofstream ATMout;
  if (mode == '+') {
    ATMout.open("atm.bin", std::ios::binary | std::ios::app);
    if (ATMout.is_open()) {
      char banknote[1];
      int count = 1000 - size;
      ATM.seekg(size);
      for (int i = 0; i < count; ++i) {
        // banknotes coding '1' - 100, '2' - 200, '3' - 500, '4' - 1000, '5' - 2000, '6' - 5000
        banknote[0] = std::to_string((std::rand() % 6 + 1))[0];
        ATMout.write(banknote, 1);
      }
      std::cout << "atm is full" << std::endl;
    } else std::cerr << "file not found" << std::endl;
    ATMout.close();
  } else if (mode == '-') {
    ATMout.open("atm.bin", std::ios::binary);
    if (ATMout.is_open()) {
      int askingSum(0);
      std::cout << "enter the sum you wanna get: ";
      std::cin >> askingSum;
      std::vector<char> toGive(0);
      if (askingSum % 100 == 0 && seekSum(banknotes, toGive, askingSum)) {
        std::cout << "sum is being given..." << std::endl;
        takingNotes(banknotes, toGive);
        for (int i = 0; i < banknotes.size(); ++i) {
          char* c = &banknotes[i];
          ATMout.write(c, 1);
        }
      } else {
        for (int i = 0; i < banknotes.size(); ++i) {
          char* c = &banknotes[i];
          ATMout.write(c, 1);
        }
        std::cout << "sum can not be given" << std::endl;
      }
    } else std::cerr << "file not found" << std::endl;
  } else std::cerr << "incorrect input" << std::endl;
  return 0;
}

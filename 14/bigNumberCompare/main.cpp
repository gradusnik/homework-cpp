#include <iostream>
#include <string>

bool correctModule(std::string line) {
  int dotsQuantity(0), digitsQuantity(0);
  for (int i = 0; i < line.length(); ++i) {
    if (line[i] == '.') ++dotsQuantity;
    else if (line[i] >= '0' && line[i] <= '9') ++digitsQuantity;
    else return false;
    if (dotsQuantity > 1) return false;
  }
  if (digitsQuantity == 0) return false;
  return true;
}

bool correctInput(std::string line) {
  if (line[0] == '-') {
    line = line.substr(1,(line.length() - 1));
    return correctModule(line);
  }
  else return correctModule(line);
}

std::string takeIntegerModule(std::string line) {
  std::string intMod;
  int i = line.find('.');
  if (line[0] == '-') intMod = line.substr(1,i - 1);
  else intMod = line.substr(0, i);
  while (intMod[0] == '0') {
    intMod = intMod.substr(1, intMod.length() - 1);
  }
  return intMod;
}

std::string takeFraction(std::string line) {
  std::string fraction;
  int i = line.find('.');
  if (i == std::string::npos) return "0";
  else fraction = line.substr(i + 1, line.length() - i);
  return fraction;
}

std::string addZerosToFraction(std::string line, int n) {
  for (int i = 0; i < n; ++i) {
    line += '0';
  }
  return line;
}

int compareParts(std::string line1, std::string line2) {
  for (int i = 0; i < line1.length(); ++i) {
    if (line1[i] > line2[i]) return 1;
    else if (line2[i] > line1[i]) return 2;
  }
  return 0;
}

int main() {
  std::string firstNumber, secondNumber;
  std::cout << "enter first number: ";
  std::cin >> firstNumber;
  std::cout << "enter second number: ";
  std::cin >> secondNumber;
  std::string firstInteger = takeIntegerModule(firstNumber);
  std::string secondInteger = takeIntegerModule(secondNumber);
  std::string firstFraction = takeFraction(firstNumber);
  std::string secondFraction = takeFraction(secondNumber);
  int n = firstFraction.length() - secondFraction.length();
  if (n > 0) secondFraction = addZerosToFraction(secondFraction, n);
  else if (n < 0) firstFraction = addZerosToFraction(firstFraction, -n);
  bool bothFractionsZero = false;
  for (int i = 0; i < firstFraction.length(); ++i) {
    if (firstFraction[i] != '0' || secondFraction[i] != '0') break;
    else if (i == firstFraction.length() - 1 && firstFraction[i] == '0' && secondFraction[i] == '0')
      bothFractionsZero = true;
  }
  // comparing numbers
  int compareResult(-1);
  if (firstInteger.empty() && secondInteger.empty() && bothFractionsZero) compareResult = 0;
  else if (firstNumber[0] == '-' && secondNumber[0] == '-') {
    if (firstInteger.length() > secondInteger.length()) compareResult = 2;
    else if (secondInteger.length() > firstInteger.length()) compareResult = 1;
    else {
      if (compareParts(firstInteger, secondInteger) == 0)
        compareResult = compareParts(firstFraction, secondFraction) + (3 - 2 * compareParts(firstFraction, secondFraction));
      else compareResult = compareParts(firstInteger, secondInteger) + (3 - 2 * compareParts(firstInteger, secondInteger));
    }
  }
  else if (firstNumber[0] == '-' && secondNumber[0] != '-') compareResult = 2;
  else if (firstNumber[0] != '-' && secondNumber[0] == '-') compareResult = 1;
  else if (firstNumber[0] != '-' && secondNumber[0] != '-') {
    if (firstInteger.length() > secondInteger.length()) compareResult = 1;
    else if (secondInteger.length() > firstInteger.length()) compareResult = 2;
    else {
      if (compareParts(firstInteger, secondInteger) == 0)
        compareResult = compareParts(firstFraction, secondFraction);
      else compareResult = compareParts(firstInteger, secondInteger);
    }
  }
  // output result
  if (correctInput(firstNumber) && correctInput(secondNumber)) {
    if (compareResult == 1) std::cout << "more\n";
    else if (compareResult == 2) std::cout << "less\n";
    else if (compareResult == 0) std::cout << "equal\n";
    else std::cout << "bad work\n";
  }
  //
  return 0;
}



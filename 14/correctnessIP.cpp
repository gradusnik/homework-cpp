#include <iostream>
#include <string>

bool checkSubLine(std::string line) { // return true if incorrect
    int len = line.length();
    if (len > 3 || len < 1) return true;
    else if (len > 1 && line[0] == '0') return true;
    for (int i = 0; i < len; ++i) {
        if (line[i] < '0' || line[i] > '9') return true;
    }
    int num = std::stoi(line);
    if (num < 0 || num > 255) return true;
    return false;
}

bool checkLineForIP(std::string line) {
    int length = line.length();
    if (line[0] == '.' || line[length - 1] == '.') return false;
    else {
        int numOfDots(0);
        std::string subLine;
        for (int i = 0; i < length; ++i) {
            if (line[i] != '.') {
                subLine += line[i];
            }
            else {
                if (checkSubLine(subLine)) return false;
                ++numOfDots;
                subLine = "";
                continue;
            }
        }
        if (numOfDots != 3) return false;
        if (checkSubLine(subLine)) return false;  // checking last subline
    }
    return true;
}

int main() {
    std::string presumedAddress;
    std::cout << "enetr the IP address: ";
    std::cin >> presumedAddress;
    checkLineForIP(presumedAddress) ?
    std::cout << "YES\n" :
    std::cout << "NO\n";
}


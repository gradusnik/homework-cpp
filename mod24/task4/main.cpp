#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

struct character {
    std::string name;
    int health = 50;
    int armor = 0;
    int damage = 15;
};

struct coordinate {
    int x = 0;
    int y = 0;
};

void checkAvailableCoordinates(int &x, int &y, coordinate coords[]) {
  for (int i(0); i < 6; ++i) {
    if (x == coords[i].x && y == coords[i].y) {
      ++x; ++y;
      checkAvailableCoordinates(x, y, coords);
    }
  }
}

bool coincide(int n, int m , coordinate coords[], character chars[]) {
  for (int i(0); i < 5; ++i) {
    if (coords[i].x == m && coords[i].y == n && chars[i].health > 0) return true;
  }
  return false;
}

void displayField(coordinate coords[], character chars[]) {
  for (int i(0); i < 40; ++i) {
    for (int j(0); j < 40; ++j) {
      if (coincide(i, j, coords, chars)) std::cout << 'E';
      else if (i == coords[5].y && j == coords[5].x) std::cout << 'P';
      else std::cout << '.';
    }
    std::cout << std::endl;
  }
}

void saving(std::ofstream &file, character arr[], coordinate coords[]) {
  for (int i = 0; i < 6; ++i) {
    file.write((char*)&arr[i], sizeof arr[i]);
  }
  for (int i = 0; i < 6; ++i) {
    file.write((char*)&coords[i], sizeof coords[i]);
  }
}

void loading(std::ifstream &file, character arr[], coordinate coords[]) {
  for (int i = 0; i < 6; ++i) {
    file.read((char*)&arr[i], sizeof arr[i]);
  }
  for (int i = 0; i < 6; ++i) {
    file.read((char*)&coords[i], sizeof coords[i]);
  }
}

bool emptyDir(const std::string &direction, int ch, coordinate coords[], character chars[]) {
  if (direction == "left") {
    if (coords[ch].x == 0) return false;
    for (int i = 0; i < 5; ++i) {
      if (i == ch) continue;
      else if (coords[i].x == coords[ch].x - 1 && coords[i].y == coords[ch].y && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "top") {
    if (coords[ch].y == 0) return false;
    for (int i = 0; i < 5; ++i) {
      if (i == ch) continue;
      else if (coords[i].x == coords[ch].x && coords[i].y == coords[ch].y - 1 && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "right") {
    if (coords[ch].x == 39) return false;
    for (int i = 0; i < 5; ++i) {
      if (i == ch) continue;
      else if (coords[i].x == coords[ch].x + 1 && coords[i].y == coords[ch].y && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "bottom") {
    if (coords[ch].y == 39) return false;
    for (int i = 0; i < 5; ++i) {
      if (i == ch) continue;
      else if (coords[i].x == coords[ch].x && coords[i].y == coords[ch].y + 1 && chars[i].health > 0) return false;
    }
    return true;
  }
  return false;
}

void damage(character chars[],const int &damagedChar, const int &hittingChar = 5){
  if (chars[damagedChar].armor > chars[hittingChar].damage) {
    chars[damagedChar].armor -= chars[hittingChar].damage;
  } else {
    chars[damagedChar].armor = 0;
    chars[damagedChar].health -= (chars[hittingChar].damage - chars[damagedChar].armor);
  }
}

void makeTurn(int charNum, coordinate coords[], character chars[], const std::string &direction) {
  bool turned = false;
  if (charNum == 5) {
    if (direction == "left") {
      for (int i = 0; i < 5; ++i) {
        if (coords[i].x == coords[5].x - 1 && coords[i].y == coords[5].y && chars[i].health > 0) {
          damage(chars, i);
          turned = true;
        }
      }
      if (!turned && coords[5].x > 0) --coords[5].x;
    } else if (direction == "top") {
      for (int i = 0; i < 5; ++i) {
        if (coords[i].x == coords[5].x && coords[i].y == coords[5].y - 1 && chars[i].health > 0) {
          damage(chars, i);
          turned = true;
        }
      }
      if (!turned && coords[5].y > 0) --coords[5].y;
    } else if (direction == "right") {
      for (int i = 0; i < 5; ++i) {
        if (coords[i].x == coords[5].x + 1 && coords[i].y == coords[5].y && chars[i].health > 0) {
          damage(chars, i);
          turned = true;
        }
      }
      if (!turned && coords[5].x < 39) ++coords[5].x;
    } else if (direction == "bottom") {
      for (int i = 0; i < 5; ++i) {
        if (coords[i].x == coords[5].x && coords[i].y == ++coords[5].y && chars[i].health > 0) {
          damage(chars, i);
          turned = true;
        }
      }
      if (!turned && coords[5].y < 39) ++coords[5].y;
    }
  } else {
    if (direction == "left") {
      if (coords[5].x == coords[charNum].x - 1 && coords[5].y == coords[charNum].y && chars[5].health > 0) damage(chars, 5, charNum);
      else if (emptyDir(direction, charNum, coords, chars)) --coords[charNum].x;
    } else if (direction == "top") {
      if (coords[5].x == coords[charNum].x && coords[5].y == coords[charNum].y - 1 && chars[5].health > 0) damage(chars, 5, charNum);
      else if (emptyDir(direction, charNum, coords, chars)) --coords[charNum].y;
    } if (direction == "right") {
      if (coords[5].x == coords[charNum].x + 1 && coords[5].y == coords[charNum].y && chars[5].health > 0) damage(chars, 5, charNum);
      else if (emptyDir(direction, charNum, coords, chars)) ++coords[charNum].x;
    } if (direction == "bottom") {
      if (coords[5].x == coords[charNum].x && coords[5].y == coords[charNum].y + 1 && chars[5].health > 0) damage(chars, 5, charNum);
      else if (emptyDir(direction, charNum, coords, chars)) ++coords[charNum].y;
    }
  }
}

std::string genDir() {
  int n = std::rand() % 4;
  if (n == 0) return "left";
  else if (n == 1) return "top";
  else if (n == 2) return "right";
  else if (n == 3) return "bottom";
}

bool checkWin(character chars[]) {
  if (chars[5].health <= 0) return true;
  for (int i = 0; i < 5; ++i) {
    if (chars[i].health > 0) return false;
  }
  return true;
}

int main() {
  std::srand(std::time(nullptr));
  coordinate fieldState[6];
  character characters[6];
  // enemies data
  for (int i(0); i < 5; ++i) {
    characters[i].name = "Enemy #" + std::to_string(i);
    characters[i].health = 50 + std::rand() % 100;
    characters[i].armor = std::rand() % 50;
    characters[i].damage = 15 + std::rand() % 15;
  }
  // player data (player - characters[5])
  std::cout << "\tcreating the player character ..." << std::endl;
  std::cout << "enter the player name: ";
  std::cin >> characters[5].name;
  std::cout << "enter the player health: ";
  std::cin >> characters[5].health;
  std::cout << "enter the player armor: ";
  std::cin >> characters[5].armor;
  std::cout << "enter the player damage: ";
  std::cin >> characters[5].damage;
  std::cout << "enter the player's coordinates(0 - 39): " << std::endl;
  std::cout << "\tx: ";
  std::cin >> fieldState[5].x; fieldState[5].x %= 40;
  std::cout << "\ty: ";
  std::cin >> fieldState[5].y; fieldState[5].y %= 40;
  // coordinates for enemies
  for (int i(0); i < 5; ++i) {
    int x = std::rand() % 40;
    int y = std::rand() % 40;
    checkAvailableCoordinates(x, y, fieldState);
    fieldState[i].x = x;
    fieldState[i].y = y;
  }
  displayField(fieldState, characters);
  bool win = false;
  std::string command;
  while (!win) {
    std::cout << characters[5].name << " choose the command: ";
    std::cin >> command;
    if (command == "save") {
      std::ofstream file1("save.bin", std::ios::binary);
      if (file1.is_open()) {
        saving(file1, characters, fieldState);
        file1.close();
      }
    } else if (command == "load") {
      std::ifstream file2("save.bin", std::ios::binary);
      if (file2.is_open()) {
        loading(file2, characters, fieldState);
        file2.close();
      }
      displayField(fieldState, characters);
    } else if (command == "left" || command == "top" || command == "right" || command == "bottom") {
      makeTurn(5, fieldState, characters, command);
      for (int i = 0; i < 5; ++i) {
        if (characters[i].health > 0) {
          std::string direction = genDir();
          makeTurn(i, fieldState, characters, direction);
        }
      }
      displayField(fieldState, characters);
      win = checkWin(characters);
    } else std::cerr << "there is not such command!" << std::endl;
  }
  (characters[5].health > 0) ? std::cout << "player win" : std::cout << "player lose";
  return 0;
}

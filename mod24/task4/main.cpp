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
    int x = 0;
    int y = 0;
};

void checkAvailableCoordinates(int &x, int &y, character chars[], int num) {
  for (int i(0); i < num; ++i) {
    if (x == chars[i].x && y == chars[i].y) {
      ++x; ++y;
      checkAvailableCoordinates(x, y, chars, num);
    }
  }
}

bool coincide(int n, int m, character chars[], int player) {
  for (int i(0); i < player; ++i) {
    if (chars[i].x == m && chars[i].y == n && chars[i].health > 0) return true;
  }
  return false;
}

void displayField(character chars[], int player) {
  for (int i(0); i < 40; ++i) {
    for (int j(0); j < 40; ++j) {
      if (coincide(i, j, chars, player)) std::cout << 'E';
      else if (i == chars[player].y && j == chars[player].x) std::cout << 'P';
      else std::cout << '.';
    }
    std::cout << std::endl;
  }
}

void saving(std::ofstream &file, character chars[], int amount) {
  for (int i = 0; i < amount; ++i) {
    file.write((char*)&chars[i], sizeof chars[i]);
  }
}

void loading(std::ifstream &file, character chars[], int amount) {
  for (int i = 0; i < amount; ++i) {
    file.read((char*)&chars[i], sizeof chars[i]);
  }
}

bool emptyDir(const std::string &direction, int ch, character chars[], int player) {
  if (direction == "left") {
    if (chars[ch].x == 0) return false;
    for (int i = 0; i < player; ++i) {
      if (i == ch) continue;
      else if (chars[i].x == chars[ch].x - 1 && chars[i].y == chars[ch].y && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "top") {
    if (chars[ch].y == 0) return false;
    for (int i = 0; i < player; ++i) {
      if (i == ch) continue;
      else if (chars[i].x == chars[ch].x && chars[i].y == chars[ch].y - 1 && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "right") {
    if (chars[ch].x == 39) return false;
    for (int i = 0; i < player; ++i) {
      if (i == ch) continue;
      else if (chars[i].x == chars[ch].x + 1 && chars[i].y == chars[ch].y && chars[i].health > 0) return false;
    }
    return true;
  } else if (direction == "bottom") {
    if (chars[ch].y == 39) return false;
    for (int i = 0; i < player; ++i) {
      if (i == ch) continue;
      else if (chars[i].x == chars[ch].x && chars[i].y == chars[ch].y + 1 && chars[i].health > 0) return false;
    }
    return true;
  }
  return false;
}

void damage(character chars[],const int &damagedChar, const int &hittingChar){
  if (chars[damagedChar].armor > chars[hittingChar].damage) {
    chars[damagedChar].armor -= chars[hittingChar].damage;
  } else {
    chars[damagedChar].armor = 0;
    chars[damagedChar].health -= (chars[hittingChar].damage - chars[damagedChar].armor);
  }
}

void makeTurn(int charNum, character chars[], const std::string &direction, int player) {
  bool turned = false;
  if (charNum == player) {
    if (direction == "left") {
      for (int i = 0; i < player; ++i) {
        if (chars[i].x == chars[player].x - 1 && chars[i].y == chars[player].y && chars[i].health > 0) {
          damage(chars, i, player);
          turned = true;
        }
      }
      if (!turned && chars[player].x > 0) --chars[player].x;
    } else if (direction == "top") {
      for (int i = 0; i < player; ++i) {
        if (chars[i].x == chars[player].x && chars[i].y == chars[player].y - 1 && chars[i].health > 0) {
          damage(chars, i, player);
          turned = true;
        }
      }
      if (!turned && chars[player].y > 0) --chars[player].y;
    } else if (direction == "right") {
      for (int i = 0; i < player; ++i) {
        if (chars[i].x == chars[player].x + 1 && chars[i].y == chars[player].y && chars[i].health > 0) {
          damage(chars, i, player);
          turned = true;
        }
      }
      if (!turned && chars[player].x < 39) ++chars[player].x;
    } else if (direction == "bottom") {
      for (int i = 0; i < player; ++i) {
        if (chars[i].x == chars[player].x && chars[i].y == chars[player].y + 1 && chars[i].health > 0) {
          damage(chars, i, player);
          turned = true;
        }
      }
      if (!turned && chars[player].y < 39) ++chars[player].y;
    }
  } else {
    if (direction == "left") {
      if (chars[player].x == chars[charNum].x - 1 && chars[player].y == chars[charNum].y && chars[player].health > 0) damage(chars, player, charNum);
      else if (emptyDir(direction, charNum, chars, player)) --chars[charNum].x;
    } else if (direction == "top") {
      if (chars[player].x == chars[charNum].x && chars[player].y == chars[charNum].y - 1 && chars[player].health > 0) damage(chars, player, charNum);
      else if (emptyDir(direction, charNum, chars, player)) --chars[charNum].y;
    } if (direction == "right") {
      if (chars[player].x == chars[charNum].x + 1 && chars[player].y == chars[charNum].y && chars[player].health > 0) damage(chars, player, charNum);
      else if (emptyDir(direction, charNum, chars, player)) ++chars[charNum].x;
    } if (direction == "bottom") {
      if (chars[player].x == chars[charNum].x && chars[player].y == chars[charNum].y + 1 && chars[player].health > 0) damage(chars, player, charNum);
      else if (emptyDir(direction, charNum, chars, player)) ++chars[charNum].y;
    }
  }
}

std::string genDir() {
  int n = std::rand() % 4;
  if (n == 0) return "left";
  else if (n == 1) return "top";
  else if (n == 2) return "right";
  else return "bottom";
}

bool checkWin(character chars[], int player) {
  if (chars[player].health <= 0) return true;
  for (int i = 0; i < player; ++i) {
    if (chars[i].health > 0) return false;
  }
  return true;
}

int main() {
  std::srand(std::time(nullptr));
  int charsAmount = 6;
  character characters[charsAmount];
  int player = 5;
  // enemies data
  for (int i(0); i < player; ++i) {
    characters[i].name = "Enemy #" + std::to_string(i);
    characters[i].health = 50 + std::rand() % 101;
    characters[i].armor = std::rand() % 51;
    characters[i].damage = 15 + std::rand() % 16;
  }
  // player data (player - characters[5])
  std::cout << "\tcreating the player character ..." << std::endl;
  std::cout << "enter the player name: ";
  std::cin >> characters[player].name;
  std::cout << "enter the player health: ";
  std::cin >> characters[player].health;
  std::cout << "enter the player armor: ";
  std::cin >> characters[player].armor;
  std::cout << "enter the player damage: ";
  std::cin >> characters[player].damage;
  std::cout << "enter the player's coordinates(0 - 39): " << std::endl;
  std::cout << "\tx: ";
  std::cin >> characters[player].x; characters[player].x %= 40;
  std::cout << "\ty: ";
  std::cin >> characters[player].y; characters[player].y %= 40;
  // coordinates for enemies
  for (int i(0); i < player; ++i) {
    int x = std::rand() % 40;
    int y = std::rand() % 40;
    checkAvailableCoordinates(x, y, characters, charsAmount);
    characters[i].x = x;
    characters[i].y = y;
  }
  displayField(characters, player);
  bool win = false;
  std::string command;
  while (!win) {
    std::cout << characters[player].name << " choose the command: ";
    std::cin >> command;
    if (command == "save") {
      std::ofstream file1("save.bin", std::ios::binary);
      if (file1.is_open()) {
        saving(file1, characters, charsAmount);
        file1.close();
      } else std::cerr << "file not found" << std::endl;
    } else if (command == "load") {
      std::ifstream file2("save.bin", std::ios::binary);
      if (file2.is_open()) {
        loading(file2, characters, charsAmount);
        file2.close();
      } else std::cerr << "file not found" << std::endl;
      displayField(characters, player);
    } else if (command == "left" || command == "top" || command == "right" || command == "bottom") {
      makeTurn(player, characters, command, player);
      for (int i = 0; i < player; ++i) {
        if (characters[i].health > 0) {
          std::string direction = genDir();
          makeTurn(i, characters, direction, player);
        }
      }
      displayField(characters, player);
      win = checkWin(characters, player);
    } else std::cerr << "there is not such command!" << std::endl;
  }
  std::cout << ((characters[player].health > 0) ?  "player win" :  "player lose");
  return 0;
}

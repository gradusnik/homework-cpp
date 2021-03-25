#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

bool coincide(int n, int m , coordinate coords[]) {
  for (int i(0); i < 5; ++i) {
    if (coords[i].x == m && coords[i].y == n) return true;
  }
  return false;
}

void displayField(coordinate coords[]) {
  for (int i(0); i < 40; ++i) {
    for (int j(0); j < 40; ++j) {
      if (coincide(i, j, coords)) std::cout << 'E';
      else if (i == coords[5].y && j == coords[5].x) std::cout << 'P';
      else std::cout << '.';
    }
    std::cout << std::endl;
  }
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
  // player data
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

  displayField(fieldState);

  //

  return 0;
}

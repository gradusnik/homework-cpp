#include <iostream>
#include <string>
#include <vector>

enum roomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    KIDS_ROOM,
    LIVING_ROOM
};

struct room {
    roomType type;
    double square;
};
void fillRoom(room &room) {
  std::cout << "which type of room" << std::endl
            << "choose number of: 0 - bedroom" << std::endl
            << "                  1 - kitchen" << std::endl
            << "                  2 - bathroom" << std::endl
            << "                  3 - kids room" << std::endl
            << "                  4 - living room" << std::endl;
  int n(0);
  std::cin >> n;
  if (n == 0) room.type = BEDROOM;
  else if (n == 1) room.type = KITCHEN;
  else if (n == 2) room.type = BATHROOM;
  else if (n == 3) room.type = KIDS_ROOM;
  else if (n == 4) room.type = LIVING_ROOM;
  std::cout << "which square the room have: ";
  std::cin >> room.square;
}

struct floor {
    int consecutiveNumber;
    double height;
    std::vector<room> rooms;
};
void fillFloor(floor &floor) {
  std::cout << "which height the floor have: ";
  std::cin >> floor.height;
  std::cout << "how many rooms the floor have: ";
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cout << "\tfilling next room..." << std::endl;
    room currRoom;
    fillRoom(currRoom);
    floor.rooms.push_back(currRoom);
  }
}

enum buildingType{
    GARAGE,
    BARN,
    BATHHOUSE
};
struct building {
    buildingType type;
    double square;
    bool furnace = false;
};
void fillBuilding(building &building) {
  std::cout << "which type of current building" << std::endl
            << "choose number of: 0 - garage" << std::endl
            << "                  1 - barn" << std::endl
            << "                  2 - bathhouse" << std::endl;
  int n(0);
  std::cin >> n;
  if (n == 0) building.type = GARAGE;
  else if (n == 1) building.type = BARN;
  else if (n == 2) {
    building.type = BATHHOUSE;
    std::cout << "does bathhouse have a furnace?(enter \'yes\' if does)";
    std::string answer;
    std::cin >> answer;
    if (answer == "yes") building.furnace = true;
  }
  std::cout << "which square the building is occupied: ";
  std::cin >> building.square;
}

struct house {
    double square;
    bool furnace = false;
    std::vector<floor> floors;
};
void fillHouse(house &house) {
  std::cout << "which square the house is occupied: ";
  std::cin >> house.square;
  std::cout << "do the house have a furnace?(type \'yes\' if yes): ";
  std::string answ;
  std::cin >> answ;
  if (answ == "yes") house.furnace = true;
  std::cout << "how many floors the house have: ";
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    floor currFloor;
    currFloor.consecutiveNumber = i + 1;
    std::cout << "\tfilling " << i + 1 << " floor..." << std::endl;
    fillFloor(currFloor);
    house.floors.push_back(currFloor);
  }
}

struct parcel {
    int id;
    double square;
    house _house;
    std::vector<building> buildings;
};
void fillParcel(parcel &parcel) {
  //std::cout << "\tfilling next parcel" << std::endl;
  std::cout << "which square current parcel is occupied: ";
  std::cin >> parcel.square;
  house currHouse;
  fillHouse(currHouse);
  parcel._house = currHouse;
  std::cout << "how many buildings the parcel have: ";
  int n(0);
  std::cin >> n;
  building currBuilding;
  for (int i = 0; i < n; ++i) {
    fillBuilding(currBuilding);
    parcel.buildings.push_back(currBuilding);
  }
}

int main() {
  int num(0);
  std::cout << "enter the parcels number: ";
  std::cin >> num;
  parcel parcels[num];
  for (int i = 0; i < num; ++i) {
    std::cout << "filling parcel with id " << i << std::endl;
    parcels[i].id = i;
    fillParcel(parcels[i]);
  }
      // some output
//  std::cout << "parcel id: " << parcels[0].id << " square " << parcels[0].square << std::endl
//            << "house square " << parcels[0]._house.square << " furnace " << parcels[0]._house.furnace << std::endl
//            << "buildings\t";
//  for (int i = 0; i < parcels[0].buildings.size(); ++i) {
//    std::cout << parcels[0].buildings[i].type << "/" << parcels[0].buildings[i].square << " ";
//  }
//  std::cout << std::endl;
//
//  std::cout << "house have " << parcels[0]._house.floors.size() << " floors" << std::endl;
//  std::cout << "1 floor: ";
//  for (int i = 0; i < parcels[0]._house.floors[0].rooms.size(); ++i) {
//    std::cout << parcels[0]._house.floors[0].rooms[i].type << "/" << parcels[0]._house.floors[0].rooms[i].square << " ";
//  }
//  std::cout << std::endl;
  return 0;
}

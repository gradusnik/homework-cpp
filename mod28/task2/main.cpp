#include <iostream>
#include <thread>
#include <mutex>

std::string station("train station");
std::mutex station_access;

void output(char id, std::string& comm, bool& dep) {
  std::cout << "train " << id << " on the " << station << std::endl;
  std::cout << "train " << id << " expect the command to depart: " << std::endl;
  std::cin >> comm;
  dep = true;
  std::cout << "train " << id << " is departed" << std::endl;
}

class Train {
public:
    char ID;
    int timeToStation;
    Train(){};
    Train(char inCh, int inTime): ID(inCh), timeToStation(inTime) {};
};

void travelling(Train train) {
  std::string depart;
  bool departed(false);
  std::cout << "train " << train.ID << " in the way" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(train.timeToStation));
  if (station_access.try_lock()) {
    output(train.ID, depart, departed);
    station_access.unlock();
  } else std::cout << "train " << train.ID << " is waiting outside" << std::endl;
  if (!departed) {
    station_access.lock();
    output(train.ID, depart, departed);
    station_access.unlock();
  }
}

int main() {
  const int count(3);
  char id('A');
  int time(0);
  Train trains[count];
  for (int i = 0; i < count; ++i) {
    std::cout << "enter the  travel time for train " << id << ": ";
    std::cin >> time;
    Train temp = Train(id, time);
    trains[i] = temp;
    id++;
  }

  std::thread trainsMoving[count];
  for (int i = 0; i < count; ++i) {
    trainsMoving[i] = std::thread(travelling, trains[i]);
  }
  for (int i = 0; i < count; ++i) {
    trainsMoving[i].join();
  }
  return 0;
}

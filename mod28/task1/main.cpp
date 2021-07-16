#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::string message;
std::mutex mess_access;

class Swimmer{
    std::string name;
    double pace;
    double currRaceTime = 0;
public:
    Swimmer() {
        std::cout << "enter next swimmer name: ";
        std::cin >> name;
        std::cout << "enter next swimmer pace: ";
        std::cin >> pace;
        if (pace < 0.3) pace = 0.3;
        else if (pace > 3) pace = 4;
    }
    std::string getName() {
        return name;
    }
    double getPace() {
        return pace;
    }
    void setCurrRaceTime() {
        currRaceTime += 1;
    }
    double getCurrRaceTime() {
        return currRaceTime;
    }
};

void race(Swimmer* swimmer) {
    double distance(0);
    double finnish(10);
    double pace = swimmer->getPace();
    while (distance < finnish) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        distance += pace;
        swimmer->setCurrRaceTime();
        mess_access.lock();
        if (distance >= finnish) {
            message =  swimmer->getName() + " reached finnish";
        }
        else {
            message = swimmer->getName() + " reached distance of " + std::to_string(distance) + " meters";
        }
        std::cout << message << std::endl;
        mess_access.unlock();
    }
}

void sortSws(Swimmer swimmers[], int length) {
    for (int i = length; i > 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (swimmers[j].getCurrRaceTime() > swimmers[j + 1].getCurrRaceTime()) {
                Swimmer temp = swimmers[j + 1];
                swimmers[j + 1] = swimmers[j];
                swimmers[j] = temp;
            }
        }
    }
}

int main() {
    int count = 3;     // amount of swimmers
    Swimmer swimmers[count];
    std::thread threadz[count];
    for (int i = 0; i < count; ++i) {
        threadz[i] = std::thread(race, swimmers + i);
    }
    for (int i = 0; i < count; ++i) {
        threadz[i].join();
    }
    sortSws(swimmers, count);
    for (int i = 0; i < count; ++i) {
        std::cout << swimmers[i].getName() << " : " << swimmers[i].getCurrRaceTime() << std::endl;
    }
    return 0;
}

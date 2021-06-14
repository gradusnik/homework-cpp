#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class Track {
    std::string name;
    std::tm date;
    int duration;
public:
    void setValues() {
      date.tm_year = std::rand() % 121;
      date.tm_mon = std::rand() % 12 + 1;
      date.tm_mday = std::rand() % 31 + 1;
      duration = std::rand() % 1000 + 120;
    }
    void setName(std::string tName) {
      name = tName;
    }
    std::string getTrackName() {
      return name;
    }
    std::string getTrackCreationDate() {
      return std::to_string( 1900 + date.tm_year) + "/" + std::to_string(date.tm_mon);
    }
    int getTrackDuration() {
      return duration;
    }
};

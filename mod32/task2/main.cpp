#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "menuOptions.h"

int main() {
  std::map<std::string, FilmInfo> M;
  nlohmann::json filmList;
  std::ifstream file("filmList.json");
  if (file.is_open()) {
    file >> filmList;
    file.close();

    int filmCount = filmList.size();
    std::vector<std::string> films;
    for (auto &elem : filmList.items()) {
      films.push_back(elem.key());
    }

    std::string temp;
    for (int j = 0; j < filmCount; ++j) {                                                // putting data into Map
      FilmInfo filmInfo;
      filmInfo.Director = filmList[films[j]]["director"];
      temp = filmList[films[j]]["cast"];
      stringToVecS(temp, filmInfo.Cast);
      temp = filmList[films[j]]["writer"];
      stringToVecS(temp, filmInfo.Writer);
      temp = filmList[films[j]]["genres"];
      stringToVecS(temp, filmInfo.Genres);
      filmInfo.MaturityRating = filmList[films[j]]["maturityRating"];
      M[films[j]] = filmInfo;
    }

    std::map<std::string, std::vector<std::string>> ActorMap;
    for (int i = 0; i < filmCount; ++i) {
      int len = M[films[i]].Cast.size();
      for (int j = 0; j < len; ++j) {
        ActorMap[M[films[i]].Cast[j]].push_back(films[i]);
      }
    }

    std::map<std::string, std::vector<std::string>> GenresMap;
    for (int i = 0; i < filmCount; ++i) {
      int len = M[films[i]].Genres.size();
      for (int j = 0; j < len; ++j) {
        GenresMap[M[films[i]].Genres[j]].push_back(films[i]);
      }
    }
    std::vector<std::string> genres;
    for (auto el = GenresMap.begin(); el != GenresMap.end() ; ++el) {
      genres.push_back(el->first);
    }

    int c(0);
    while(c != -1) {                                                                        //menu
      std::cout << "we have info about " << films.size() << " films" << std::endl;
      std::cout << "press the number of item you interesting: " << std::endl;
      std::cout << "  1 - you are interesting a certain film" << std::endl;
      std::cout << "  2 - you are interesting a certain actor" << std::endl;
      std::cout << "  3 - you are interesting a certain genres" << std::endl;
      std::cout << "  -1 for exit" << std::endl;
      std::cin >> c;
      if (c == 1) menuFilm(M, films);
      else if (c == 2) menuActor(ActorMap);
      else if (c == 3) menuGenres(genres, GenresMap);
      else if (c != -1) std::cout << "no menu item, please enter again" << std::endl;
      else std::cout << "exit." << std::endl;
    }
  }
  return 0;
}

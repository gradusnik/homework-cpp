//
#pragma once

struct FilmInfo {
    std::string Director;
    std::vector<std::string> Cast;
    std::vector<std::string> Writer;
    std::vector<std::string> Genres;
    int MaturityRating = 18;
};

void stringToVecS(std::string &s, std::vector<std::string> &v) {
  v.resize(1);
  v[0] = "";
  int len = s.length();
  int j = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] == ',' && s[i + 1] == ' ') {
      j++; i+=2; v.resize(v.size() + 1);
    }
    v[j] += s[i];
  }
}

void displayItem( std::vector<std::string> &item, std::string name) {
  std::cout << name << ": ";
  int sz = item.size();
  for (int i = 0; i < sz; ++i) {
    std::cout << item[i] << ", ";
  }
  std::cout << std::endl;
}
void displayItem(std::string &item, std::string name = "Director") {
  std::cout << name << ": " << item << std::endl;
}
void displayItem(int &item, std::string name = "Maturity Rating") {
  std::cout << name << ": " << item << std::endl;
}

void displayFilmInfo(std::string &filmName, FilmInfo &filmInfo) {
  std::cout << "  \"" << filmName << "\"" << std::endl;
  displayItem(filmInfo.Director);
  displayItem(filmInfo.Cast, "Cast");
  displayItem(filmInfo.Writer, "Writer");
  displayItem(filmInfo.Genres, "Genres");
  displayItem(filmInfo.MaturityRating);
}

void menuFilm(std::map<std::string, FilmInfo> &m, std::vector<std::string> &films) {
  int select(-1);
  std::cout << "\twhich film you are interesting: " << std::endl;
  int count = films.size();
  for (int i = 0; i < count; ++i) {
    std::cout << "\t" << i << " - " << films[i] << std::endl;
  }
  std::cout << "\telse - back" << std::endl;
  std::cin >> select;
  if (select >= 0 && select <= count - 1) {
    FilmInfo filmInfo = m[films[select]];
    displayFilmInfo(films[select], filmInfo);
  }
  else std::cout << "\tback" << std::endl;
  std::cout << std::endl;
}

void menuActor(std::map<std::string, std::vector<std::string>> &ActMap) {
  std::string name;
  std::cout << "\twhich actor you are interesting, please enter name: ";
  std::cin.ignore();
  std::getline(std::cin, name);
  //
  std::map<std::string, std::vector<std::string>>::iterator it = ActMap.find(name);
  if (it != ActMap.end()) {
    std::cout << name << " took part in followings films: ";
    int count = ActMap[name].size();
    for (int i = 0; i < count; ++i) {
      std::cout << "\""<< ActMap[name][i] << "\"" << " ";
    }
    std::cout << std::endl;
  } else std::cout << "no actor" << std::endl;
  std::cout << std::endl;
}

void displayGenre(std::string name, std::map<std::string, std::vector<std::string>> &GenMap) {
  std::cout << "following film is " << name << " of genre:" << std::endl;
  int count = GenMap[name].size();
  for (int i = 0; i < count; ++i) {
    std::cout << "  " << GenMap[name][i] << std::endl;
  }
}
void menuGenres(std::vector<std::string> &genres, std::map<std::string, std::vector<std::string>> &GenMap) {
  int genCount = genres.size();
  std::cout << "\twhich genre do you prefer:" << std::endl;
  for (int i = 0; i < genCount; ++i) {
    std::cout << i << " - " << genres[i] << std::endl;
  }
  int select(-1);
  std::cout << "your select: ";
  std::cin >> select;
  if (select >= 0 && select <= genCount - 1) {
    displayGenre(genres[select], GenMap);
  } else if (select >= genCount || select < 0) {
    std::cout << "no item   ...back" << std::endl;
  }
  std::cout << std::endl;
}

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

struct Record {
    std::string Director;
    std::string Cast;
    std::string Writer;
    std::string Genres;
    int MaturityRating;
};

int main() {
  Record rec01;
  rec01.Director = "Adam McKay";
  rec01.Cast = "Leonardo DiCaprio, Jennifer Lawrence, Meryl Streep, Cate Blanchett, Rob Morgan, Jonah Hill, "
               "Mark Rylance, Tyler Perry, Timmothee Chalamet, Ariana Grande, Scott Mescudi, Michael Chiklis, "
               "Melany Lynskey, Himesh Patel, Tomer Sisley, Paul Guilfoyle, Robert Joy";
  rec01.Writer = "Adam McKay, David, Sirota";
  rec01.Genres = "Scii-Fi Movies, Comedies, Dramas";
  rec01.MaturityRating = 18;
  nlohmann::json record01;
  record01["Director"] = rec01.Director;
  record01["Cast"] = rec01.Cast;
  record01["Writer"] = rec01.Writer;
  record01["Genres"] = rec01.Genres;
  record01["MaturityRating"] = rec01.MaturityRating;
  std::ofstream json_file("dont_look_up.json");
  json_file << record01;
  json_file.close();
  return 0;
}

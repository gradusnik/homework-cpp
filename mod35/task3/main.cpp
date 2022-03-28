#include <iostream>
#include <filesystem>

int main() {
  std::string myDirTest = "D:\\myDirTest";
  std::string extension = ".txt";
  std::filesystem::path P(myDirTest);
  auto recurFileNameByExtension = [](std::filesystem::path const &P, const std::string &ext) ->int {
    int count(0);
    for (auto &p : std::filesystem::recursive_directory_iterator(P)) {
      if (p.path().extension() == ext) {
        std::cout << p.path() << std::endl;
        ++count;
      }
    }
      return count;
  };
  std::cout << recurFileNameByExtension(myDirTest, extension);
  return 0;
}

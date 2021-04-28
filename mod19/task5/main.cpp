#include <iostream>
#include <string>
#include <fstream>

void shiftPos (int &p, bool arr[]) {
  int i(0);
  while (arr[(p + i) % 13]) {
    ++i;
  }
  p += i; p %= 13;
}

void playingSector (int p, int &players, int &watchers) {
  std::string quesFilePath = "question" + std::to_string(p + 1) + ".txt";
  std::ifstream question;
  question.open(quesFilePath);
  std::string quesText;
  if (question.is_open()) {
    std::cout << "sector " << p + 1 << " question" << std::endl;
    while (!question.eof()) {
      question >> quesText;
      std::cout << quesText << " ";
    }
  } else std::cout << "something wrong" << std::endl;
  std::string plAnswer;
  std::cout << std::endl;
  std::cout << "enter the answer (use low case): ";
  std::cin >> plAnswer;
  std::ifstream answer;
  std::string ansFilePath = "answer" + std::to_string(p + 1) + ".txt";
  answer.open(ansFilePath);
  std::string ansText;
  if (answer.is_open()) {
    answer >> ansText;
    if (plAnswer == ansText) ++players;
    else ++watchers;
  } else std::cout << "something wrong" << std::endl;
}

int main() {
  int players(0), watchers(0);
  std::string win;
  bool playedSectors[13] = {false};
  int offset, pos(0);
  while (win.empty()) {
    std::cout << "enter the offset: ";
    std::cin >> offset;
    pos = (pos + offset) % 13;
    shiftPos(pos, playedSectors);
    playedSectors[pos] = true;
    playingSector(pos, players, watchers);
    std::cout << "players - " << players << "\twatchers " << watchers << std::endl;
    if (players == 6) win = "players";
    else if (watchers == 6) win = "watchers";
  }
  std::cout << win << " win." << std::endl;
  return 0;
}

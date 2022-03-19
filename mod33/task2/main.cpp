#include <iostream>
#include <exception>
#include <ctime>

class exWin : std::exception {
public:
    const char * what() const noexcept override{
      return "you win";
    }
};

class exLose : std::exception {
public:
    const char * what() const noexcept override{
      return "you lose";
    }
};

class exInp : std::exception {
public:
    const char * what() const noexcept override{
      return "you chose unavailable sector";
    }
};

class exMiss : std::exception {
public:
    const char * what() const noexcept override{
      return "miss";
    }
};
enum sector {
    empty,
    boot,
    fish,
};

void displField(sector f[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << f[i] << " ";
  }
  std::cout <<std::endl;
}

void imposeElem(sector f[], sector elem, int n) {
  //std::srand(std::time(nullptr));
  int r = std::rand() % 9;
  while (f[r] != empty) {
    ++r;
    if (r == n) r = 0;
  }
  f[r] = elem;
}

int main() {
  std::srand(std::time(nullptr));

  int n = 9;
  sector field[n];
  for (int i = 0; i < n; ++i) {
    field[i] = empty;
  }

  imposeElem(field, fish, n);
  imposeElem(field, boot, n);
  imposeElem(field, boot, n);

  displField(field, n);

  int try_count(0);
  bool gameover(false);
  do {
    try {
      int _try(0);
      std::cout << "which sector you wanna check " << "(0-" << n - 1 << ") : ";
      std::cin >> _try;
      if (_try < 0 || _try >= n) throw exInp();
      ++try_count;
      if (field[_try] == fish) throw exWin();
      if (field[_try] == boot) throw exLose();
      throw exMiss();
    }
    catch (exInp I){
      std::cout << I.what() << std::endl;
    }
    catch (exWin W) {
      std::cout << W.what() << std::endl;
      gameover =true;
    }
    catch (exLose L) {
      std::cout << L.what() << std::endl;
      gameover = true;
    }
    catch (exMiss M) {
      std::cout << M.what() << std::endl;
    }
  } while (!gameover);

  std::cout << "you have made " << try_count << " attempts" << std::endl;

  return 0;
}

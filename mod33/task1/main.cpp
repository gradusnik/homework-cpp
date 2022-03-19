#include <iostream>
#include <map>
#include <exception>
#include <thread>

class excLow : public std::exception {
public:
    const char * what() const noexcept override {
      return "input data should be positive";
    }
};

class excAmount : public std::exception {
public:
    const char * what() const noexcept override {
      return "invalid item amount";
    }
};

class excI : public std::exception {
public:
    const char * what() const noexcept override {
      return "item is absent";
    }
};

std::pair<long, int> input() {
  long art(0);
  int amount(0);
  //std::cout << "entering a commodity:" << std::endl;
  std::cout << "  enter the article: ";
  std::cin >> art;
  std::cout << "  enter the amount: ";
  std::cin >> amount;
  if (art < 1 || amount < 1) throw excLow();
  return {art, amount};
}

void add(std::map<long, int> &m) {
  std::cout << "you want to add product" << std::endl;
  auto tmp = input();
  if (m.find(tmp.first) != m.end()) {
    m[tmp.first] += tmp.second;
  } else throw excI();
}

void remove(std::map<long, int> &m) {
  long rem_art(0);
  std::cout << "enter the article you want remove: ";
  std::cin >> rem_art;
  auto r_item = m.find(rem_art);
  if (r_item == m.end()) {
    throw excI();
    //std::cout << "article " << rem_art << " is absent" << std::endl;
  } else {
    std::cout << "enter the amount you want remove: ";
    int r_amount(0);
    std::cin >> r_amount;
    if (r_amount < 0 || r_amount > r_item->second) throw excAmount();
    r_item->second -= r_amount;
    std::cout << "removing done" << std::endl;
  }
}

int main() {
  std::map<long, int> store;
                      //creating the store
  int next(1);
  std::cout << "creating the store..." << std::endl;
  while (next) {
    std::cout << "press 0 to exit, or any else key to input next commodity: ";
    std::cin >> next;
    if (next) {
      try {
        auto tmp = input();
        store[tmp.first] = tmp.second;
      }
      catch (const excLow& L) {
        std::cerr << L.what() << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }
                    //menu  (changing items)
  next = 1;
  do {
    std::cout << "menu: " << std::endl;
    std::cout << "\t1 - to add item" << std::endl;
    std::cout << "\t2 - to remove item" << std::endl;
    std::cout << "\t0 - to exit: ";
    std::cin >> next;
    try {
      if (next == 1) add(store);
      else if (next == 2) remove(store);
    }
    catch (const excLow& L) {
      std::cerr << L.what() << std::endl;
    }
    catch (const excAmount& A) {
      std::cerr << A.what() << std::endl;
    }
    catch (const excI& I) {
      std::cerr << I.what() << std::endl;
    }
  } while (next);

                    //display final items
  for (auto it = store.begin(); it != store.end() ; ++it) {
    std::cout << it->first << " -> " << it->second << std::endl;
  }

  return 0;
}

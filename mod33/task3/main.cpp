#include <iostream>
#include <vector>

#define parK int
#define parV std::string

template<typename K, typename V>
class Pair {
    K key;
    V val;
public:
    Pair(K _key, V _val):key(_key), val(_val){}
    K getKey() {
      return key;
    }
    V getVal() {
      return val;
    }

    Pair(const Pair& in) {
      key = in.key;
      val = in.val;
    }
};

template<typename K, typename V>
void addElem(std::vector<Pair<K, V>> &vec) {
  std::cout << std::endl << "adding element" << std::endl;
  K in_key;
  V in_val;
  std::cout << "enter the element key: ";
  std::cin >> in_key;
  std::cout << "enter the element value: ";
  std::cin >> in_val;
  Pair tmp(in_key, in_val);
  vec.push_back(tmp);
}
template<typename K, typename V>
void removeElement(std::vector<Pair<K, V>> &vec) {
  std::cout << std::endl << "removing elements" << std::endl;
  K in_key;
  std::cout << "enter the element key you wanna erase: ";
  std::cin >> in_key;
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it->getKey() == in_key) {
      vec.erase(it); --it;
    }
  }
}
template<typename K, typename V>
void printElements(std::vector<Pair<K, V>> &vec) {
  std::cout << std::endl;
  std::cout << "\'key\'" << "\t" << "\'value\'" << std::endl;
  for (auto item = vec.begin(); item != vec.end(); ++item) {
    std::cout << item->getKey() << "\t" << item->getVal() << std::endl;
  }
}
template<typename K, typename V>
void findElement(std::vector<Pair<K, V>> &vec) {
  std::vector<Pair<K, V>> rez;
  K in_key;
  std::cout << std::endl << "enter the element key you wanna find: ";
  std::cin >> in_key;
  for (auto item = vec.begin(); item != vec.end(); ++item) if (item->getKey() == in_key) rez.push_back(*item);
  if (rez.empty()) std::cout << "no elements" << std::endl;
  else {
    std::cout << "there are following elements: " << std::endl;
    printElements(rez);
  }
}

int main() {

  std::vector<Pair<parK, parV>> buf;

  int select(-1);
  while (select) {
    std::cout << std::endl << "you wanna: " << std::endl;
    std::cout << "1 for add element" << std::endl;
    std::cout << "2 for remove element" << std::endl;
    std::cout << "3 for print all elements" << std::endl;
    std::cout << "4 for find element" << std::endl;
    std::cout << "0 for exit" << std::endl;
    std::cout << "...: ";
    std::cin >> select;
    if (select == 1) addElem(buf);
    else if (select == 2) removeElement(buf);
    else if (select == 3) printElements(buf);
    else if (select == 4) findElement(buf);
    else if (select == 0) std::cout << "exit" << std::endl;
    else std::cout << "no option" << std::endl;
  }

  return 0;
}

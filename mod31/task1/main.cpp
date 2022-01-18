//                         my shared pointer
#include <iostream>
#include <string>
#include <vector>

//class Shared_ptr_toy;

class Toy {
    std::string name = "smToy";
public:
    //Toy();
    Toy(std::string _name) : name(_name){}
    std::string getName() {
      return name;
    }
} stdToy("usualToy");

class Shared_ptr_toy {
    Toy * _ptr_ = nullptr;
    int * rfs_num = nullptr;

    Shared_ptr_toy(Toy& obj) {                          // по замыслу вызывается только
      _ptr_ = &obj;                                     // при создании нового shared_ptr_toy
      rfs_num = new int(1);
    }

    friend Shared_ptr_toy make_shared_ptr_toy(Toy&);
public:


    Toy* getP() {
      return _ptr_;
    }

    int getReferences() {
      return *rfs_num;
    }
    std::string getName() {
      return this->_ptr_->getName();
    }
//    Shared_ptr_toy() {
//      _ptr_ = new Toy();
//      rfs_num = new int(1);
//    }

    Shared_ptr_toy(const Shared_ptr_toy& _obj) {                                    // констр. копирования
      _ptr_ = _obj._ptr_;
      rfs_num = _obj.rfs_num;
      ++*rfs_num;
    }
    Shared_ptr_toy& operator= (const Shared_ptr_toy& obj) {
      if (this == &obj) return *this;
      else if (_ptr_ != nullptr) {
        //std::cout << "previous obj rfs_num=" << *(obj.rfs_num) << std::endl;
        _ptr_ = obj._ptr_;
        --*rfs_num;
        rfs_num = obj.rfs_num;
        //std::cout << "next obj rfs_num " << *obj.rfs_num << std::endl;
        ++*rfs_num;
        //std::cout << " oper \'=\' ... rfs_num=" << *rfs_num << std::endl;
        return *this;
      } else {
        //std::cerr << "perhaps wrong programming" << std::endl;
        _ptr_ = obj._ptr_;
        rfs_num = obj.rfs_num;
        return *this;
      }
    }
    ~Shared_ptr_toy() {
      if (*rfs_num == 0) {
        delete _ptr_;
        delete rfs_num;
      }
    }
};

Shared_ptr_toy make_shared_ptr_toy(Toy& toy) {
//  static int count = 0; count++;
//  std::cout << " make is called " << count << " time" << std::endl;

  static std::vector<Shared_ptr_toy*> shareds;

  for (int i(0); i < shareds.size(); ++i) {
    if (shareds[i]->getP() == &toy) {
      //std::cout << " there are coincidence" << std::endl;
      return *(shareds[i]);
    }
  }
  shareds.push_back(new Shared_ptr_toy(toy));
  --*(shareds[shareds.size() - 1]->rfs_num);
  //std::cout << "  fun-make new obj rfs_num " <<  *(shareds[shareds.size() - 1]->rfs_num) << std::endl;
  return *(shareds[shareds.size() - 1]);
}

class Dog {
    std::string dogName = "empty";
    Shared_ptr_toy toy_ptr;
public:
    Dog(std::string _name, Shared_ptr_toy _toy_ptr) : dogName(_name), toy_ptr(_toy_ptr) {}
    Dog(std::string _name) : Dog(_name, make_shared_ptr_toy(stdToy)) {}
    Dog() : Dog("someDog", make_shared_ptr_toy(stdToy)) {}
};

void viewInfo(Shared_ptr_toy& ptr) {
  std::cout << ptr.getName() << " has " << ptr.getReferences() << " refs" << std::endl;
}

int main() {
  Toy ball("ball");
  Toy bone("bone");
  Shared_ptr_toy toy01 = make_shared_ptr_toy(ball);
  Shared_ptr_toy toy02 = make_shared_ptr_toy(ball);
  Shared_ptr_toy toy03 = make_shared_ptr_toy(ball);
  Shared_ptr_toy toy04 = make_shared_ptr_toy(ball);


  toy02 = make_shared_ptr_toy(bone);
  toy03 = make_shared_ptr_toy(bone);
  toy04 = toy03;

  //Shared_ptr_toy toy03 = make_shared_ptr_toy(bone);
  viewInfo(toy01);
  viewInfo(toy03);


  return 0;
}

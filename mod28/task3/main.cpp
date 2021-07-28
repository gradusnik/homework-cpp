#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

enum Dish{
    PIZZA,
    SOUP,
    STAKE,
    SALAD,
    SUSHI
};

enum Status{
    PENDING,
    COOKING,
    COOKED,
    DELIVERING,
    //DELIVERED
};

Dish intToDish(int n) {
  if (n == 0) return PIZZA;
  else if (n == 1) return SOUP;
  else if (n == 2) return STAKE;
  else if (n == 3) return SALAD;
  else return SUSHI;
}
std::string DishToString(Dish dish) {
  if (dish == PIZZA) return "pizza";
  else if (dish == SOUP) return "soup";
  else if (dish == STAKE) return "stake";
  else if (dish == SALAD) return "salad";
  else return "sushi";
}

class Order{
    Dish dish;
    Status status;
public:
    Order(Dish inDIsh): dish(inDIsh), status(PENDING){}
    Dish getDish() {
      return dish;
    }
    void setStatus(Status inStatus) {
      status = inStatus;
    }
    Status getStatus() {
      return status;
    }
    std::string message(Status status) {
      if (status == PENDING) return DishToString(dish) + " is ordered!";
      else if (status == COOKING) return DishToString(dish) + " is being cooked!";
      else if (status == COOKED) return DishToString(dish) + " has been cooked!";
      else if (status == DELIVERING) return DishToString(dish) + " is being delivered!";
      else return DishToString(dish) + " has been delivered!";
    }
};

std::vector<Order> orders;
std::mutex accForOrders;
std::mutex accForKitchen;
std::mutex accForCourier;

void gettingOrders() {
  std::srand(std::time(nullptr));
  while (true) {
    int pause = std::rand() % 6 + 5;
    std::this_thread::sleep_for(std::chrono::seconds(pause));
    int n = std::rand() % 5;
    Order order(intToDish(n));
    accForOrders.lock();
    orders.push_back(order);
    std::cout << order.message(PENDING) << std::endl;
    accForOrders.unlock();
  }
}

void kitchen() {
  std::srand(std::time(nullptr));
  int ind(0);
  while (true) {
    accForKitchen.lock();
    if (ind < orders.size()) {
      orders[ind].setStatus(COOKING);
      std::cout << orders[ind].message(COOKING) << std::endl;
      accForKitchen.unlock();
      int cooking = std::rand() % 11 + 5;
      std::this_thread::sleep_for(std::chrono::seconds(cooking));
      accForKitchen.lock();
      orders[ind].setStatus(COOKED);
      std::cout << orders[ind].message(COOKED) << std::endl;
      accForKitchen.unlock();
      ind++;
    } else {
      accForKitchen.unlock();
      std::this_thread::sleep_for(std::chrono::seconds(10));
    }
  }
}

void courier() {
  int ind(0);
  int count(0);
  int plan(4);
  int delivering(15);
  while (count < plan) {
    accForCourier.lock();
    if (ind < orders.size()) {
      if (orders[ind].getStatus() == COOKED) {
        orders[ind].setStatus(DELIVERING);
        std::cout << orders[ind].message(DELIVERING) << std::endl;
        accForCourier.unlock();
        ind++;
        count++;
        if (count == plan) break;
        std::this_thread::sleep_for(std::chrono::seconds(delivering));
      } else{
        accForCourier.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(delivering));
      }
    } else {
      accForCourier.unlock();
      std::this_thread::sleep_for(std::chrono::seconds(delivering));
    }
  }
  std::cout << "\ttoday we have reached the plan." << std::endl;
}

int main() {
  //std::srand(std::time(nullptr));
  std::thread ORDERS(gettingOrders);
  ORDERS.detach();
  std::thread KITCHEN(kitchen);
  KITCHEN.detach();
  std::thread COURIER(courier);
  COURIER.join();
  //std::cout << "exit.";
  return 0;
}

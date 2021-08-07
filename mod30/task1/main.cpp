#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
  std::string name = "dee", city = "boo";
  std::string url;
  std::string baseUrl = "http://httpbin.org/",
  get = "get",
  post = "post",
  delett = "delete",
  patch = "patch",
  put = "put";
  std::string request;
  while (request != "exit") {
    std::cout << "which request do you want to execute: ";
    std::cin >> request;
    if (request == get) {
      url = baseUrl + get;
      cpr::Response response = cpr::Get(cpr::Url(url));
      std::cout << response.text << std::endl;
    } else if (request == post) {
      url = baseUrl + post;
      cpr::Response response = cpr::Post(cpr::Url(url),
                                         cpr::Payload({{"name", name.c_str()},
                                                       {"city", city.c_str()}}));
      std::cout << response.text << std::endl;
    } else if (request == delett) {
      url = baseUrl + delett;
      cpr::Response response = cpr::Delete(cpr::Url(url));
      std::cout << response.text << std::endl;
    } else if (request == patch) {
      url = baseUrl + patch;
      cpr::Response response = cpr::Patch(cpr::Url(url));
      std::cout << response.text << std::endl;
    } else if (request == put) {
      url = baseUrl + put;
      cpr::Response response = cpr::Put(cpr::Url(url));
      std::cout << response.text << std::endl;
    } else if (request != "exit") {
      std::cout << "no request" << std::endl;
    }
  }
  return 0;
}

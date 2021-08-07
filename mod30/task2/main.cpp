#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {

  std::string url = "http://httpbin.org/html";
  std::string respText;


  cpr::Response response = cpr::Get(cpr::Url(url));
  respText = response.text;
  int begin = respText.find("<h1>") + 4;
  int end = respText.find("</h1>");
  std::string rez = respText.substr(begin, end - begin);
  std::cout << rez;

  //std::cout << response.text << std::endl;
  //std::cout << response.raw_header;
  //std::cout << response.header["accept"];


  return 0;
}

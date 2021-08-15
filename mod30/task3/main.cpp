#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <vector>

using std::string;

string mGetReq(std::vector<cpr::Pair> params, string& url) {
  if (!params.empty()) {
    url += "get?";
    auto iter = params.begin();
    url += iter->key + '=' + iter->value;
    ++iter;
    while (iter != params.end()) {
      url += '&' + iter->key + '=' + iter->value;
      ++iter;
    }
  }
  //std::cout << url << std::endl;
  cpr::Response response = cpr::Get(cpr::Url(url));
  return response.text;
}

string mPostReq(std::vector<cpr::Pair> params, string& url) {
  url += "post";
  cpr::Response response;
  if (!params.empty()) {
    response = cpr::Post(cpr::Url(url),
                         cpr::Payload(params.begin(), params.end()));
  }
  return response.text;
}

int main() {

  std::vector<cpr::Pair> params;
  cpr::Pair pair("", "");
  string url = "http://httpbin.org/";
  while (pair.key != "get" && pair.key != "post") {
    std::cout << "enter next parameter key: ";
    std::cin >> pair.key;
    if (pair.key != "get" && pair.key != "post") {
      std::cout << "enter next parameter value: ";
      std::cin >> pair.value;
      params.push_back(pair);
    }
  }

  if (pair.key == "get") std::cout << mGetReq(params, url);
  if (pair.key == "post") std::cout << mPostReq(params, url);

  return 0;
}

#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <vector>

using std::string;

string mGetReq(std::vector<std::pair<string, string>> params, string& url) {
  if (!params.empty()) {
    url += '?';
    auto iter = params.begin();
    url += iter->first + '=' + iter->second;
    ++iter;
    while (iter != params.end()) {
      url += '&' + iter->first + '=' + iter->second;
      ++iter;
    }
  }
  //std::cout << url << std::endl;
  cpr::Response response = cpr::Get(cpr::Url(url));
  return response.text;
}

string mPostReq(std::vector<std::pair<string, string>> params, string& url) {
  url += "/post";
  cpr::Response response;
  if (!params.empty()) {
    for (int i = 0; i < params.size(); ++i) {
      response = cpr::Post(cpr::Url(url),
                           cpr::Payload({{params[i].first.c_str(), params[i].second.c_str()}}));
    }
  }
//  cpr::Response response = cpr::Post(cpr::Url(url),
//                                     cpr::Payload(params));
  return response.text;
}

int main() {

  std::vector<std::pair<string, string>> params;

  string url = "http://httpbin.org";
  string paramKey, paramValue;
  while (paramKey != "get" && paramKey != "post") {
    std::cout << "enter next parameter key: ";
    std::cin >> paramKey;
    if (paramKey != "get" && paramKey != "post") {
      std::cout << "enter next parameter value: ";
      std::cin >> paramValue;
      params.push_back({paramKey, paramValue});
    }
  }

  if (paramKey == "get") std::cout << mGetReq(params, url);
  if (paramKey == "post") std::cout << mPostReq(params, url);

  return 0;
}

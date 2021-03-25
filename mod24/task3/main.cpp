#include <iostream>
#include <cmath>

struct vect{
    double x = 0;
    double y = 0;
};

double vectLen(vect &V) {
  return std::sqrt(std::pow(V.x, 2) + std::pow(V.y, 2));
}

void enteringVec(vect &vector) {
  std::cout << "\tx: ";
  double x(0);
  std::cin >> vector.x;
  std::cout << "\ty: ";
  double y(0);
  std::cin >> vector.y;
}

vect addVectors(vect &v1, vect &v2) {
  vect res;
  res.x = v1.x + v2.x;
  res.y = v1.y + v2.y;
  return res;
}

vect subtract(vect &v1, vect &v2) {
  vect res;
  res.x = v1.x - v2.x;
  res.y = v1.y - v2.y;
  return res;
  std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
}

vect multiplyScalar(vect &v, double s) {
  vect res;
  res.x = v.x * s;
  res.y = v.y * s;
  return res;
}

vect vectNormalize(vect &v) {
  vect nv;
  nv.x = v.x / vectLen(v);
  nv.y = v.y / vectLen(v);
  return nv;
}

int main() {
  std::cout << "choose the operation(enter the number): 0 - add two vectors" << std::endl
            << "                                        1 - subtract vectors" << std::endl
            << "                                        2 - multiplying a vec on scalar" << std::endl
            << "                                        3 - find the length of vec" << std::endl
            << "                                        4 - vec normalization" << std::endl;
  int n(-1);
  std::cin >> n;
  vect V1, V2, res;
  double S;
  if (n == 0) {
    std::cout << "enter first vector: " << std::endl;
    enteringVec(V1);
    std::cout << "enter second vector: " << std::endl;
    enteringVec(V2);
    res = addVectors(V1, V2);
    std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
  } else if (n == 1) {
    std::cout << "enter first vector: " << std::endl;
    enteringVec(V1);
    std::cout << "enter second vector: " << std::endl;
    enteringVec(V2);
    res = subtract(V1, V2);
    std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
  } else if (n == 2) {
    std::cout << "enter the vector: " << std::endl;
    enteringVec(V1);
    std::cout << "enter the number: ";
    std::cin >> S;
    res = multiplyScalar(V1, S);
    std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
  } else if (n == 3) {
    std::cout << "enter the vector: " << std::endl;
    enteringVec(V1);
    std::cout << "vector length is " << vectLen(V1) << std::endl;
  } else if (n == 4) {
    std::cout << "enter the vector: " << std::endl;
    enteringVec(V1);
    res = vectNormalize(V1);
    std::cout << "normalized vector is (" << res.x << "  " << res.y << ")" << std::endl;
  }
  else std::cerr << "no operation" << std::endl;
  return 0;
}

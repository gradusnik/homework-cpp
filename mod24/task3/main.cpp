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

void addVectors() {
  std::cout << "enter first vector: " << std::endl;
  vect V1, V2, res;
  enteringVec(V1);
  std::cout << "enter second vector: " << std::endl;
  enteringVec(V2);
  res.x = V1.x + V2.x;
  res.y = V1.y + V2.y;
  std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
}

void subtract() {
  std::cout << "enter first vector: " << std::endl;
  vect V1, V2, res;
  enteringVec(V1);
  std::cout << "enter second vector: " << std::endl;
  enteringVec(V2);
  res.x = V1.x - V2.x;
  res.y = V1.y - V2.y;
  std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
}

void multiplyScalar() {
  vect V, res;
  double S(0);
  std::cout << "enter the vector: " << std::endl;
  enteringVec(V);
  std::cout << "enter the number: ";
  std::cin >> S;
  res.x = V.x * S;
  res.y = V.y * S;
  std::cout << "result vector is (" << res.x << "  " << res.y << ")" << std::endl;
}

void vectLength() {
  vect V;
  std::cout << "enter the vector: " << std::endl;
  enteringVec(V);
  double L(0);
  std::cout << "vector length is " << vectLen(V) << std::endl;
}

void vectNormalize() {
  vect V, nV;
  std::cout << "enter the vector: " << std::endl;
  enteringVec(V);
  nV.x = V.x / vectLen(V);
  nV.y = V.y / vectLen(V);
  std::cout << "normalized vector: (" << nV.x << "  " << nV.y << ")" << std::endl;
}

int main() {
  std::string operation;
  std::cout << "choose the operation(enter the number): 0 - add two vectors" << std::endl
            << "                                        1 - subtract vectors" << std::endl
            << "                                        2 - multiplying a vec on scalar" << std::endl
            << "                                        3 - find the length of vec" << std::endl
            << "                                        4 - vec normalization" << std::endl;
  int n(-1);
  std::cin >> n;
  if (n == 0) addVectors();
  else if (n == 1) subtract();
  else if (n == 2) multiplyScalar();
  else if (n == 3) vectLength();
  else if (n == 4) vectNormalize();
  else std::cerr << "no operation" << std::endl;
  return 0;
}

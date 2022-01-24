#include <iostream>
#include "iGraph.h"

void displayVector(std::vector<int> &vec) {
  if (vec.empty()) std::cout << "vector is empty" << std::endl;
  else {
    int vecSize = vec.size();
    for (int i = 0; i < vecSize; ++i) {
      std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  iGraph * Graph001 = new MatrixGraph(3);
//  Graph001->displayGraph();
  Graph001->AddEdge(1, 1);
  Graph001->AddEdge(2, 0);
  std::cout << "  graph 01" << std::endl;
  Graph001->displayGraph();

//  MatrixGraph mgra(Graph001);
//  mgra.AddEdge(0,2);
//  mgra.displayGraph();

//  iGraph* grahp002 = new MatrixGraph(-2);

  iGraph* graph003 = new ListGraph(4);
//  graph003->displayGraph();
  graph003->AddEdge(1,2);
  graph003->AddEdge(0,3);
  graph003->AddEdge(0,2);
  std::cout << "  graph 03" << std::endl;
  graph003->displayGraph();

  ListGraph graph004(graph003);
  std::cout << "  graph 4 copied from list 03" << std::endl;
  graph004.displayGraph();

  ListGraph graph005(Graph001);
  std::cout << "  graph 5 copied from matrix 01" << std::endl;
  graph005.displayGraph();
//
//  graph003->displayGraph();
//
//  iGraph* graph004 = new MatrixGraph(graph003);
//  graph004->displayGraph();

  std::vector<int> vertices;
  graph003->GetNextVertices(0, vertices);
  displayVector(vertices);
  graph003->GetPrevVertices(2, vertices);
  displayVector(vertices);

  return 0;
}

//                      some graph
#pragma once
#include <iostream>
#include <vector>

enum GraphType {
    Undefined,
    Matrix,
    List,
};

class iGraph {
protected:
    GraphType type;
    int verticesCount = 1;
    std::vector<std::vector<int>> table;
public:
    virtual ~iGraph() = default;
    iGraph() {};
    iGraph(iGraph * _oth) {};
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const {return verticesCount;}
    virtual void displayGraph() const = 0;
    virtual GraphType getType() const {
      return type;
    }
    std::string stringType() const {
      if (type == Matrix) return "adjacency matrix";
      else if (type == List) return "adjacency list";
      else return "undefined";
    }
    int getTableElement(int i, int j) {
      return table[i][j];
    }
    int getVerCount() const {return verticesCount;}
    virtual int getNextVerCount(int ver) const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;
};

class MatrixGraph : public iGraph {
public:
    explicit MatrixGraph(int vCount) {
      type = Matrix;
      if (vCount < 1) vCount = 1;
      verticesCount = vCount;
      table.resize(verticesCount);
      for (int i = 0; i < verticesCount; ++i) {
        table[i].resize(verticesCount);
      }
    };
    explicit MatrixGraph(iGraph* in_graph) {
      type = Matrix;
      verticesCount = in_graph->getVerCount();
      table.resize(verticesCount);
      for (int i = 0; i < verticesCount; ++i) {
        table[i].resize(verticesCount);
      }
      if (in_graph->getType() == Matrix) {
        for (int i = 0; i < verticesCount; ++i) {
          table[i].resize(verticesCount);
        }
        for (int i = 0; i < verticesCount; ++i) {
          for (int j = 0; j < verticesCount; ++j) {
            table[i][j] = in_graph->getTableElement(i, j);
          }
        }
      } else if (in_graph->getType() == List) {
        for (int i = 0; i < verticesCount; ++i) {
          for (int j = 0; j < in_graph->getNextVerCount(i); ++j) {
            table[i][in_graph->getTableElement(i,j)] = 1;
          }
        }
      }
    }
    virtual void displayGraph() const override {
      std::cout << " graph type is " << stringType() << std::endl;
      std::cout << " graph has " << verticesCount << " vertices" << std::endl;
      //std::cout << "\t";
      for (int i = 0; i < verticesCount; ++i) {
        std::cout << "\tv" << i;
      }
      std::cout << std::endl;
      for (int i = 0; i < verticesCount; ++i) {
        std::cout << "v" << i;
        for (int j = 0; j < verticesCount; ++j) {
          std::cout << "\t" << table[i][j];
        }
        std::cout << std::endl;
      }
    }
    virtual void AddEdge(int from, int to) {
      if (from > verticesCount - 1 || to > verticesCount - 1) std::cout << "the vertex not available" << std::endl;
      else { table[from][to] = 1; }
    }
    virtual int getNextVerCount(int ver) const {
      int count = 0;
      for (int i = 0; i < verticesCount; ++i) {
        count += table[ver][i];
      }
      return count;
    };
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
      vertices.resize(0);
      for (int i = 0; i < verticesCount; ++i) {
        if (table[vertex][i] == 1) vertices.push_back(i);
      }
    }
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
      vertices.resize(0);
      for (int i = 0; i < verticesCount; ++i) {
        if (table[i][vertex] == 1) vertices.push_back(i);
      }
    }
};

class ListGraph : public iGraph {
public:
    explicit ListGraph(int vCount) {
      type = List;
      if (vCount < 1) vCount = 1;
      verticesCount = vCount;
      table.resize(verticesCount);
    }
    explicit ListGraph(iGraph* in_graph) {
      type = List;
      verticesCount = in_graph->getVerCount();
      table.resize(verticesCount);
      if (in_graph->getType() == Matrix) {
        for (int i = 0; i < verticesCount; ++i) {
          for (int j = 0; j < verticesCount; ++j) {
            if (in_graph->getTableElement(i, j) == 1) table[i].push_back(j);
          }
        }
      } else if (in_graph->getType() == List) {
        for (int i = 0; i < verticesCount; ++i) {
          for (int j = 0; j < in_graph->getNextVerCount(i); ++j) {
            table[i].push_back(in_graph->getTableElement(i,j));
          }
        }
      }
    }
    virtual void displayGraph() const override {
      std::cout << " graph type is " << stringType() << std::endl;
      std::cout << " graph has " << verticesCount << " vertices" << std::endl;
      for (int i = 0; i < verticesCount; ++i) {
        std::cout << "v" << i << "->";
        int size_ = table[i].size();
        //if (size_ == 0) std::cout << "  empty line ";
        for (int j = 0; j < size_; ++j) {
          std::cout << "\tv" << table[i][j];
        }
        std::cout << std::endl;
      }
    }
    virtual void AddEdge(int from, int to) {
      if (from > verticesCount - 1 || to > verticesCount - 1) std::cout << "the vertex not available" << std::endl;
      else { table[from].push_back(to); }
    }
    virtual int getNextVerCount (int ver) const {
      return table[ver].size();
    }
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
      vertices.resize(0);
      for (int i = 0; i < getNextVerCount(vertex); ++i) {
        vertices.push_back(table[vertex][i]);
      }
    }
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
      vertices.resize(0);
      for (int i = 0; i < verticesCount; ++i) {
        for (int j = 0; j < table[i].size(); ++j) {
          if (table[i][j] == vertex) {
            vertices.push_back(i); break;
          }
        }
      }
    }
};
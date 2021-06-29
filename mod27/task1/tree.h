#pragma once
#include <vector>
#include <string>

class MidBranch {
public:
    std::string name;
    MidBranch();
};

class BigBranch {
public:
    std::string name;
    std::vector<MidBranch> midBranches;
    BigBranch();
    int countInhabitedHouses();
};

class Tree {
public:
    std::vector<BigBranch> bigBranches;
    Tree();
    void findNameNeighbors(std::string name);
};

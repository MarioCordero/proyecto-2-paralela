#ifndef PAGERANK_H
#define PAGERANK_H

#include "../include/vertex.hpp"
#include "../include/fileManager.hpp"
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>

class PageRank {
private:
    FileManager& fileManager;

public:
    PageRank(FileManager& fm);

    void calculatePR();
    void printPageRanks();
};

#endif // PAGERANK_H
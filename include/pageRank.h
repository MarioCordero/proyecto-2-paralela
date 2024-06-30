#ifndef PAGERANK_H
#define PAGERANK_H

#include "vertex.h"
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>

class PageRank
{
public:
    PageRank(int iterations, int numThreads);
    ~PageRank();

    void updateRanks();
    void calculatePageRank();

private:
    int iterations;
    int numThreads;
    std::unordered_map<int, Vertex *> verticesMap;
};

#endif // PAGERANK_H
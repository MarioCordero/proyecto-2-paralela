// Inclusion de encabezados
#include "../include/vertex.hpp"
#include "../include/fileManager.hpp"

// Bibliotecas
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>

using namespace std;

#ifndef PAGERANK_H
#define PAGERANK_H

class PageRank
{
private:
    FileManager &fileManager;

public:
    PageRank(FileManager& fm);

    void calculatePR();
    void printPageRanks();
};

#endif // PAGERANK_H
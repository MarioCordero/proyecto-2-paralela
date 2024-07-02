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
    // Mapa para almacenar los nodos y sus asociaciones
    unordered_map<int, vertex> nodeAssociations;
    // Nombre del archivo para escribir
    string outputFileName;

public:
    PageRank(FileManager &fm);

    void calculatePR();
    void printPageRanks();
}; // Fin clase PageRank

#endif // Fin PAGERANK_H
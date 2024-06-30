#include "../include/vertex.hpp"
#include "../include/pageRank.hpp"
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>

// Constructor de la clase PageRank
PageRank::PageRank(int iterations, int numThreads)
    : iterations(iterations), numThreads(numThreads) {}

// Destructor de la clase PageRank
PageRank::~PageRank() {}

// Método para actualizar las puntuaciones de las páginas utilizando múltiples hilos con OpenMP
void PageRank::updateRanks()
{
    int verticesPerThread = (verticesMap.size() + numThreads - 1) / numThreads; // División redondeada hacia arriba

    // Configurar el número de hilos en OpenMP
    omp_set_num_threads(numThreads);

// Paralelizar el bucle usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < verticesMap.size(); ++i)
    {
        auto it = std::next(verticesMap.begin(), i);
        // REVISAR NOMBRE DE LA VARIABLE
        vertex *vertex = it->second;

// Imprimir el vértice actual y la lista de vértices que le apuntan (sección crítica)
#pragma omp critical
        {
            std::cout << "Thread ID: " << omp_get_thread_num() << " - Vertex ID: " << vertex->getID() << std::endl;
            const auto &pointingVertices = vertex->getPointingVertices();
            std::cout << "Pointing vertices: ";
            for (auto *pointingVertex : pointingVertices)
            {
                std::cout << pointingVertex->getID() << " ";
            }
            std::cout << std::endl;
        }
    }
}

// Método para calcular el PageRank
void PageRank::calculatePageRank()
{

    for (int i = 0; i < iterations; ++i)
    {
        updateRanks();
    }
}
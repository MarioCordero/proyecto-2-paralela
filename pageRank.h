#ifndef PAGERANK_H
#define PAGERANK_H

#include "vertex.h"
#include <string>
#include <map>
#include <vector>
#include <pthread.h>

// Estructura para pasar los datos a los hilos
struct ThreadData {
    std::map<int, Vertex*>& verticesMap; // Referencia al mapa de vértices
    pthread_mutex_t* mutex; // Mutex para sincronización
};

class PageRank {
private:
    int iterations; // Número de iteraciones para el cálculo de PageRank
    int numThreads; // Número de hilos a utilizar
    pthread_mutex_t mutex; // Mutex para sincronización entre hilos
    std::map<int, Vertex*> verticesMap; // Mapa de vértices

public:
    // Constructor
    PageRank(int iterations, const std::string& inputFile, int numThreads);

    // Destructor
    ~PageRank();

    // Función que será ejecutada por cada hilo para actualizar las puntuaciones de las páginas
    static void* updateRanksThread(void* arg);

    // Método para actualizar las puntuaciones de las páginas utilizando múltiples hilos
    void updateRanks();

    // Método para calcular el PageRank
    void calculatePageRank();
};

#endif // PAGERANK_H
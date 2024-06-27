#ifndef PAGERANK_H
#define PAGERANK_H

#include "vertex.h"
#include <string>
<<<<<<< HEAD
#include <map>
#include <vector>
#include <pthread.h>

// Estructura para pasar los datos a los hilos
struct ThreadData {
    std::map<int, Vertex*>& verticesMap; // Referencia al mapa de vértices
    pthread_mutex_t* mutex; // Mutex para sincronización
=======
#include <unordered_map>
#include <pthread.h>  // Incluir la biblioteca pthread

class PageRank {
public:
    PageRank(const std::string& inputFile, const std::string& outputFile, int iterations, double dampingFactor);
    void calculatePageRank();
    void readInputFile();
    void writeOutputFile();
    
private:
    std::string inputFile;
    std::string outputFile;
    int iterations;
    double dampingFactor;
    std::unordered_map<std::string, std::vector<std::string>> links;
    std::unordered_map<std::string, double> ranks;

    // Variables y métodos para pthread
    pthread_t *threads;
    pthread_mutex_t ranksMutex;

    void initializeRanks();
    void updateRanks();
    static void* threadUpdateRanks(void* arg);
>>>>>>> 561bffe98f5c2927263dfa7f510c4212327d3c03
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

    // Método para inicializar las puntuaciones de los vértices
    void initializeRanks();

    // Función que será ejecutada por cada hilo para actualizar las puntuaciones de las páginas
    static void* updateRanksThread(void* arg);

    // Método para actualizar las puntuaciones de las páginas utilizando múltiples hilos
    void updateRanks();

    // Método para calcular el PageRank
    void calculatePageRank();
};

#endif // PAGERANK_H
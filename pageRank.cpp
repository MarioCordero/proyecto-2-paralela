#include "pageRank.h"
#include "vertex.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <pthread.h>
#include <map>

// Estructura para pasar los datos a los hilos
struct ThreadData {
    std::map<int, Vertex*>& verticesMap; // Referencia al mapa de vértices
    pthread_mutex_t* mutex; // Mutex para sincronización
};

// Constructor de la clase PageRank
PageRank::PageRank(int iterations, const std::string& inputFile, int numThreads)
    : iterations(iterations), inputFile(inputFile), numThreads(numThreads) {
    pthread_mutex_init(&mutex, nullptr); // Inicializar el mutex
}

// Destructor de la clase PageRank
PageRank::~PageRank() {
    pthread_mutex_destroy(&mutex); // Destruir el mutex
}

// Función que será ejecutada por cada hilo para actualizar las puntuaciones de las páginas
void* PageRank::updateRanksThread(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);

    // Iterar sobre los vértices asignados a este hilo
    for (auto& pair : data->verticesMap) {
        Vertex* vertex = pair.second;

        // Bloquear mutex antes de imprimir para sincronización
        pthread_mutex_lock(data->mutex);

        // Imprimir el vértice actual
        std::cout << "Vertex ID: " << vertex->getID() << std::endl;

        // Imprimir la lista de vértices que le apuntan
        const auto& pointingVertices = vertex->getPointingVertices();
        std::cout << "Pointing vertices: ";
        for (auto* pointingVertex : pointingVertices) {
            std::cout << pointingVertex->getID() << " ";
        }
        std::cout << std::endl;

        // Desbloquear mutex después de imprimir
        pthread_mutex_unlock(data->mutex);

        // Realizar otras operaciones en el vértice
        // Ejemplo:
        // vertex->updatePageRank(); // Método ficticio para actualizar PageRank
    }

    pthread_exit(nullptr);
}

// Método para actualizar las puntuaciones de las páginas utilizando múltiples hilos
void PageRank::updateRanks() {
    pthread_t threads[numThreads];
    std::vector<ThreadData> threadData(numThreads);

    // Dividir los vértices en partes iguales para cada hilo
    int verticesPerThread = verticesMap.size() / numThreads;
    int remainingVertices = verticesMap.size() % numThreads;

    auto it = verticesMap.begin();
    for (int i = 0; i < numThreads; ++i) {
        threadData[i].verticesMap = verticesMap;
        threadData[i].mutex = &mutex;

        for (int j = 0; j < verticesPerThread && it != verticesMap.end(); ++j) {
            ++it;
        }

        if (i < remainingVertices && it != verticesMap.end()) {
            ++it;
        }
    }

    // Crear los hilos y pasarles los datos
    for (int i = 0; i < numThreads; ++i) {
        pthread_create(&threads[i], nullptr, &PageRank::updateRanksThread, &threadData[i]); // Crear el hilo
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }
}

// Método para calcular el PageRank
void PageRank::calculatePageRank() {

    // Actualizar las puntuaciones el número especificado de iteraciones
    for (int i = 0; i < iterations; ++i) {
        updateRanks();
    }
}

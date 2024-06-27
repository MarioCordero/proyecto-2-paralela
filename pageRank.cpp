#include "pageRank.h"
#include "vertex.h"
#include <iostream>
#include <pthread.h>

// Estructura para pasar los datos a los hilos
struct ThreadData {
    Vertex* vertex;          // Puntero al vértice asignado al hilo
    pthread_mutex_t* mutex;  // Mutex para sincronización
};

// Constructor de la clase PageRank
PageRank::PageRank(int iterations, int numThreads)
    : iterations(iterations), numThreads(numThreads) {
    pthread_mutex_init(&mutex, nullptr); // Inicializar el mutex
}

// Destructor de la clase PageRank
PageRank::~PageRank() {
    pthread_mutex_destroy(&mutex); // Destruir el mutex
}

// Función que será ejecutada por cada hilo para actualizar las puntuaciones de las páginas
void* PageRank::updateRanksThread(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    Vertex* vertex = data->vertex;

    // Bloquear mutex antes de imprimir para sincronización
    pthread_mutex_lock(data->mutex);

    // Imprimir el vértice actual y la lista de vértices que le apuntan
    std::cout << "Thread ID: " << pthread_self() << " - Vertex ID: " << vertex->getID() << std::endl;
    const auto& pointingVertices = vertex->getPointingVertices();
    std::cout << "Pointing vertices: ";
    for (auto* pointingVertex : pointingVertices) {
        std::cout << pointingVertex->getID() << " ";
    }
    std::cout << std::endl;

    // Desbloquear mutex después de imprimir
    pthread_mutex_unlock(data->mutex);

    // Realizar otras operaciones en el vértice si es necesario
    // Ejemplo:
    // vertex->updatePageRank(); // Método ficticio para actualizar PageRank

    pthread_exit(nullptr);
}

// Método para actualizar las puntuaciones de las páginas utilizando múltiples hilos
void PageRank::updateRanks() {
    pthread_t threads[numThreads];
    std::vector<ThreadData> threadData(numThreads);

    int verticesPerThread = (verticesMap.size() + numThreads - 1) / numThreads; // División redondeada hacia arriba
    auto it = verticesMap.begin();
    
    for (int i = 0; i < numThreads; ++i) {
        threadData[i].mutex = &mutex;

        for (int j = 0; j < verticesPerThread && it != verticesMap.end(); ++j, ++it) {
            threadData[i].vertex = it->second;
            pthread_create(&threads[i], nullptr, &PageRank::updateRanksThread, &threadData[i]);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }
}

// Método para calcular el PageRank
void PageRank::calculatePageRank() {
    // Aquí deberías inicializar tus vértices y asignarlos a verticesMap
    // Luego llamar a updateRanks() dentro de un bucle para el número de iteraciones especificado
    for (int i = 0; i < iterations; ++i) {
        updateRanks();
    }
}
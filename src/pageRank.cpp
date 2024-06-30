#include "../include/vertex.hpp"
#include "../include/pageRank.hpp"
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>

// Constructor
PageRank::PageRank(FileManager& fm) : fileManager(fm) {}

// Método para imprimir los IDs de los vértices
void PageRank::printVertexIDs() {
    const auto& nodes = fileManager.getNodeAssociations();

    // Obtener todos los IDs de los nodos
    std::vector<int> nodeIDs;
    nodeIDs.reserve(nodes.size());
    for (const auto& pair : nodes) {
        nodeIDs.push_back(pair.first);
    }

    // Iterar sobre los nodos en paralelo
    #pragma omp parallel
    {
        double aux = 0;
        double prevPR = 0;
        double currPR = 0;
        int iterationCounter = 0;
        int threadID = omp_get_thread_num();
        #pragma omp for schedule(dynamic)
        // Aquí va un while que hace la convergencia
        // Poner un for para estudiar resultados
        for (size_t i = 0; i < nodeIDs.size(); ++i) {
            int nodeID = nodeIDs[i];
            // Obtener el nodo actual
            const auto& currentNode = nodes.at(nodeID);
            // if (iterationCounter == 0) {
            //     currentNode.previousPR = 1.0 / nodes.size();
            // }
            // Imprimir los vértices adyacentes de manera segura
            #pragma omp critical
            {
                std::cout << "Thread ID: " << threadID << ", Vertex ID: " << nodeID << std::endl;

                const auto& adjacentVertices = currentNode.getAdjacentVertex();
                std::cout << "    Adjacent Vertices: ";
                for (const auto* adjVertex : adjacentVertices) {
                    //prevPR = currentNode.previousPR;
                    // Aquí se accede a previousPR y nodos que apunta
                    // Fórmula: sumatoria = previousPR / nodos que apunta
                    // para hacer una sumatoria

                    // std::cout << adjVertex->getID() << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}
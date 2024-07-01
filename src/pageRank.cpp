// Inclusion de encabezados
#include "../include/vertex.hpp"
#include "../include/pageRank.hpp"

// Bibliotecas
#include <iostream>
#include <omp.h>
#include <vector>
#include <unordered_map>
#include <cmath> // Para usar std::abs

using namespace std;

// Constructor
PageRank::PageRank(FileManager &fm) : fileManager(fm) {}

// Método para imprimir los IDs de los vértices
void PageRank::calculatePR() {
    auto& nodes = fileManager.getNodeAssociations();
    
    // Obtener todos los IDs de los nodos
    vector<int> nodeIDs;
    nodeIDs.reserve(nodes.size());

    // Número máximo de iteraciones para convergencia
    const int maxIterations = 1000; // Limite de seguridad
    const double dampingFactor = 0.85;
    const double initialPageRank = 1.0 / nodes.size();
    const double threshold = 1.0e-5; // Umbral de convergencia

    // Inicializar PageRank
    #pragma omp parallel for
    for (size_t i = 0; i < nodeIDs.size(); ++i) {
        int nodeID = nodeIDs[i];
        nodes[nodeID].setPreviousPR(initialPageRank);
        nodes[nodeID].setCurrentPR(initialPageRank);
    }

    // Iterar hasta que converja
    bool converged = false;
    int iteration = 0;
    while (!converged && iteration < maxIterations) {
        ++iteration;
        converged = true; // Suponemos convergencia hasta que se demuestre lo contrario

        #pragma omp parallel for schedule(dynamic)
        for (size_t i = 0; i < nodeIDs.size(); ++i) {
            int nodeID = nodeIDs[i];
            auto& currentNode = nodes.at(nodeID);

            double sum = 0.0;

            // Calcular la sumatoria de PageRanks de los nodos que apuntan a currentNode
            const auto& adjacentVertices = currentNode.getAdjacentVertex();
            for (const auto* adjVertex : adjacentVertices) {
                double prevPR = adjVertex->getPreviousPR();
                int outDegree = adjVertex->getAdjacentVertexCount();
                sum += (outDegree > 0) ? (prevPR / outDegree) : 0.0;
            }

            // Actualizar el PageRank actual usando el damping factor
            double newPR = ((1.0 - dampingFactor) / nodes.size()) + (dampingFactor * sum);

            // Verificar convergencia
            if (std::abs(currentNode.getCurrentPR() - newPR) > threshold) {
                converged = false; // Si hay una diferencia mayor que el umbral, no ha convergido
            }

            currentNode.setCurrentPR(newPR);
        }

        // Actualizar previousPR para la siguiente iteración
        #pragma omp parallel for
        for (size_t i = 0; i < nodeIDs.size(); ++i) {
            int nodeID = nodeIDs[i];
            nodes[nodeID].setPreviousPR(nodes[nodeID].getCurrentPR());
        }
    }

    std::cout << "PageRank converged after " << iteration << " iterations." << std::endl;
}

// Método auxiliar para imprimir el valor del PageRank de cada nodo
void PageRank::printPageRanks() {
    auto& nodes = fileManager.getNodeAssociations();

    for (const auto& pair : nodes) {
        int nodeID = pair.first;
        const auto& currentNode = pair.second;
        std::cout << "Vertex ID: " << nodeID << ", PageRank: " << currentNode.getCurrentPR() << std::endl;
    }
}


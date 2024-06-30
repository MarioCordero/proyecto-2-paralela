#ifndef VERTEX_h
#define VERTEX_h

// Bibliotecas
#include <iostream>
#include <vector>
#include <unordered_set>

class vertex
{

private:
    // Numero del nodo/vertice
    int id;
    // Vertices apuntados por mi
    int counterPointingVertex = 0;
    // PageRank anterior
    double previousPR = 0;
    // PageRank actual
    double currentPR = 0;
    // Lista de punteros de vertices adyacentes (Para poder acceder a sus atributos facilmente)
    std::vector<vertex *> adjacentVertex;

public:
    // Constructor por defecto
    vertex() : id(0) {}

    // Constructor del vertice
    vertex(int id) : id(id) {}

    // Función para agregar nodos adyacentes
    void addEdge(vertex oneVertex)
    {
        // Estamos añadiendo al array la dirección del vertice adyacente
        adjacentVertex.push_back(&oneVertex);
    }

    // Getters
    int getID() const
    {
        return id;
    }

    const std::vector<vertex *> &getAdjacentVertex() const
    {
        return adjacentVertex;
    }
    // int getPointingVertex(){
    //     return counterPointingVertex;
    // }
    // int getVertexPointMe(){
    //     return counterVertexPointMe;
    // }
    // vector* getVectorAdjacentVertex(){
    //     return &adjacentVertex;
    // }
};
#endif
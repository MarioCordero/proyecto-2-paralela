#ifndef VERTEX_h
#define VERTEX_h

// Bibliotecas
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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

public:
    // Lista de punteros de vertices adyacentes (Para poder acceder a sus atributos facilmente)
    vector<vertex *> adjacentVertex;

    // Constructor del vertice
    vertex(int id) : id(id)
    {
    }

    // Función para agregar nodos adyacentes
    void addEdge(vertex oneVertex)
    {
        // Estamos añadiendo al array la dirección del vertice adyacente
        adjacentVertex.push_back(&oneVertex);
    }

    // Getters
    int getID()
    {
        return id;
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
}; // Fin clase Vertex

#endif // Fin VERTEX_h
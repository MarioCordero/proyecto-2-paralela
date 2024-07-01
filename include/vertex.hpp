// Bibliotecas
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#ifndef VERTEX_h
#define VERTEX_h

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
    void addEdge(vertex &oneVertex)
    {
        // Estamos añadiendo al array el vertice adyacente
        adjacentVertex.push_back(&oneVertex);
    } // Fin addEdge

    // Getters
    int getID() const
    {
        return id;
    } // Fin getID

    const std::vector<vertex *> &getAdjacentVertex() const
    {
        return adjacentVertex;
    } // Fin getAdjacentVertex

    double getPreviousPR() const
    {
        return previousPR;
    } // Fin getPreviousPR

    double getCurrentPR() const
    {
        return currentPR;
    } // Fin getCurrentPR

    size_t getAdjacentVertexCount() const
    {
        return adjacentVertex.size();
    } // Fin getAdjacentVertexCount

    void setPreviousPR(double pr)
    {
        previousPR = pr;
    } // Fin setPreviousPR

    void setCurrentPR(double pr)
    {
        currentPR = pr;
    } // Fin setCurrentPR
}; // Fin clase vertex

#endif // Fin VERTEX_h
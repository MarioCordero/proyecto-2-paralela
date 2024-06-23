#ifndef vertex_h
#define vertex_h

#include <iostream>
#include <vector>
#include <unordered_set>

class vertex {
    private:

        int id;
        // Vertices apuntados por mi
        int counterPointingVertex = 0;
        // Vertices que me apuntan
        int counterVertexPointMe = 0;

    public:

        // Lista de punteros de vertices adyacentes (Para poder acceder a sus atributos facilmente)
        std::vector<vertex*> adjacentVertex;

        // Constructor del vertice
        vertex(int id) : id(id) 
        {}

        // Función para agregar nodos adyacentes
        void addEdge(vertex oneVertex) {
            // Estamos añadiendo al array la dirección del vertice adyacente
            adjacentVertex.push_back(&oneVertex);
        }

        // Getters
        int getID(){
            return id;
        }
        // int getPointingVertex(){
        //     return counterPointingVertex;
        // }
        // int getVertexPointMe(){
        //     return counterVertexPointMe;
        // }
        // std::vector* getVectorAdjacentVertex(){
        //     return &adjacentVertex;
        // }

};

#endif
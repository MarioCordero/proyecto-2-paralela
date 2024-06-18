#ifndef vertex_h
#define vertex_h

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <map>

class vertex {
    public:

        //ID del vertice (en este caso será un entero)
        int id;

        //Lista de adyacencia
        std::vector<int> nodosAdyacentes;

        //Constructor
        vertex(int id) : id(id) 
        {}

        //Función para agregar nodos adyacentes
        void addEdge(int v) {
            nodosAdyacentes.push_back(v);
        }
};

#endif
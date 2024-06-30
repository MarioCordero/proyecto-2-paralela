#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Bibliotecas e inclusion de encabezados
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <vertex.h>

class FileManager{

    private:

        // Mapa para almacenar los nodos y sus asociaciones
        std::unordered_map<int, vertex> nodeAssociations;

    public:

        // Constructor
        FileManager(){}
        //Procesador del archivo
        bool processFile(std::ifstream &file, const std::string &path);
        // Getter para toda la estructura de los nodos
        const std::unordered_map<int, vertex>& getNodeAssociations();

};

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//

bool FileManager::processFile(std::ifstream &file, const string &path){
    
    // Almacena cada línea del archivo
    std::string line;

    // Vertice y sus asociaciones
    int node, association;
    // Los : que delimita la entrada por linea
    char delimiter;

    // Leer el archivo línea por línea
    while (getline(file, line)){

        std::cout << line << endl;
        std::stringstream ss(line);

        // Leyendo la línea
        if (ss >> node >> delimiter >> association){
            /*
            Si encuentra la clave, devuelve un iterador que apunta a
            la posición de esa clave en el mapa.

            Si no encuentra la clave, devuelve end(), que es un
            iterador especial que indica el final del mapa.
            */
            if (nodeAssociations.find(node) == nodeAssociations.end()){
                // Nodo no existe en el mapa, entonces se agrega al mapa
                nodeAssociations[node] = vertex(node);
            }

            if (nodeAssociations.find(association) == nodeAssociations.end()){
                // Asociacion no existe en el mapa, entonces se agrega al mapa
                nodeAssociations[association] = vertex(association);
            }

            // Agregar la asociación al nodo en el mapa
            nodeAssociations[node].addEdge(nodeAssociations[association]);

        }
    }
    // Se hizo todo sin errores
    return true;
}

// Implemetación del getter
const std::unordered_map<int, vertex>& FileManager::getNodeAssociations(){
    return nodeAssociations;
}

#endif // Fin FILEMANAGER_H
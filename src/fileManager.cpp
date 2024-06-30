// Bibliotecas e inclusion de encabezados
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "vertex.h"
#include "fileManager.h"

using namespace std;

bool FileManager::processFile(std::ifstream &file, const std::string &path)
{

    // Almacena cada línea del archivo
    std::string line;

    // Vertice y sus asociaciones
    int node, association;
    // Los : que delimita la entrada por linea
    char delimiter;

    // Leer el archivo línea por línea
    while (getline(file, line))
    {

        std::cout << line << std::endl;
        std::stringstream ss(line);

        // Leyendo la línea
        if (ss >> node >> delimiter >> association)
        {
            /*
            Si encuentra la clave, devuelve un iterador que apunta a
            la posición de esa clave en el mapa.

            Si no encuentra la clave, devuelve end(), que es un
            iterador especial que indica el final del mapa.
            */
            if (nodeAssociations.find(node) == nodeAssociations.end())
            {
                // Nodo no existe en el mapa, entonces se agrega al mapa
                nodeAssociations[node] = vertex(node);
            }

            if (nodeAssociations.find(association) == nodeAssociations.end())
            {
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
const std::unordered_map<int, vertex> &FileManager::getNodeAssociations()
{
    return nodeAssociations;
}

void FileManager::printNodeAssociations()
{
    for (const auto &pair : nodeAssociations)
    {
        int node = pair.first;
        const vertex &vert = pair.second;

        std::cout << "Node: " << node << ", Adjacent Nodes: ";
        for (const auto *adjVertex : vert.getAdjacentVertex())
        {
            std::cout << adjVertex->getID() << " ";
        }
        std::cout << std::endl;
    }
}
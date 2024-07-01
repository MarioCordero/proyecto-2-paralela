// Inclusion de encabezados
#include "../include/vertex.hpp"
#include "../include/fileManager.hpp"

// Bibliotecas
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

bool FileManager::processFile(ifstream &file, const string &path)
{
    // Almacena cada línea del archivo
    string line;
    // Vertice y sus asociaciones
    int node, association;
    // Los : que delimita la entrada por linea
    char delimiter;

    // Leer el archivo línea por línea
    while (getline(file, line))
    {
        cout << line << endl;
        stringstream ss(line);

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
            } // Fin if

            if (nodeAssociations.find(association) == nodeAssociations.end())
            {
                // Asociacion no existe en el mapa, entonces se agrega al mapa
                nodeAssociations[association] = vertex(association);
            } // Fin if

            // Agregar la asociación al nodo en el mapa
            nodeAssociations[node].addEdge(nodeAssociations[association]);
        } // Fin if
    } // Fin while
    // Se hizo todo sin errores
    return true;
} // Fin processFile

// Implemetación del getter
unordered_map<int, vertex> &FileManager::getNodeAssociations()
{
    return nodeAssociations;
} // Fin getNodeAssociations

void FileManager::printNodeAssociations()
{
    for (const auto &pair : nodeAssociations)
    {
        int node = pair.first;
        const vertex &vert = pair.second;
        cout << "Node: " << node << ", Adjacent Nodes: ";
        for (const auto *adjVertex : vert.getAdjacentVertex())
        {
            cout << adjVertex->getID() << " ";
        } // Fin for
        cout << endl;
    } // Fin for
} // Fin printNodeAssociations

bool writeFile(const string &path)
{
    // Crear un objeto ofstream
    ofstream file(path);

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo para escribir: " << path << endl;
        return false;
    } // Fin if

    //file << pageRanke.calculatePR();

    // Verificar si hubo algún error al escribir
    if (file.fail())
    {
        cerr << "Error al escribir en el archivo: " << path << endl;
        file.close();
        return false;
    } // Fin if

    // Cerrar el archivo
    file.close();
    return true;
} // Fin writeFile
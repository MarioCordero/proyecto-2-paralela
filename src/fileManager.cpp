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

void FileManager::writeFile(const unordered_map<int, vertex>& pageRanks)
{
    // Verificar si el nombre del archivo está establecido
    if (outputFileName.empty())
    {
        throw std::runtime_error("El nombre del archivo de salida no está establecido.");
    } // Fin if

    // Crear un objeto ofstream
    ofstream file(outputFileName);

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open())
    {
        throw std::runtime_error("No se pudo abrir el archivo para escribir: " + outputFileName);
    } // Fin if

    // Iterar sobre el mapa y escribir los datos
    for (const auto &pair : nodeAssociations)
    {
        int node = pair.first;
        const vertex &vert = pair.second;
        file << "Node: " << node << ", Adjacent Nodes: ";
        for (const auto *adjVertex : vert.getAdjacentVertex())
        {
            file << adjVertex->getID() << " ";
        } // Fin for
        file << endl;
    } // Fin for

    // Escribir los valores de PageRank
    file << "\nPageRanks:\n";
    for (const auto &pair : pageRanks)
    {
        int node = pair.first;
        const vertex &vert = pair.second;
        file << "Node: " << node << ", PageRank: " << vert.getCurrentPR() << endl;
    } // Fin for

    // Verificar si hubo algún error al escribir
    if (file.fail())
    {
        file.close();
        throw std::runtime_error("Error al escribir en el archivo: " + outputFileName);
    } // Fin if

    // Cerrar el archivo
} // Fin writeFile

void FileManager::setOutputFileName(const string &fileName)
{
    outputFileName = fileName;
} // Fin setOutputFileNa
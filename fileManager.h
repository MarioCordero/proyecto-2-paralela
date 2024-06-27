#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Bibliotecas e inclusion de encabezados
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <vertex.h>

using namespace std;

class FileManager
{
private:
    // Nombre del archivo
    string readFile;
    // Mapa para almacenar los nodos y sus asociaciones
    map<int, vertex> nodeAssociations;

public:
    bool isPathValid(const string &path);
    bool processFile(const string &inputFile, const string &path);
}; // Fin clase FileManager

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//

bool FileManager::processFile(const string &inputFile, const string &path)
{
    readFile = inputFile;
    // Crear un objeto ifstream para intentar abrir el archivo
    ifstream file(readFile);

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo." << readFile << endl;
        return false;
    } // Fin if

    // Verificar que la ruta se pueda usar
    if (!isPathValid(path))
    {
        cerr << "Ruta destino inválida." << endl;
        return false;
    } // Fin if

    // Mapa para almacenar los nodos y sus asociaciones
    map<int, vertex> nodeAssociations;
    // Almacena cada línea del archivo
    string line;

    // Leer el archivo línea por línea
    while (getline(file, line))
    {
        cout << line << endl;
        stringstream ss(line);
        // Vertice y sus asociaciones
        int node, association;
        // Los : que delimita la entrada por linea
        char delimiter;

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

    // Cerrar el archivo
    file.close();
    // Se ejecuta bien
    return true;
} // Fin processFile

// Verificar si una ruta es válida
bool FileManager::isPathValid(const string &path)
{
    // Crear un objeto ifstream para intentar abrir el archivo
    ifstream file(path);
    // Si da true, significa que se pudo abrir y se puede usar
    bool valid = file.good();
    // Cerrar archivo
    file.close();
    // Da el resultado
    return valid;
} // Fin isPathValid

#endif // Fin FILEMANAGER_H
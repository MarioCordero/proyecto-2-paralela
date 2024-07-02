// Inclusion de encabezados
#include "../include/vertex.hpp"

// Bibliotecas
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager
{
private:
    // Mapa para almacenar los nodos y sus asociaciones
    unordered_map<int, vertex> nodeAssociations;
    // Nombre del archivo para escribir
    string outputFileName;

public:
    // Constructor
    FileManager() {}

    // Procesador del archivo
    bool processFile(ifstream &file, const string &path);
    // Getter para toda la estructura de los nodos
    unordered_map<int, vertex> &getNodeAssociations();
    // Para imprimir el mapa
    void printNodeAssociations();
    // Escribir un archivo
    void writeFile();
    // Establecer el nombre del archivo
    void setOutputFileName(const string &fileName);

}; // Fin clase FileManager

#endif // Fin FILEMANAGER_H
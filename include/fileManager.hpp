#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Bibliotecas e inclusion de encabezados
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "../include/vertex.hpp"

class FileManager
{

private:
    // Mapa para almacenar los nodos y sus asociaciones
    std::unordered_map<int, vertex> nodeAssociations;

public:
    // Constructor
    FileManager() {}
    // Procesador del archivo
    bool processFile(std::ifstream &file, const std::string &path);
    // Getter para toda la estructura de los nodos
    const std::unordered_map<int, vertex> &getNodeAssociations();
    // Para imprimir el mapa
    void printNodeAssociations();
    bool writeFile(const std::string& path, const std::string& content);
};

#endif // Fin FILEMANAGER_H
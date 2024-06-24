#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class FileManager{

    private:

        // Nombre del archivo
        std::string filename;

        // Mapa para almacenar los nodos y sus asociaciones
        std::map<int, std::vector<int>> nodeAssociations;

    public:

        // Constructor por defecto (no hace nada)
        FileManager() : filename("") {}

        bool processFile(const std::string& inputFile, const std::string& path);
        bool isPathValid(const std::string& path);
        bool isFileValid(const std::string& inputFile);

        // Destructor
        ~FileManager(){}
};

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//

bool FileManager::processFile(const std::string& inputFile, const std::string& path){

    // Verificar que se pueda abrir
    if (!isFileValid(inputFile)) {
        std::cerr << "Archivo inválido" << std::endl;
        return false;
    }

    // Verificar que la ruta se pueda usar
    if (!isPathValid(path)) {
        std::cerr << "Ruta destino inválida" << std::endl;
        return false;
    }
    
    // Crear un objeto ifstream
    std::ifstream file(filename);

    // Mapa para almacenar los nodos y sus asociaciones
    std::map<int, std::vector<int>> nodeAssociations;

    // Variable para almacenar cada línea del archivo
    std::string line;

    // Leer el archivo línea por línea
    while (std::getline(file, line)){

        std::cout << line << std::endl;

        // // Crear un stringstream a partir de la línea leída
        // std::stringstream ss(line);

        // // Variables para el nodo y la asociación
        // int node, association;
        // char delimiter;

        // // Leer el nodo y la asociación desde la línea
        // if (ss >> node >> delimiter >> association)
        // {
        //     // Agregar la asociación al nodo en el mapa
        //     nodeAssociations[node].push_back(association);
        // }

    }

    // Cerrar el archivo
    file.close();

    // Todo se ejecutó con exito
    return true;
}

// Función para verificar si una ruta es válida
bool FileManager::isPathValid(const std::string& path) {
    // Crear un objeto ifstream para verificar la ruta
    std::ifstream file(path);
    bool valid = file.good();
    file.close();
    return valid;
}

// Función para verificar si el archivo se puede abrir
bool FileManager::isFileValid(const std::string& inputFile) {
    filename = inputFile;

    // Crear un objeto ifstream
    std::ifstream file(filename);

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
        return false;
    }

    // Cerrar el archivo
    file.close();
    return true;
}

#endif // FILE_H
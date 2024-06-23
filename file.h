#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class File
{
public:
    // Mapa para almacenar los nodos y sus asociaciones
    std::map<int, std::vector<int>> nodeAssociations;

    // Declaración de la función
    void processFile(string &filename);
};

#endif // FILE_H

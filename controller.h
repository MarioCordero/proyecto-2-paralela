#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fileManager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Controller{
    private:
    public:
        int start(int argc, char *argv[]);
};

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//

// Inicializador de clase controladora
int Controller::start(int argc, char *argv[]){

    std::string fileName = "";
    std::string fileDestination = "";

    // Iterar sobre los argumentos dados
    int i = 1;
    while (i < argc) {

        if (strcmp(argv[i], "-src") == 0 && i + 1 < argc) {

            fileName = argv[i + 1];
            i += 2;

        } else if (strcmp(argv[i], "-dst") == 0 && i + 1 < argc) {

            fileDestination = argv[i + 1];
            i += 2;

        } else {

            throw std::invalid_argument("\n\nArgumentos invalidos.\n\n");

        }
    }

    // Verificar que ambos parámetros se hayan especificado
    if (fileName.empty() || fileDestination.empty()) {\
        throw std::invalid_argument("\n\nEl archivo de entrada y la ruta de salida deben especificarse.\n\n");;
    }

    // Crear una instancia de la clase FileManager
    FileManager fileProcessor;

    if (!fileProcessor.processFile(fileName, fileDestination)){
        throw std::runtime_error("\n\nFallo al procesar el archivo.\n\n");
    }

    // -TODO[] : HACER LO QUE QUEDA

    return 0;
}

#endif // Fin CONTROLLER_H
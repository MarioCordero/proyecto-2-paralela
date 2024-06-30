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
            // Código de error -1
            return -1;
        }
    }

    // Verificar que ambos parámetros se hayan especificado
    if (fileName.empty() || fileDestination.empty()) {\
        // Código de error -1
        return -1;
    }

    // Crear una instancia de la clase FileManager
    FileManager fileProcessor;

    if (fileProcessor.processFile(fileName, fileDestination)){

        // -TODO[] : HACER LO QUE QUEDA

    }else{

        return -1;

    }

    return 0;
}

#endif // Fin CONTROLLER_H
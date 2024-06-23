#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "file.h"
#include <iostream>
#include <string>
#include <cstring>

class controller{

    private:
        
    public:
        // Constructor por defecto (No hace nada)
        controller();
        int start(int argc, char* argv[]);
        // Destructor
        ~controller();
};

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//
// Constructor por defecto
controller::controller(){}

// Inicializador de clase controladora
int controller::start(int argc, char* argv[]){

    std::string fileName        = "";
    std::string fileDestination = "";

    if (strcmp(argv[1], "-src") == 0 && strcmp(argv[3], "-dst") == 0) {
        // argv[2] (Aqui esta el archivo a usar)
        fileName = argv[2];
        // argv[4] (Aqui esta la ruta a guardar el archivo)
        fileDestination = argv[4];

    } else {

        if(strcmp(argv[1], "-dst") == 0 && strcmp(argv[3], "-src") == 0){

            // argv[4] (Aqui esta el archivo a usar)
            fileName = argv[4];
            // argv[2] (Aqui esta la ruta a guardar el archivo)
            fileDestination = argv[4];

        }else{

            //Devolver codigo de error -1
            return -1;

        }
    }
    
    
    // Crear una instancia de la clase File
    FileManager fileProcessor;
    // Llamar al método para procesar el archivo
    fileProcessor.processFile(fileName);
    // Devolver 0, todo sale bien
    return 0;
}

// Destructor
controller::~controller(){}

#endif
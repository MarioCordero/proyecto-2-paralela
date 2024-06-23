#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "file.h"

class controller{

    private:
        
    public:
        // Constructor
        controller(int argc, char* argv[]);
        // Destructor
        ~controller();
};

controller::controller(int argc, char* argv[]){

    
    std::printf("Hola, funciono");
    // // Nombre del archivo que queremos leer
    // std::string filename = "prueba.txt";

    // // Crear una instancia de la clase File
    // File fileProcessor;

    // // Llamar al método para procesar el archivo
    // fileProcessor.processFile(filename);
}

controller::~controller(){}

#endif
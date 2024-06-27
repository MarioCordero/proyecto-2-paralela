#ifndef CONTROLLER_H
#define CONTROLLER_H

// Bibliotecas e inclusion de encabezados
#include "fileManager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Controller
{
private:
public:
    int start(int argc, char *argv[]);
}; // Fin clase Controller

// ---------------------------------------IMPLEMENTACIÓN---------------------------------------//

// Inicializador de clase controladora
int Controller::start(int argc, char *argv[])
{
    string fileName = "";
    string fileDestination = "";

    if (strcmp(argv[1], "-src") == 0 && strcmp(argv[3], "-dst") == 0)
    {
        // argv[2] (Aqui esta el archivo a usar)
        fileName = argv[2];
        // argv[4] (Aqui esta la ruta a guardar el archivo)
        fileDestination = argv[4];
    }
    else
    {
        if (strcmp(argv[1], "-dst") == 0 && strcmp(argv[3], "-src") == 0)
        {
            // argv[4] (Aqui esta el archivo a usar)
            fileName = argv[4];
            // argv[2] (Aqui esta la ruta a guardar el archivo)
            fileDestination = argv[4];
        }
        else
        {
            // Devolver codigo de error -1
            return -1;
        } // Fin if
    } // Fin if

    // Crear una instancia de la clase FileManager
    FileManager fileProcessor;

    if (fileProcessor.processFile(fileName, fileDestination))
    {
    }
    else
    {
        return -1;
    } // Fin if
    return 0;
} // Fin start

#endif // Fin CONTROLLER_H
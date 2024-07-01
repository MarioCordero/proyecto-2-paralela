// Inclusion de encabezados
#include "../include/fileManager.hpp"
#include "../include/controller.hpp"

// Bibliotecas
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Inicializador de clase controladora
int Controller::start(int argc, char *argv[])
{
    string fileName = "";
    string fileDestination = "";

    // Iterar sobre los argumentos dados
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-src") == 0 && i + 1 < argc)
        {
            fileName = argv[i + 1];
            i += 2;
        }
        else if (strcmp(argv[i], "-dst") == 0 && i + 1 < argc)
        {
            fileDestination = argv[i + 1];
            i += 2;
        }
        else
        {
            // Excepcion
            throw invalid_argument("\n\nArgumentos invalidos.\n\n");
        } // Fin if
    } // Fin while

    // Verificar que ambos parámetros se hayan especificado
    if (fileName.empty() || fileDestination.empty())
    {
        // Excepcion
        throw invalid_argument("\n\nEl archivo de entrada y la ruta de salida deben especificarse.\n\n");
    } // Fin if

    // Crear una instancia de la clase FileManager
    FileManager fileProcessor;
    // Declaracion de archivo a partir de la ruta proporcionada por parametros
    ifstream file(fileName);

    if (!file)
    {
        // Excepcion
        throw runtime_error(string("\n\nNo se pudo abrir el archivo: ") + fileName + (".\n\n"));
    } // Fin if

    if (!fileProcessor.processFile(file, fileDestination))
    {
        // Excepcion
        throw runtime_error("\n\nFallo al procesar el archivo.\n\n");
    } // Fin if

    // -TODO[] : HACER LO QUE QUEDA
    // Usar el getter el mapa y vamonos
    PageRank pageRank(fileProcessor);
    pageRank.calculatePR();
    // Imprimir los PageRanks después de calcularlos
    pageRank.printPageRanks();
    // Fin programa
    return 0;
} // Fin start
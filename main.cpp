// Bibliotecas e inclusion de encabezados
#include "controller.h"

int main(int argc, char *argv[])
{
    Controller program1;
    program1.start(argc, argv);
    // Fin del programa
    return 0;
}
// #include "PageRank.h"
// #include <iostream>

// int main(int argc, char* argv[]) {
//     // Verifica si se proporcionaron los argumentos esperados
//     if (argc != 5) {
//         std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile> <iterations> <dampingFactor>" << std::endl;
//         return 1;  // Devuelve 1 para indicar error en la línea de comandos
//     }

//     // Recupera los argumentos de la línea de comandos
//     std::string inputFile = argv[1];
//     std::string outputFile = argv[2];
//     int iterations = std::stoi(argv[3]);
//     double dampingFactor = std::stod(argv[4]);

//     // Crear instancia de PageRank con los parámetros proporcionados
//     PageRank pageRank(inputFile, outputFile, iterations, dampingFactor);

//     // Calcular el PageRank
//     pageRank.calculatePageRank();

//     return 0;  // Salida exitosa
// }
// } // Fin main

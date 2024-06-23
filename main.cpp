#include "pageRank.h"
#include "vertex.h"
#include "file.h"

#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char* argv[]) {

    if (strcmp(argv[1], "-src") == 0 && strcmp(argv[3], "-dst") == 0) {
        // argv[2] (Aqui esta el archivo a usar)
        // argv[4] (Aqui esta la ruta a guardar el archivo)
        std::cout << "\n\nCaso estandar\n\n";
    } else {
        if(strcmp(argv[1], "-dst") == 0 && strcmp(argv[3], "-src") == 0){
            // argv[4] (Aqui esta el archivo a usar)
            // argv[2] (Aqui esta la ruta a guardar el archivo)
            std::cout << "\n\nCaso alternativo\n\n";
        }else{
            return 1;
        }
    }

    // std::string inputFile = argv[1];
    // std::string outputFile = argv[2];
    // int iterations = std::stoi(argv[3]);
    // double dampingFactor = std::stod(argv[4]);

    // PageRank pageRank(inputFile, outputFile, iterations, dampingFactor);
    // pageRank.calculatePageRank();

    return 0;
}
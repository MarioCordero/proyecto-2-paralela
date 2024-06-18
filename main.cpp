#include "pageRank.h"
#include "vertex.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    // argv[2] (Aqui esta el archivo a usar)
    printf("Argumento 1 %s \n", argv[2]);

    // argv[4] (Aqui esta la ruta a guardar el archivo)
    printf("Argumento 2 %s\n", argv[4]);

    // if (argc != 5) {
    //     std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile> <iterations> <dampingFactor>" << std::endl;
    //     return 1;
    // }

    // std::string inputFile = argv[1];
    // std::string outputFile = argv[2];
    // int iterations = std::stoi(argv[3]);
    // double dampingFactor = std::stod(argv[4]);

    // PageRank pageRank(inputFile, outputFile, iterations, dampingFactor);
    // pageRank.calculatePageRank();

    // return 0;
}

#include "pageRank.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile> <iterations> <dampingFactor>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    int iterations = std::stoi(argv[3]);
    double dampingFactor = std::stod(argv[4]);

    PageRank pageRank(inputFile, outputFile, iterations, dampingFactor);
    pageRank.calculatePageRank();

    return 0;
}

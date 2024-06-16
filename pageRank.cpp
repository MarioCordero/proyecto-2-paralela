#include "PageRank.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <omp.h>

PageRank::PageRank(const std::string& inputFile, const std::string& outputFile, int iterations, double dampingFactor)
    : inputFile(inputFile), outputFile(outputFile), iterations(iterations), dampingFactor(dampingFactor) {}

void PageRank::readInputFile() {
    std::ifstream file(inputFile);
    std::string line, source, destination;

    while (getline(file, line)) {
        std::istringstream stream(line);
        stream >> source >> destination;
        links[source].push_back(destination);
        if (ranks.find(source) == ranks.end()) {
            ranks[source] = 1.0;
        }
        if (ranks.find(destination) == ranks.end()) {
            ranks[destination] = 1.0;
        }
    }

    file.close();
}

void PageRank::initializeRanks() {
    int numPages = ranks.size();
    double initialRank = 1.0 / numPages;

    for (auto& rank : ranks) {
        rank.second = initialRank;
    }
}

void PageRank::updateRanks() {
    int numPages = ranks.size();
    std::unordered_map<std::string, double> newRanks;
    
    #pragma omp parallel for
    for (auto it = ranks.begin(); it != ranks.end(); ++it) {
        std::string page = it->first;
        double rankSum = 0.0;

        for (const auto& link : links) {
            if (std::find(link.second.begin(), link.second.end(), page) != link.second.end()) {
                rankSum += ranks[link.first] / link.second.size();
            }
        }
        
        newRanks[page] = (1 - dampingFactor) / numPages + dampingFactor * rankSum;
    }

    ranks = newRanks;
}

void PageRank::calculatePageRank() {
    readInputFile();
    initializeRanks();

    for (int i = 0; i < iterations; ++i) {
        updateRanks();
    }

    writeOutputFile();
}

void PageRank::writeOutputFile() {
    std::vector<std::pair<std::string, double>> sortedRanks(ranks.begin(), ranks.end());
    std::sort(sortedRanks.begin(), sortedRanks.end());

    std::ofstream file(outputFile);

    for (const auto& rank : sortedRanks) {
        file << rank.first << " " << rank.second << std::endl;
    }

    file.close();
}

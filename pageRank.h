#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>
#include <string>
#include <unordered_map>
#include <pthread.h>  // Incluir la biblioteca pthread

class PageRank {
public:
    PageRank(const std::string& inputFile, const std::string& outputFile, int iterations, double dampingFactor);
    void calculatePageRank();
    void readInputFile();
    void writeOutputFile();
    
private:
    std::string inputFile;
    std::string outputFile;
    int iterations;
    double dampingFactor;
    std::unordered_map<std::string, std::vector<std::string>> links;
    std::unordered_map<std::string, double> ranks;

    // Variables y métodos para pthread
    pthread_t *threads;
    pthread_mutex_t ranksMutex;

    void initializeRanks();
    void updateRanks();
    static void* threadUpdateRanks(void* arg);
};

#endif // PAGERANK_H

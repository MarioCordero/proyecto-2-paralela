#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>
#include <string>
#include <unordered_map>

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
    
    void initializeRanks();
    void updateRanks();
};

#endif // PAGERANK_H

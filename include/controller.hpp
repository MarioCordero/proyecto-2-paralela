// Inclusion de encabezados
#include "../include/fileManager.hpp"
#include "../include/pageRank.hpp"

// Bibliotecas
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

#ifndef CONTROLLER_H
#define CONTROLLER_H

using namespace std;

class Controller
{
private:
public:
    int start(int argc, char *argv[]);
}; // Fin clase Controller

#endif // Fin CONTROLLER_H
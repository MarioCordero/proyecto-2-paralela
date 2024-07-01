// Inclusion de encabezados
#include "../include/controller.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Controller controller;

    try
    {
        return controller.start(argc, argv);
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return -1;
    } // Fin try-catch

    // Fin programa
    return 0;
} // Fin main

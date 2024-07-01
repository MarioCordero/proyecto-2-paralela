// Bibliotecas e inclusion de encabezados
#include "../include/controller.hpp"

int main(int argc, char *argv[])
{
    Controller controller;

    try
    {
        return controller.start(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    } // Fin try-catch

    // Fin programa
    return 0;
} // Fin main



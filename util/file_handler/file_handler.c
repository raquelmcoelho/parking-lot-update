#include "file_handler.h"

// verify if the binary file of vehicles exists^
bool fileExists(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
    return false;
    }
    fclose(file);
    return true;
}
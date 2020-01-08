#include <iostream>
#include <cstdlib>
#include "BMPGenerator.h"
#include "colors.h"
#include "position.h"

using namespace std;

int main(int argc, char **argv)
{
    if(argc == 4)
    {
        const int height = atoi(argv[1]);
        const int width = atoi(argv[2]);

        GenerateBMP bmp(height, width, argv[3]);

        Position middle((height - 1) / 2, (width - 1) / 2);

        //TODO algorithm here

        bmp.endGeneration();
    }

    return 0;
}
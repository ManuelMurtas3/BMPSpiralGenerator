#include <iostream>
#include <cstdlib>
#include "BMPGenerator.h"
#include "colors.h"
#include "position.h"

using std::cout;

int main(int argc, char **argv)
{
    if(argc == 4)
    {
        if(atoi(argv[1]) == atoi(argv[2])) //has to be a squared image
        {
            const int side = atoi(argv[1]);
            GenerateBMP bmp(side, side, argv[3]);

            Position middle((side - 1) / 2, (side - 1) / 2);

            int x = (side - 1) / 2;
            int y = (side - 1) / 2;
            
            int numberToWrite = 1;
            int numberOfDirectionChanges = 2 * side - 1;
            int incx = 1;

            for(int i = 0; i < (side * side) - 1; i++)
            {
                //TODO
            }

            bmp.endGeneration();
        }
        else
        {
            cout << "The image you want to generate isn't a square.\n";
        }
        
    }

    return 0;
}

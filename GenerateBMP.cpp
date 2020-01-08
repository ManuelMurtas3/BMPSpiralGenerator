#include <iostream>
#include "BMPGenerator.h"
#include "colors.h"

using namespace std;

int main()
{
    GenerateBMP bmp1(8, 8, "prova1");

    bmp1.writePixel(0, 0, black);

    bmp1.endGeneration();

    return 0;
}
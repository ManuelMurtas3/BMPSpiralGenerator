#include <iostream>
#include <cstdlib>
#include <cmath>
#include "BMPGenerator.h"
#include "colors.h"
#include "position.h"

#define MAXNDIR 4

using std::cout;

bool isPrime(int n)
{
    for(int i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    if(argc == 4) //program width height image_filename
    {
        if(atoi(argv[1]) == atoi(argv[2])) //has to be a squared image
        {
            const int directions[MAXNDIR] = {Position::RIGHT, Position::UP, Position::LEFT, Position::DOWN};
            int directionIndex = 0;
            const int side = atoi(argv[1]);

            GenerateBMP bmp(side, side, argv[3]);
            int matrix[3][3] = {0};

            Position currentPosition(floor((side - 1) / 2), ceil((side - 1) / 2.0));

            int numberToWrite = 1;
            int totalNumberOfDirectionChanges = 2 * side - 1;
            int stepsBeforeChangeDirection = 1;
            int stepsBeforeStepAmountChange = 2;
            int currentAmountOfSteps = 0;

            for(int i = 0; i < (side * side) - 1; i++)
            {
                cout << "Row: " << currentPosition.gety() << " | Column: " << currentPosition.getx() << "\n";
                matrix[currentPosition.gety()][currentPosition.getx()] = numberToWrite;

                if(isPrime(numberToWrite))
                {
                    bmp.writePixel(currentPosition, BLACK);
                }

                numberToWrite++;
                currentAmountOfSteps++;

                if(currentAmountOfSteps % stepsBeforeChangeDirection == 0)
                {
                    directionIndex = (directionIndex + 1) % MAXNDIR;

                    try
                    {
                        currentPosition.moveTo(directions[directionIndex]);
                        cout << "Going: ";
                        switch (directions[directionIndex])
                        {
                            case Position::UP:
                            {
                                cout << "up";
                                break;
                            }
                            case Position::DOWN:
                            {
                                cout << "up";
                                break;
                            }
                            case Position::LEFT:
                            {
                                cout << "up";
                                break;
                            }
                            case Position::RIGHT:
                            {
                                cout << "up";
                                break;
                            }
                        }
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }

                    if(currentAmountOfSteps % stepsBeforeStepAmountChange == 0)
                    {
                        stepsBeforeChangeDirection++;
                        stepsBeforeStepAmountChange += 2;
                    }
                }

                //

            }

            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << matrix[i][j] << " ";
                }

                cout << "\n";
                
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

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "BMPGenerator.h"
#include "colors.h"
#include "position.h"

#define MAXNDIR 4

using std::cout;

void printGoingDirection(int dir)
{
    cout << "Going: ";
    switch (dir)
    {
        case Position::UP:
        {
            cout << "UP";
            break;
        }
        case Position::DOWN:
        {
            cout << "DOWN";
            break;
        }
        case Position::LEFT:
        {
            cout << "LEFT";
            break;
        }
        case Position::RIGHT:
        {
            cout << "RIGHT";
            break;
        }
    }
    cout << "\n";
}

bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    if (argc == 4) //program width height image_filename
    {
        if (atoi(argv[1]) == atoi(argv[2])) //has to be a squared image
        {
            const int directions[MAXNDIR] = {Position::RIGHT, Position::UP, Position::LEFT, Position::DOWN};
            int directionIndex = -1;
            const int side = atoi(argv[1]);

            GenerateBMP bmp(side, side, argv[3]);
            int matrix[5][5] = {0};

            Position currentPosition(floor((side - 1) / 2), ceil((side - 1) / 2.0));

            int numberToWrite = 1;
            int totalNumberOfDirectionChanges = 2 * side - 1;
            int stepsBeforeChangeDirection = 1;
            int stepsBeforeStepAmountChange = 2;
            int stepsAmount = 0;
            int currentTotalStepsAmount = 0;

            for (int i = 0; i < side * side; i++)
            {
                cout << "Row: " << currentPosition.gety() << " | Column: " << currentPosition.getx() << "\n";
                cout << "Writing: " << numberToWrite << "\n";
                matrix[currentPosition.gety()][currentPosition.getx()] = numberToWrite;

                if (isPrime(numberToWrite))
                {
                    bmp.writePixel(currentPosition, BLACK);
                }

                numberToWrite++;
                stepsAmount++;
                currentTotalStepsAmount++;

                if (stepsAmount <= stepsBeforeChangeDirection)
                {
                    directionIndex = (directionIndex + 1) % MAXNDIR;

                    try
                    {
                        currentPosition.moveTo(directions[directionIndex]);
                        printGoingDirection(directions[directionIndex]);
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }

                    if (currentTotalStepsAmount % stepsBeforeStepAmountChange == 0)
                    {
                        stepsBeforeChangeDirection++;
                        stepsBeforeStepAmountChange += 2;
                    }
                }
                else
                {
                    try
                    {
                        currentPosition.moveTo(directions[directionIndex]);
                        printGoingDirection(directions[directionIndex]);
                        stepsAmount = 0;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                system("pause");
                cout << "\n";
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cout << matrix[i][j] << "\t";
                }

                cout << "\n\n";
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

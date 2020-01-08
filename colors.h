#ifndef COLORS_H
#define COLORS_H

#include <cstring>
#include <cmath>
#include "bmpExceptions.h"

class Color
{
    private:
        
        short int red;
        short int green;
        short int blue;

        short int hexToInt(const char* hex) //must be 2 characters
        {
            short int res = 0;
            if(strlen(hex) == 2)
            {
                if(hex[1] >= '0' && hex[1] <= '9')
                    res = hex[1] - 48;
                else if(hex[1] >= 'A' && hex[1] <= 'F')
                    res = hex[1] - 55;
                else if(hex[1] >= 'a' && hex[1] <= 'f')
                    res = hex[1] - 87;
                else
                    throw invalidHexException;

                if(hex[0] >= '0' && hex[0] <= '9')
                    res += (hex[0] - 48) * 10;
                else if(hex[0] >= 'A' && hex[0] <= 'F')
                    res += (hex[0] - 55) * 10;
                else if(hex[0] >= 'a' && hex[0] <= 'f')
                    res += (hex[0] - 87) * 10;
                else
                    throw invalidHexException;
            }

            return res;
        }

    public:

        Color(const short int red, const short int green, const short int blue)
        {
            if(red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0 && blue <= 255)
            {
                this->red = red;
                this->green = green;
                this->blue = blue;
            }
            else
            {
                this->red = this->green = this->blue = 0;
            }
        }

        Color(const char* hex)
        {
            if(strlen(hex) == 6)
            {
                char colors[3][3];
                
                for(int i = 0; i < 3; i++)
                {
                    strcpy(colors[i], "");
                    colors[i][i % 2] = hex[i % 2];
                    colors[i][i % 2 + 1] = hex[i % 2 + 1];
                }

                this->red = hexToInt(colors[0]);
                this->green = hexToInt(colors[1]);
                this->blue = hexToInt(colors[2]);
            }
            else
            {
                throw invalidHexLengthException;
            }
            
        }

        const int getRed()
        {
            return this->red;
        }

        const int getGreen()
        {
            return this->green;
        }

        const int getBlue()
        {
            return this->blue;
        }
    
};

Color red(255, 0, 0);
Color green(0, 255, 0);
Color blue(0, 0, 255);
Color white(255, 255, 255);
Color black(0, 0, 0);

#endif
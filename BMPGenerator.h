#ifndef BMPGEN_H
#define BMPGEN_H

#include <fstream>
#include <cstring>
#include <stdio.h>
#include "colors.h"
#include "bmpExceptions.h"
#include "position.h"

class GenerateBMP
{
    private:
        
        //all numbers are expressed in bytes (1 = 1 byte = 8 bit)
        std::fstream binFile;
        unsigned short int height;
        unsigned short int width;
        unsigned int headerDimension = 54;
        char* filename;
        const unsigned short int colorDimension = 4; //rapresents how many bytes are needed for the color to be desplayed

        int expectedSize()
        {
            return this->height * this->width * colorDimension + headerDimension;
        }

    public:
        GenerateBMP(const unsigned short int height, const unsigned short int width, const char* filename)
        {
            // dimension inizialization
            this->height = height;
            this->width = width;

            //check for filename validity
            if(!strstr(filename, ".bmp"))
            {
                this->filename = new char[strlen(filename) + 4];
                strcpy(this->filename, filename);
                strcat(this->filename, ".bmp");
            }
            else
            {
                this->filename = new char[strlen(filename)];
                strcpy(this->filename, filename);
            }
            
            
            //file creation
            binFile.open(this->filename, std::ios::out | std::ios::binary | std::ios::trunc);

            //file inizialization
            binFile.write("BM", 2); //bmp signature

            int binaryOutput = this->expectedSize();
            binFile.write((char*)&binaryOutput, sizeof(int)); //total file dimension
            
            binaryOutput = 0;
            binFile.write((char*)&binaryOutput, sizeof(int)); //reserved bytes

            binaryOutput = headerDimension;
            binFile.write((char*)&binaryOutput, sizeof(int)); //bitmap color map offset starting address

            binaryOutput = 40;
            binFile.write((char*)&binaryOutput, sizeof(int)); //Size of the header (calculated from now on)

            binaryOutput = this->width;
            binFile.write((char*)&binaryOutput, sizeof(int)); //bitmap width in pixels
            binaryOutput = this->height;
            binFile.write((char*)&binaryOutput, sizeof(int)); //bitmap height in pixels

            binaryOutput = 2097153; //corresponds to 01002000 (hex: 00200001) - 32 bit configuration
            binFile.write((char*)&binaryOutput, sizeof(int)); //the palette and color depth configuration

            binaryOutput = 0;
            binFile.write((char*)&binaryOutput, sizeof(int)); //compression method (no compression)

            binaryOutput = this->height * this->width * colorDimension;
            binFile.write((char*)&binaryOutput, sizeof(int)); //size of the bitmap color map

            binaryOutput = 0;
            binFile.write((char*)&binaryOutput, sizeof(int)); //width resolution (0 means original)
            binFile.write((char*)&binaryOutput, sizeof(int)); //height resolution (0 means original)
            binFile.write((char*)&binaryOutput, sizeof(int)); //number of palette colors 
            binFile.write((char*)&binaryOutput, sizeof(int)); //number of important colors (o means every color is important)

            char whitePixel = 255;
            for(int i = 0; i < this->height * this->width * colorDimension; i++)
            {
                binFile.write((char*)&whitePixel, 1);
            }

			binFile.close();
			binFile.open(this->filename, std::ios::in | std::ios::out | std::ios::binary);

            //end of bmp pregeneration
        }

        /*void InitPixels(Color color)
        {
            char red = color.getRed(), green = color.getGreen(), blue = color.getBlue(), end = 255;
            
            binFile.write((char*)&red, 1);
            binFile.write((char*)&green, 1);
            binFile.write((char*)&blue, 1);
            binFile.write((char*)&end, 1);
        }*/

		void writePixel(unsigned short int column, unsigned short int row, Color color)
		{
			row = this->height - 1 - row;
			//column = this->width - 1 - column;
			
			char red = color.getRed(), green = color.getGreen(), blue = color.getBlue(), end = 0;

			binFile.seekp(std::ios::beg + headerDimension + (row * width * colorDimension) + (column * colorDimension));

			binFile.write((char*)&red, 1);
			binFile.write((char*)&green, 1);
			binFile.write((char*)&blue, 1);
			binFile.write((char*)&end, 1);
		}

        void writePixel(Position* pos, Color color)
		{
			this->writePixel(pos->getx(), pos->gety(), color);
		}

        void writePixel(Position pos, Color color)
		{
			this->writePixel(pos.getx(), pos.gety(), color);
		}

        void endGeneration()
        {
            binFile.close();
        }

        ~GenerateBMP()
        {   
            binFile.close();
        }
};

#endif
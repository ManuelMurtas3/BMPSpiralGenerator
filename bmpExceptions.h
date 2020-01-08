#ifndef BMPEXCEPTION_H
#define BMPEXCEPTION_H
#include <exception>

class InvalidHexException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Invalid HEX in color, must contain only numbers or A to F characters";
    }
}invalidHexException;

class InvalidHexLengthException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Invalid HEX in color, must contain only 6 characters";
    }
}invalidHexLengthException;

class InvalidBMPDimensionException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Invalid bmp dimension, the file current size doesn't match the expected dimension";
    }
}invalidBMPDimensionException;

#endif
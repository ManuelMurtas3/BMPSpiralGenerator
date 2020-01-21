#ifndef POSITION_H
#define POSITION_H

#include "constants.h"

class Position
{
    private:

        unsigned short int x;
        unsigned short int y;

    public:
        
        Position(unsigned short int x, unsigned short int y)
        {
            this->x = x;
            this->y = y;
        }
        
        unsigned short int getx() {return x;}
        unsigned short int gety() {return y;}
        
        void moveTo(unsigned short int x, unsigned short int y)
        {
            this->x = x;
            this->y = y;
        }

        void moveTo(Position* p)
        {
            moveTo(p->getx(), p->gety());
        }

        void moveTo(Position p)
        {
            moveTo(p.getx(), p.gety());
        }

        void goRight()
        {
            if(x <= USHORTMAX - 1)
            {
                this->moveTo(this->x + 1, this->y);
            }
            else
            {
                throw outOfBoundsPositionException;
            }
            
        }

        void goLeft()
        {
            if(x >= USHORTMIN + 1)
            {
                this->moveTo(this->x - 1, this->y);
            }
            else
            {
                throw outOfBoundsPositionException;
            }
        }

        void goUp()
        {
            if(y >= USHORTMIN + 1)
            {
                this->moveTo(this->x, this->y - 1);
            }
            else
            {
                throw outOfBoundsPositionException;
            }
        }

        void goDown()
        {
            if(y <= USHORTMAX - 1)
            {
                this->moveTo(this->x, this->y + 1);
            }
            else
            {
                throw outOfBoundsPositionException;
            }
        }
};

#endif
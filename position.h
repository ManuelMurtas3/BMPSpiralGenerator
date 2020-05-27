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
        
        static const int RIGHT = 0;
        static const int UP = 1;
        static const int LEFT = 2;
        static const int DOWN = 3;

        unsigned short int getx() {return x;}
        unsigned short int gety() {return y;}
        
        void moveTo(unsigned short int x, unsigned short int y)
        {
            this->x = x;
            this->y = y;
        }

        void moveTo(int direction)
        {
            switch(direction)
            {
                case UP:
                {
                    this->goUp();
                    break;
                }

                case DOWN:
                {
                    this->goDown();
                    break;
                }

                case LEFT:
                {
                    this->goLeft();
                    break;
                }

                case RIGHT:
                {
                    this->goRight();
                    break;
                }

            }
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
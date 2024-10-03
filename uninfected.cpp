#include "uninfected.h"
// Uninfected::Uninfected(const Uninfected& hero) : {}

Uninfected::Uninfected(const Position& pos, char type): Person(pos,type){}
void Uninfected::move(const char name)
{
    Position* temPtr =this->getPosition();

    switch(name)
    {
        case 'l':
            temPtr->moveLeft();
            break;
        case 'r':
            temPtr->moveRight();
            break;
        case 'u':
            temPtr->moveUp();
            break;
        case 'd':
            temPtr->moveDown();
            break;
    }
}


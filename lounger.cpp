#include "lounger.h"

Lounger::Lounger(const Position& pos): Infected(pos, 'L'){}

void Lounger::move(const char name)
{
    Position* termPtr = this->getPosition();
    int ranNumber = termPtr->ranDom(1, 10);  
    
    
    if (ranNumber <= 2) 
    {
        termPtr->moveMent();
    }
}

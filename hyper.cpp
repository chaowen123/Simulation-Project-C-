#include "hyper.h"

#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

Hyper::Hyper(const Position &pos) : Infected(pos, 'H') {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
}

void Hyper::move(const char name) 
{
    Position *termPtr = this->getPosition();
    
    // Generate a random number between 0 and 3
    int direction = rand() % 4;

    // Move based on the random direction
    switch (direction) {
        case 0: 
            termPtr->moveUp();    // Move up
            break;
        case 1: 
            termPtr->moveDown();  // Move down
            break;
        case 2: 
            termPtr->moveLeft();  // Move left
            break;
        case 3: 
            termPtr->moveRight(); // Move right
            break;
        default:
            break; // No movement, though this should never be reached
    }
}
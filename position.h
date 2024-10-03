#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H
struct Position
{
    size_t x;
    size_t y;

    Position(size_t x, size_t y) : x{x}, y{y} {}
    Position(const Position &other) : x{other.x}, y{other.y} {}
    
    int ranDom(const int, const int);

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();


    void moveLandD();
    void moveRandD();
    void moveUandL();
    void moveRandU();
    void moveUdL();
    void moveUdR();
    void moveDrl();
    void moveUrl();
    void moveany();
    void moveMent();

};

#endif
#include <random>
#include <stdlib.h>

#include "position.h"

Position::ranDom(const int start, const int end)
{
    int modole;
    modole = end - start + 1;
    return (rand() % modole) + start;
}
void Position::moveRight()
{
    y += 1;
}

void Position::moveLeft()
{
    y -= 1;
}

void Position::moveUp()
{
    x -= 1;
}

void Position::moveDown()
{
    x += 1;
}
void Position::moveLandD()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveLeft();
        break;
    case 2:
        moveDown();
        break;
    default:
        break;
    }
}
void Position::moveRandD()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveDown();
        break;
    default:
        break;
    }
}
void Position::moveUandL()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveLeft();
        break;
    case 2:
        moveUp();
        break;
    default:
        break;
    }
}
void Position::moveRandU()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveUp();
        break;
    default:
        break;
    }
}

void Position::moveUdL()
{
    int move = ranDom(1, 3);
    switch (move)
    {
    case 1:
        moveLeft();
        break;
    case 2:
        moveUp();
        break;
    case 3:
        moveDown();
        break;
    default:
        break;
    }
}
void Position::moveUdR()
{
    int move = ranDom(1, 3);
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveUp();
        break;
    case 3:
        moveDown();
        break;
    default:
        break;
    }
}
void Position::moveDrl()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveDown();
        break;
    case 3:
        moveLeft();
        break;
    default:
        break;
    }
}
void Position::moveUrl()
{
    int move = ranDom(1, 2);
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveUp();
        break;
    case 3:
        moveLeft();
        break;
    default:
        break;
    }
}
void Position::moveany()
{
    int move = ranDom(1, 4); 
    switch (move)
    {
    case 1:
        moveRight();
        break;
    case 2:
        moveDown();
        break;
    case 3:
        moveLeft();
        break;
    case 4:
        moveUp();
        break;
    default:
        break;
    }
}
void Position::moveMent()
{
    if (x==0&&y==0) {this->moveRandD();}
    else if (x==0&&y==7) {this->moveLandD();}
    else if (x==9&&y==0) {this->moveRandU();}
    else if (x==9&&y==7) {this->moveUandL();}
    else if (y==7) {this->moveUdL();}
    else if (y==0) {this->moveUdR();}
    else if (x==0) {this->moveDrl();}
    else if (x==9) {this->moveUrl();}
    else {this->moveany();}
}
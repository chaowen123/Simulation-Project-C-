#include "aggressor.h"

Aggressor::Aggressor(const Position &pos, const Uninfected *hero) : Infected(pos, 'A') 
{
    this->hero = hero;
}
void Aggressor::move(const char move)
{
    // int userx{0};
    // int usery{0};
    // Position* tremUserPtr = this->hero->getPosition();
    // Position* tremAggresPtr = this->pos;
    // userx = tremUserPtr->x;
    // usery = tremUserPtr->y;
    // int aggrex =tremAggresPtr->x;
    // int aggrey =tremAggresPtr->y;
    // if((aggrex - 2)== userx||(aggrex - 1)== userx ){tremAggresPtr->moveUp();}
    // else if((aggrex + 2)== userx||(aggrex + 1)== userx ){tremAggresPtr->moveDown();}
    // else if((aggrey - 2)== usery||(aggrey - 1)== usery ){tremAggresPtr->moveLeft();}
    // else if((aggrey + 2)== usery||(aggrey + 1)== usery ){tremAggresPtr->moveRight();}
    // else{tremAggresPtr->moveMent();}

    Position* userPosPtr = this->hero->getPosition();
    Position* aggresPosPtr = this->pos;

    int userx = userPosPtr->x;
    int usery = userPosPtr->y;
    int aggrex = aggresPosPtr->x;
    int aggrey = aggresPosPtr->y;

    if (aggrex > userx) {
        aggresPosPtr->moveUp();
    } else if (aggrex < userx) {
        aggresPosPtr->moveDown();
    } else if (aggrey > usery) {
        aggresPosPtr->moveLeft();
    } else if (aggrey < usery) {
        aggresPosPtr->moveRight();
    } else {
        aggresPosPtr->moveMent(); // 默认行为
    }
}

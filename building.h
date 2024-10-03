// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "uninfected.h"
#include "infected.h"
#include "lounger.h"
#include "hyper.h"
#include "aggressor.h"


#ifndef BUILDING_H
#define BUILDING_H

#define ROW 10
#define CLOUM 8
// this class does not provide UI nor does it contain main.
class Building
{
    /** stream insertion operator overload */
    friend std::ostream &operator<<(std::ostream &, const Building &);

public:
    /** Building constructor. Initializes the Building */
    Building();

    int ranDom(const int, const int);
    void ranDomRange(const int);

    void setLounger();
    void setHyper();
    void setAggress();

    void setUser();
    void setScien();

    void setZero();

    void setMap();
    void setZumberPosition();
    void setUserPosition();
    void setScientistPosition();

    bool checkStates() const;
    bool checkWin() const;
    bool checkForScien() const;

    Position *getUserPosition() const;
    Position *getScienPosition() const;
    Uninfected *getUserMove() const;
    Uninfected *getScienMove() const;

    /** move the position of the spec-op
     @ parameter move the direction in which the spec-op must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */
    void move();
    void printMap() const;

    /** Building destructor. Deletes all heap based objects (including guards) */
    ~Building() {}

private:
    std::vector<Infected *> guards;
    Uninfected *specOp;
    Uninfected *scientist;
    int emptySpot[ROW][CLOUM]{0};
    int LoungerPosition[ROW][CLOUM]{0};
    int userPosition[ROW][CLOUM]{0};
    int scientistPosistion[ROW][CLOUM]{};
    int hyperPosition[ROW][CLOUM]{0};
    int aggrePosition[ROW][CLOUM]{0};
};

#endif
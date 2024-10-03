#include "building.h"

Building::Building()
{
    setLounger();
    setHyper();
    setAggress();
    setScien();
}

int Building::ranDom(const int start, const int end)
{
    return rand() % (end - start) + start;
}
void Building::ranDomRange(const int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int posiX = ranDom(1, 9);
        int posiy = ranDom(1, 7);
        while (emptySpot[posiX][posiy] != 0)
        {
            posiX = ranDom(1, 9);
            posiy = ranDom(1, 7);
        }
        emptySpot[posiX][posiy] = 1;
    }
}
void Building::setLounger()
{
    setZero();
    ranDomRange(6);
    size_t positionX{0};
    size_t positionY{0};

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (emptySpot[i][j] == 1)
            {
                positionX = i;
                positionY = j;
                Position term{positionX, positionY};
                guards.push_back(new Lounger{term});
            }
        }
    }
}
void Building::setHyper()
{
    setZero();
    ranDomRange(4);
    size_t positionX{0};
    size_t positionY{0};

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (emptySpot[i][j] == 1)
            {
                positionX = i;
                positionY = j;
                Position term{positionX, positionY};
                guards.push_back(new Hyper{term});
            }
        }
    }
}

void Building::setAggress()
{
    setZero();
    Position s{0, 0};
    specOp = new Uninfected{s, 'U'} ;

    ranDomRange(2);
    size_t positionX{0};
    size_t positionY{0};

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (emptySpot[i][j] == 1)
            {
                positionX = i;
                positionY = j;
                Position term{positionX, positionY};
                guards.push_back(new Aggressor{term, specOp});
            }
        }
    }
}
void Building::setScien()
{
    size_t x = ranDom(4, 5);
    size_t y = ranDom(3, 4);

    Position s{x, y};
    scientist = new Uninfected{s, 'S'};
    scientistPosistion[x][y] = 1;
}
void Building::move()
{
    for (Infected *i : guards)
    {
        i->move();
    }
}
void Building::setZero()
{
    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < CLOUM; j++)
        {
            emptySpot[i][j] = 0;
            userPosition[i][j] = 0;
            LoungerPosition[i][j] = 0;
            scientistPosistion[i][j] = 0;
            hyperPosition[i][j] = 0;
            aggrePosition[i][j] = 0;
        }
    }
}
void Building::setMap()
{
    setZero();
    setZumberPosition();
    setUserPosition();
    setScientistPosition();
}

void Building::setZumberPosition()
{
    for (Infected *i : guards)
    {
        char tempType = i->getType();
        Position *ptr = i->getPosition();
        if (tempType == 'L')
        {
            LoungerPosition[ptr->x][ptr->y] = 1;
        }
        else if (tempType == 'H')
        {
            hyperPosition[ptr->x][ptr->y] = 1;
        }
        else if (tempType == 'A')
        {
            aggrePosition[ptr->x][ptr->y] = 1;
        }
    }
}
void Building::setUserPosition()
{
    Position *ptr = specOp->getPosition();
    userPosition[ptr->x][ptr->y] = 1;
}
void Building::setScientistPosition()
{
    Position *ptr = scientist->getPosition();
    scientistPosistion[ptr->x][ptr->y] = 1;
}
bool Building::checkStates() const
{
    bool checkPoint = false;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < CLOUM; j++)
        {
            if (userPosition[i][j] == 1 && LoungerPosition[i][j] == 1)
            {
                return true;
            }
            if (userPosition[i][j] == 1 && hyperPosition[i][j] == 1)
            {
                return true;
            }
            if (userPosition[i][j] == 1 && aggrePosition[i][j] == 1)
            {
                return true;
            }
        }
    }
    return checkPoint;
}
bool Building::checkWin() const
{
    bool checkPoint = false;
    if (userPosition[0][0] == 1 && scientistPosistion[0][0] == 1)
    {
        return true;
    }
    return checkPoint;
}
bool Building::checkForScien() const
{
    bool checkPoint = false;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < CLOUM; j++)
        {
            if (userPosition[i][j] == 1 && scientistPosistion[i][j] == 1)
            {
                return true;
            }
        }
    }
    return checkPoint;
}

Position *Building::getUserPosition() const
{
    return specOp->getPosition();
}
Position *Building::getScienPosition() const
{
    return scientist->getPosition();
}
Uninfected *Building::getUserMove() const
{
    return this->specOp;
}
Uninfected *Building::getScienMove() const
{
    return this->scientist;
}

void Building::printMap() const
{
 std::cout << "---------------------------------\n";
    for (int i = 0; i < ROW; ++i)
    {
        // Print the first row with guards
        for (int j = 0; j < CLOUM; ++j)
        {
            std::string cell = "   ";  // Default empty cell
            
            if (LoungerPosition[i][j] == 1 && hyperPosition[i][j] == 1 && aggrePosition[i][j] == 1)
            {
                cell = "AHL";
            }
            else if (LoungerPosition[i][j] == 1 && hyperPosition[i][j] == 1)
            {
                cell = "HL ";
            }
            else if (LoungerPosition[i][j] == 1 && aggrePosition[i][j] == 1)
            {
                cell = "AL ";
            }
            else if (hyperPosition[i][j] == 1 && aggrePosition[i][j] == 1)
            {
                cell = "AH ";
            }
            else if (LoungerPosition[i][j] == 1)
            {
                cell = " L ";
            }
            else if (hyperPosition[i][j] == 1)
            {
                cell = " H ";
            }
            else if (aggrePosition[i][j] == 1)
            {
                cell = " A ";
            }
            
            std::cout << "|" << cell;
        }
        std::cout << "|\n";

        // Print the second row with user and scientist
        for (int j = 0; j < CLOUM; ++j)
        {
            std::string cell = "   ";  // Default empty cell
            
            if (userPosition[i][j] == 1 && scientistPosistion[i][j] == 1)
            {
                cell = "US ";
            }
            else if (userPosition[i][j] == 1)
            {
                cell = " U ";
            }
            else if (scientistPosistion[i][j] == 1)
            {
                cell = " S ";
            }
            
            std::cout << "|" << cell;
        }
        std::cout << "|\n";
        std::cout << "---------------------------------\n";
    }
}

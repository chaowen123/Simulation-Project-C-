// who: <Chaowen Cao  Mt SAC username: ccao13>
// what: <Rescue mission in progres>
// why: <Exam 3 project >
// when: <5-27-2022>

#include <iostream>

#include "building.h"
#include "clear.h"

void toLower(char &);
bool checkForBounce(const char, Building);
void voladateCheck(char &, Building);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Building s;
    char move;
    char theBreak = false;
    bool checkStates = false;
    bool checkWin = false;
    std::cout << "Rescue mission in progres\n";
    s.setMap();
    s.printMap();
    do
    {
        std::cout << "Your move [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";
        std::cin >> move;
        while (towlower(move) == 'p')
        {
            std::cout << "You pause the game enter [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";

            std::cout << "Your move [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";
            std::cin >> move;
            towlower(move);
        }
        voladateCheck(move, s);
        char carryanswer;
        s.getUserMove()->move(move);

        s.move();
        s.setMap();
        clearScreen();
        s.printMap();
        if (s.checkForScien() == true)
        {
            std::cout << "Would you carray the scientseis\n";
            std::cin >> carryanswer;
            toLower(carryanswer);
        }
        checkStates = s.checkStates();
        while (carryanswer == 'c')
        {
            std::cout << "Your move [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";
            std::cin >> move;
            while (towlower(move) == 'p')
            {
                std::cout << "You pause the game enter [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";

                std::cout << "Your move [U(up),D(dowm),L(left),R(right),P(put down),C(carry)]";
                std::cin >> move;
                towlower(move);
            }
            s.getUserMove()->move(move);
            s.getScienMove()->move(move);
            s.move();
            s.setMap();
            clearScreen();
            s.printMap();
            checkWin = s.checkWin();
            if (s.checkStates() == true)
            {
                checkStates = true;
                break;
            }
            if (checkWin == true)
            {
                std::cout << "You win!!!";
                theBreak = true;
                break;
            }
        }

        if (checkStates == true)
        {
            std::cout << "GAME OVER!!";
            break;
        }

    } while (theBreak == false);
    return 0;
}
void toLower(char &input)
{
    if (input >= 'A' && input <= 'Z')
        input = input + ('a' - 'A');
}
bool checkForBounce(const char move, Building s)
{
    Position *tmpePtr = s.getUserPosition();
    int x = tmpePtr->x;
    int y = tmpePtr->y;
    switch (move) {
        case 'r': return y < 7;
        case 'l': return y > 0;
        case 'u': return x > 0;
        case 'd': return x < 9;
        default: return false;
    }
}
void voladateCheck(char &move, Building s)
{
    towlower(move);
    while (checkForBounce(move, s) == false)
    {
        std::cout << "Invalid move!!\nPlease Enter again!!" << std::endl;
        std::cin >> move;
        towlower(move);
    }
}
void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}
void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(INT_MAX, '\n');
}
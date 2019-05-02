#ifndef ANT_HPP
#define ANT_HPP

#include <string>

class Ant
{
private:

    enum drxn { UP, RIGHT, DOWN, LEFT };

    int antRow;     //ant position variables
    int antColumn;
    char antColor;  
    int antDirection;

public:
    Ant();                      //default constructed
    Ant(int rw, int clmn);      //defined constructor

    // getter functions
    int getAntRow();
    int getAntColumn();

    // primary working function which takes current position and 
    // calculates next move
    void calculateMove(int nmClmns, int nmRws, char psnClr);

    // subfunctions called when needed by calculateMove
    void turnClockwise();
    void turnCounterclockwise();

};

#endif 
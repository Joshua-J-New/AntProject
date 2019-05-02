#include "Ant.hpp"
#include "Board.hpp"
#include <iostream>
#include <random>

/*****************************************************************************
**                              Ant::Ant
**  Default constructor for Ant -- assigning defaults of 0 to ant row and 
**  and column. 
*****************************************************************************/

Ant::Ant()
{
    antRow = 0;
    antColumn = 0; 
    antDirection = UP;
}

/*****************************************************************************
**                              Ant::Ant
**  Defined constructor for Ant -- assigning user-specified values
**  to ant row and and column.
*****************************************************************************/

Ant::Ant(int rw, int clmn)
{
    antRow = rw;
    antColumn = clmn;
    antDirection = UP;
}

/*****************************************************************************
**                              Ant::turnCounterclockwise
**  Function with single task - turning antDirection 90 degrees
**  counterclockwise.
*****************************************************************************/

void Ant::turnCounterclockwise()
{
    antDirection = (antDirection + 4 - 1) % 4;
}

/*****************************************************************************
**                              Ant::turnClockwise
**  Function with single task - turning antDirection 90 degrees clockwise.
*****************************************************************************/

void Ant::turnClockwise()
{   
    antDirection = (antDirection + 1) % 4;
}

// getter function for private variable, antRow
int Ant::getAntRow()
{
    return antRow;
}

// getter function for private variable, antColumn
int Ant::getAntColumn()
{
    return antColumn;
}

/*****************************************************************************
**                              Ant::calculateMove
**  Function which takes ant's current position and location color.  These are
**  used to determine new direction and location of ant.
*****************************************************************************/

void Ant::calculateMove(int nmRws, int nmClmns, char psnClr)
{

    int leftBoundary = 0;
    int topBoundary = 0;
    int rightBoundary = nmClmns;
    int bottomBoundary = nmRws;

    if (psnClr == ' ')
    {   
        turnClockwise();
    }
    if(psnClr == '#')
    {
        turnCounterclockwise();
    }
 
    if (antDirection == UP)
    {
        if (antRow == topBoundary)
        {
            antDirection = DOWN;
            antRow++; 
        }
        else 
        {
            antRow--;
        }
    }

    else if (antDirection == DOWN)
    {
        if (antRow == bottomBoundary)
        {
            antDirection = UP;
            antRow--;
        }
        else
        {
            antRow++;
        }
    }

    else if (antDirection == LEFT)
    {
        if (antColumn == leftBoundary)
        {
            antDirection = RIGHT;
            antColumn++;
        }
        else
            antColumn--;
    }

    else if (antDirection == RIGHT)
    {
        if (antColumn == rightBoundary)
        {
            antDirection = LEFT;
            antColumn--;
        }
        else
            antColumn++;
    }

}

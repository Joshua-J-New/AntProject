/*****************************************************************************
**  Program Name:   Langton's Ant (Board.cpp)
**  Author:         Joshua New
**  Date:           4/15/19
**  Description:    This file contains a board class with a default and user-
**                  specified board constructor, and destructor.  Additional
**                  functions for inserting and removing the ant from the board -
**                  along with one for inverting the color of vacated location
**                  and displaying the board are included for the class.  
**                  A getter and setter function were included for each private 
                    board menu likely to be of use externally. 
*****************************************************************************/

#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <random>

/*****************************************************************************
**                              Board::Board
**  Default constructor for Board -- assigning default value of 50 to board width
**  and height.  Fills board with default char, ' '. 
*****************************************************************************/

Board::Board()
{

    numRows = 50;
    numColumns = 50;
    
    charGrid = new char*[numRows]; // declaring first dimension of 2d matrix of integers of user-chosen size - 2x2 or 3x3

    for (int n = 0; n < numRows; n++)    // declaring second dimension of 2d matrix of integers 
        charGrid[n] = new char[numColumns];

    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numColumns; c++)
        {
            charGrid[r][c] = ' ';
        }
    }

}

/*****************************************************************************
**                              Board::Board
**  Defined constructor for Board -- assigning user-inputted values to board 
**  widthand height.  Fills board with default char, ' '.
*****************************************************************************/

Board::Board(int nmRws, int nmClmns, int nmStps)
{
    numRows = nmRws;
    numColumns = nmClmns;
    numSteps = nmStps;

    charGrid = new char*[numRows]; // declaring first dimension of 2d matrix of integers of user-chosen size - 2x2 or 3x3

    for (int n = 0; n < numRows; n++)    // declaring second dimension of 2d matrix of integers 
        charGrid[n] = new char[numColumns];

    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numColumns; c++)
        {
            charGrid[r][c] = ' ';
        }
    }

}


// getter function for private variable, numRows
int Board::getRows()
{
    return numRows;

}
// getter function for private variable, numColumns
int Board::getColumns()
{
    return numColumns;
}

// setter function for zeroing out private variable, currentStep
void Board::zeroCurrentStep()
{
    currentStep = 0;
}

// getter function for private variable, numSteps
void Board::setNumSteps(int stps)
{
    numSteps = stps;
}

// single function for incrementing private variable, currentStep
void Board::incrementCurrentStep()
{
    currentStep++;
}

// getter function for private variable, currentStep
int Board::getCurrentStep()
{
    return currentStep;
}

// getter function for private variable, numSteps
int Board::getNumSteps()
{
    return numSteps;
}

// getter function for getting location color from private 2d array, charGrid
char Board::getLocationColor(int rw, int clmn)
{
    return charGrid[rw][clmn];
}

// getter function for getting location color from private 2d array, charGrid
void Board::displayAnt(int rw, int clmn)
{
    charGrid[rw][clmn] = '*';
}

/*****************************************************************************
**                              Board::deleteAnt
**  Function which virtually deletes ant by assigning current ant location 
**  from * back to original color
*****************************************************************************/

void Board::deleteAnt(int rw, int clmn, char currClr)
{
    charGrid[rw][clmn] = currClr;
}

/*****************************************************************************
**                              Board::invertLocationColor
**  Function which inverts the ant's current location color
*****************************************************************************/

void Board::invertLocationcolor(int antRow, int antColumn, char locationColor)
{
    if (locationColor == ' ')
    {
        charGrid[antRow][antColumn] = '#';
    }
    else if (locationColor == '#')
    {
        charGrid[antRow][antColumn] = ' ';
    }
}


/*****************************************************************************
**                              Board::displayBoard
**  Function called each loop to display the board on the console
*****************************************************************************/

void Board::displayBoard()
{
    
    for (int a = 0; a < (numColumns + 2); a++)
        std::cout << '-';

    std::cout << std::endl;
    
    for (int x = 0; x < numRows; x++)
    {
        std::cout << '|';
        for (int y = 0; y < numColumns; y++)
            std::cout << charGrid[x][y];
        std::cout << '|';
        std::cout << std::endl;
    }
    
    for (int b = 0; b < (numColumns + 2); b++)
        std::cout << '-';
    
    std::cout << std::endl;
}

/*****************************************************************************
**                              Board::~Board
**  Defined destructor for Board class
*****************************************************************************/

Board::~Board()
{
    for (int j = 0; j < numRows; j++)  // deallocating the 2nd dimension of the array
        delete[] charGrid[j];

    delete[] charGrid;                 //deallocating the 1st dimensions of the array
}





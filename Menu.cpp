/*****************************************************************************
**  Program Name:   Langton's Ant (menu.cpp)
**  Author:         Joshua New
**  Date:           4/15/19
**  Description:    This file contains a menu class which prompts the user
**                  to input their desired board dimensions, number of steps
**                  to run for, and the beginning ant position.  A getter and
**                  setter function is also included for each private menu
**                  variable.  
*****************************************************************************/

#include <iostream>
#include "Menu.hpp"


bool Menu::displayMenu()
{
    int startQuit = 0;
    int boardMargin = 2;

    std::cout << std::endl << "LANGTON'S ANT SIMULATION" << std::endl;
    std::cout << "Enter 1 to Start" << std::endl;
    std::cout << "Enter 2 to Exit" << std::endl;

    std::cin >> startQuit;


    while (std::cin.fail() || startQuit < 1 || startQuit > 2)  //validate choice for integer 1 or 2
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Please enter 1 or 2: ";
        std::cin >> startQuit;
    }

    if (startQuit == 2)             //user quitting out
        return false;

    if (startQuit == 1)             //user chooses to begin simulation, enters board size, ant position, and num steps
    {
        
        std::cout << "How many ROWS would you like your board to have? ";
        std::cin >> numRows;
        while (std::cin.fail() || numRows < 1)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please enter a number: ";
            std::cin >> numRows;
        }

        std::cout << "How many COLUMNS would you like your board to have? ";
        std::cin >> numColumns;
        while (std::cin.fail() || numColumns < 1)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please enter a number: ";
            std::cin >> numColumns;
        }
        
        std::cout << "How many STEPS would you like the simulation to run? ";
        std::cin >> numSteps;
        while (std::cin.fail() || numSteps < 1)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please enter a number: ";
            std::cin >> numSteps;
        }

        std::cout << "Which ROW would you like the ant to start on? ";
        std::cin >> antRow;
        while (std::cin.fail() || antRow < 0 || antRow >= numRows )
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please enter a number between 1 and " << numRows  << ": ";
            std::cin >> antRow;
        }

        std::cout << "Which COLUMN would you like the ant to start on? ";
        std::cin >> antColumn;
        while (std::cin.fail() || antRow < 0 || antColumn >= numColumns )
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please enter a number between 1 and " << numColumns << ": ";
            std::cin >> antColumn;
        }

    }
    std::cout << std::endl;

    return true;
}

// getter function for private variable, numRows
int Menu::getNumRows()
{
    return numRows;
}

// getter function for private variable, numColumns
int Menu::getNumColumns()
{
    return numColumns;
}

// getter function for private variable, antRow
int Menu::getAntRow()
{
    return antRow;
}

// getter function for private variable, antColumn
int Menu::getAntColumn()
{
    return antColumn;
}

// getter function for private variable, numSteps
int Menu::getNumSteps()
{
    return numSteps;
}

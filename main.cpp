/*****************************************************************************
**  Program Name:   Langton's Ant (AntMain.cpp)
**  Author:         Joshua New
**  Date:           4/15/19
**  Description:    
**
**  This program generates a two-dimensional board which is traversed by an 
**  'ant'.  This ant moves according to the following rules, 1) when on a white
**  square, rotates 90 degrees clockwise and moves forward one square, 2) when
**  on a black square, rotates 90 degrees counterclockwise and moves forward
**  one square.  Each square that is occupied by the square has it's color 
**  inverted between black and white.  The board's dimensions are collected
**  from the user, as are the number of steps in the simulation.
**
**  *included makefile was authored by TA Harlan James and edited for use with
**   this program according to the explicit permission in the course "Make help"
**   page, "TA's Makefile Example
**          imsample.zip
**          You can use it for your own program by proper citation."
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <iostream>
//#include <Windows.h>

#include "Board.hpp"
#include "Menu.hpp"
#include "Ant.hpp"


int main()
{
    Menu antMenu;   // declare new instance of class antMenu

    bool runSim = false;    // boolean to track whether user inputs response to run sim or exit

    runSim = antMenu.displayMenu(); // 

    // tracking variables for current ant position and color
    int currentAntRow = 0;
    int currentAntColumn = 0;
    char currentColor = 'X';

    // variables for establishing board dimensions and simulation length
    int numBoardRows = 0;
    int numBoardColumns = 0;
    int numSteps = 0;

    // user chose option 2 in display menu to exit
    if (!runSim)
    {
        std::cout << "Ok, goodbye!" << std::endl;
        return 0;
    }

    // user chose option 1 in display menu to begin simulation
    do 
    {
        //pulling user-provided information from menu object to setup board and simulation
        numBoardRows = antMenu.getNumRows();
        numBoardColumns = antMenu.getNumColumns();
        numSteps = antMenu.getNumSteps();

        //pulling user-provided information from menu object to position ant
        currentAntRow = antMenu.getAntRow();
        currentAntColumn = antMenu.getAntColumn();

        //declare new board pulling number of rows, columns, and steps from menu object
        Board antBoard(numBoardRows, numBoardColumns, numSteps);

        antBoard.zeroCurrentStep();

        // declaring ant and setting first position
        Ant myAnt(currentAntRow, currentAntColumn);   
        
        while ( ( antBoard.getCurrentStep() ) < ( antBoard.getNumSteps() ) )
        {
            
            currentColor = antBoard.getLocationColor(currentAntRow, currentAntColumn);

            //accessing new ant position from ant object and updating position on board

           //briefly changing char at current location to '*'
            antBoard.displayAnt(currentAntRow, currentAntColumn);   
            antBoard.displayBoard();                                //printing board to console
            // changing char at current location to back to color, either ' ' or '#'
            antBoard.deleteAnt(currentAntRow, currentAntColumn, currentColor);
     
            //  passing board dimensions, and color of current location's color to 
            //  ant member function calculateMove to calculate next ant location
            myAnt.calculateMove(numBoardRows, numBoardColumns, currentColor );  

            // invert color at ant's current location, from ' ' to '#' or vice versa
            antBoard.invertLocationcolor(currentAntRow, currentAntColumn, currentColor); 
         
            // update current ant location - for displaying board
            currentAntRow = myAnt.getAntRow();
            currentAntColumn = myAnt.getAntColumn();
 
            // increment step counter
            antBoard.incrementCurrentStep();
      
        }
        // run menu to see if user wants to run another sim or exit
        runSim = antMenu.displayMenu();
        
    } while (runSim);

    
    
    return 0;
}



    
   





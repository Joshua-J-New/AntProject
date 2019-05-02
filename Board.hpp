#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

class Board
{
    private:
        int numRows;        // board dimensions
        int numColumns;   

        char** charGrid;    // 2d pointer to char array
        char currentAntPositionColor;     // variable to keep track of position color - useful while set to * and back for display
        int numSteps;                     //variables for tracking number of steps completed in simulation
        int currentStep;

    public:
        Board();            // default constructor
        Board(int nmRws, int nmClmns, int nmStps);  // defined constructor

        // getter functions
        int getRows();
        int getColumns();
        int getCurrentStep();
        int getNumSteps();
        char getLocationColor(int rw, int clmn);
        
        // setter functions
        void zeroCurrentStep();
        void setNumSteps(int stps);

        // simple incrementer function for tracking step of simulation
        void incrementCurrentStep ();
        

        void displayAnt(int currentRow, int currentColumn);
        void deleteAnt(int rw, int clmn, char currClr);     
        void invertLocationcolor(int antRow, int antColumn, char locationColor);

        void displayBoard();   

        ~Board();

};

#endif 

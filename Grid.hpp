
#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "Cell.hpp"
#include <string>

using namespace std;

class Grid{
    public:
        Grid(); //default constructor
        Grid(int rows, int cols); //overloaded constructor
        Grid(int rows, int cols, char values[10][10]); //overloaded constructor
        Grid(string m_filename); //overloaded constructor
        ~Grid(); //destructor

        //functons
        void print();
        void calcNextGenerationValuesForAllCells();
        void countNeighborsForAllCells();
        void moveToNextGeneration();

    protected:
        //attributes
        int cols;
        int rows;
        Cell* pCellArray[10][10]; //pointer to a char - array
        
        //functions
        void helpCountEdgeRowNeighbors(int curr_row, int neigh_row);
        void helpCountEdgeColNeighbors(int curr_col, int neigh_col);
};

#endif /* Grid_hpp */

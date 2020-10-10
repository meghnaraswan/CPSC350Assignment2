
#ifndef DoughnutGrid_hpp
#define DoughnutGrid_hpp

#include <stdio.h>
#include "Grid.hpp"

using namespace std;

//inheriting values and functions from Grid class
class DoughnutGrid : public Grid {
    public:
        DoughnutGrid(); //default constructor
        DoughnutGrid(int rows, int cols); //overloaded constructor
        DoughnutGrid(int rows, int cols, char values[10][10]); //overloaded constructor
        DoughnutGrid(string m_filename); //overloaded constructor
        ~DoughnutGrid(); //destructor
    
        //functions
        void countNeighborsForAllCells();
        void moveToNextGeneration();

    private:
        //functions
        void helpCountDoughnutCornerNeighbors(int curr_row, int curr_col);
        int complementIndex(int x, int max_val);
    
};


#endif /* DoughnutGrid_hpp */

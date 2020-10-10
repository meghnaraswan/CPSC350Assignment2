
#ifndef MirrorGrid_hpp
#define MirrorGrid_hpp

#include <stdio.h>
#include "Grid.hpp"

using namespace std;

//inheriting values and functions from Grid class
class MirrorGrid : public Grid {
    public:
        MirrorGrid(); //default constructor
        MirrorGrid(int rows, int cols); //overloaded constructor
        MirrorGrid(int rows, int cols, char values[10][10]); //overloaded constructor
        MirrorGrid(string m_filename); //overloaded constructor
        ~MirrorGrid(); //destructor
    
        //functions
        void countNeighborsForAllCells();
        void moveToNextGeneration();

    private:
        //functions
        void helpCountMirrorCornerNeighbors(int curr_row, int curr_col);
};

#endif /* MirrorGrid_hpp */

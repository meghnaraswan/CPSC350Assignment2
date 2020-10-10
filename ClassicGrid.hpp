
#ifndef ClassicGrid_hpp
#define ClassicGrid_hpp

#include <stdio.h>
#include "Grid.hpp"

using namespace std;

//inheriting values and functions from Grid class
class ClassicGrid : public Grid {
    public:
        ClassicGrid(); //default constructor
        ClassicGrid(int rows, int cols); //overloaded constructor
        ClassicGrid(int rows, int cols, char values[10][10]); //overloaded constructor
        ClassicGrid(string m_filename); //overloaded constructor
        ~ClassicGrid(); //destructor
};

#endif /* ClassicGrid_hpp */


#include <iostream>
#include <string>
#include "ClassicGrid.hpp"

//Classic Mode Grid

//default constructor
ClassicGrid::ClassicGrid(): Grid::Grid() {
    this->countNeighborsForAllCells();
}
//overloaded constructor
ClassicGrid::ClassicGrid(int rows, int cols): Grid::Grid(rows, cols){
    this->countNeighborsForAllCells();
}
//overloaded constructor
ClassicGrid::ClassicGrid(int rows, int cols, char values[10][10]): Grid::Grid(rows, cols, values){
    this->countNeighborsForAllCells();
}
//overloaded constructor
ClassicGrid::ClassicGrid(string m_filename): Grid::Grid(m_filename){
    this->countNeighborsForAllCells();
}
//destructor
ClassicGrid::~ClassicGrid(){
}


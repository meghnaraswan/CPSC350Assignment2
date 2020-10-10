
#include <iostream>
#include <string>
#include "MirrorGrid.hpp"

//Mirror Mode Grid

//default constructor
MirrorGrid::MirrorGrid():  Grid::Grid() {
    this->countNeighborsForAllCells();
}
//overloaded constructor
MirrorGrid::MirrorGrid(int rows, int cols): Grid::Grid(rows, cols){
    this->countNeighborsForAllCells();
}
//overloaded constructor
MirrorGrid::MirrorGrid(int rows, int cols, char values[10][10]): Grid::Grid(rows, cols, values){
    this->countNeighborsForAllCells();
}
//overloaded constructor
MirrorGrid::MirrorGrid(string m_filename): Grid::Grid(m_filename){
    this->countNeighborsForAllCells();
}
//destructor
MirrorGrid::~MirrorGrid(){
}
//calls calcNextGenerationValuesForAllCells() and countNeighborsForAllCells() functions from base class (Grid) to move the cells to the next generation
void MirrorGrid::moveToNextGeneration() {
    this->calcNextGenerationValuesForAllCells();
    this->countNeighborsForAllCells();
}
//calls countNeighborsForAllCells() function from base class (Grid) to count the classic neighbors
//class helpCountEdgeRowNeighbors() and helpCountEdgeColNeighbors() functions from base class (Grid) add the rows and columns neighbors
//calls helpCountMirrorCornerNeighbors() function to count the number of neighbors that contain an X
void MirrorGrid::countNeighborsForAllCells(){
    Grid::countNeighborsForAllCells();
    // rows edge
    this->helpCountEdgeRowNeighbors(0, 0); //current row is 0 and neighbor row is 0
    this->helpCountEdgeRowNeighbors(rows-1, rows-1); //current row is rows-1 and neighbor row is rows-1
    // columns edge
    this->helpCountEdgeColNeighbors(0, 0); //current column is 0 and neighbor column is 0
    this->helpCountEdgeColNeighbors(cols-1, cols-1); //current column is cols-1 and neighbor column is cols-1
    // all corners
    this->helpCountMirrorCornerNeighbors(0, 0); //current column is 0 and current row is 0
    this->helpCountMirrorCornerNeighbors(0,cols-1); //current column is cols-1 and current row is 0
    this->helpCountMirrorCornerNeighbors(rows-1, 0); //current column is 0 and current row is rows-1
    this->helpCountMirrorCornerNeighbors(rows-1, cols-1); //current column is cols-1 and current row is rows-1
}
//function that counts X's in corners
void MirrorGrid::helpCountMirrorCornerNeighbors(int curr_row, int curr_col){
    if(pCellArray[curr_row][curr_col]->getValue() == 'X') { //if the corner itself has an X, then add the X to the neighborCount
        pCellArray[curr_row][curr_col]->neighborCount++;
    }
}


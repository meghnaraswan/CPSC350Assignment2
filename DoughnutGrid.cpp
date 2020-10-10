
#include <iostream>
#include <string>
#include "DoughnutGrid.hpp"

//Doughnut Mode Grid

//default constructor
DoughnutGrid::DoughnutGrid(): Grid::Grid() {
    this->countNeighborsForAllCells();
}
//overloaded constructor
DoughnutGrid::DoughnutGrid(int rows, int cols): Grid::Grid(rows, cols){
    this->countNeighborsForAllCells();
}
//overloaded constructor
DoughnutGrid::DoughnutGrid(int rows, int cols, char values[10][10]): Grid::Grid(rows, cols, values){
    this->countNeighborsForAllCells();
}
//overloaded constructor
DoughnutGrid::DoughnutGrid(string m_filename): Grid::Grid(m_filename){
    this->countNeighborsForAllCells();
}
//destructor
DoughnutGrid::~DoughnutGrid(){
}
//calls calcNextGenerationValuesForAllCells() and countNeighborsForAllCells() functions from base class (Grid) to move the cells to the next generation
void DoughnutGrid::moveToNextGeneration() {
    this->calcNextGenerationValuesForAllCells();
    this->countNeighborsForAllCells();
}
//calls countNeighborsForAllCells() function from base class (Grid) to count the classic neighbors
//class helpCountEdgeRowNeighbors() and helpCountEdgeColNeighbors() functions from base class (Grid) add the rows and columns neighbors
//calls helpCountDoughnutCornerNeighbors() function to count the number of neighbors that contain an X
void DoughnutGrid::countNeighborsForAllCells(){
    Grid::countNeighborsForAllCells();
    // rows edge
    this->helpCountEdgeRowNeighbors(0, rows-1); //current row is 0 and neighbor row is rows-1
    this->helpCountEdgeRowNeighbors(rows-1, 0); //current row is rows-1 and neighbor row is 0
    // columns edge
    this->helpCountEdgeColNeighbors(0, cols-1); //current column is 0 and neighbor column is cols-1
    this->helpCountEdgeColNeighbors(cols-1, 0); //current column is cols-1 and neighbor column is 0
    // all corners
    this->helpCountDoughnutCornerNeighbors(0, 0); //current column is 0 and current row is 0
    this->helpCountDoughnutCornerNeighbors(rows-1, 0); //current column is cols-1 and current row is 0
    this->helpCountDoughnutCornerNeighbors(0, cols-1); //current column is 0 and current row is rows-1
    this->helpCountDoughnutCornerNeighbors(rows-1, cols-1); //current column is cols-1 and current row is rows-1
}
//function that counts X's in corners
void DoughnutGrid::helpCountDoughnutCornerNeighbors(int curr_row, int curr_col){
    int neigh_row = this->complementIndex(curr_row, rows-1); //calling complementIndex() identify the neighbor row as the opposite end of the grid
    int neigh_col = this->complementIndex(curr_col, cols-1); //calling complementIndex() identify the neighbor column as the opposite end of the grid
//    cout << "[" << curr_row << "," << curr_col <<"]:{" << neigh_row << "," << neigh_col << "}" << endl;
    if(pCellArray[neigh_row][neigh_col]->getValue() == 'X') { //if the neighbor cell equals X, then add the neighborCount
        pCellArray[curr_row][curr_col]->neighborCount++;
    }
}
//function to find the diagonal neighbor
//x is either 0 or the max amount of rows/columns to get the diagonal indexes of the corners
int DoughnutGrid::complementIndex(int x, int max_x){
    return max_x - x;
}

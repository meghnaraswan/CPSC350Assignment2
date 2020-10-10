//
//  Grid.cpp
//  FirstCPP
//
//  Created by iMan on 10/4/20.
//  Copyright © 2020 iMan. All rights reserved.
//

#include "Grid.hpp"
#include "Cell.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Grid

//default constructor
//default values of rows and columns of grid will be 5
Grid::Grid(){
    rows = 5;
    cols = 5;
}
//overloaded constructor
Grid::Grid(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            pCellArray[i][j] = new Cell(); //array consists of Cell datatype
        }
    }
}
//overloaded constructor
//array can hold up to 10 rows and 10 columns
Grid::Grid(int rows, int cols, char values[10][10]) {
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            pCellArray[i][j] = new Cell(values[i][j]); //array consists of Cell datatype that has char value
        }
    }
}
//overloaded constructor
Grid::Grid(string m_filename){
    //initialize rows, columns, and line count as 0
    this->rows = 0;
    this->cols = 0;
    int lineCount = 0;
    fstream newfile; //fstream is a stream class to both read and write from/to files.
    newfile.open(m_filename,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){  //checking to see whether the file is open
        string line;
        while(getline(newfile, line)){ //read data from file object and put it into string.
            if(lineCount == 0){ //the first line (or 0th index of the line) is the rows
                this->rows = stoi(line); //stoi converts data from a string type to an integer type
            } else if (lineCount == 1){ //the second line (or the 1st indext of the line) is the columns
                this->cols = stoi(line);
            } else {
                int i = lineCount - 2; //makes i starting from 0 since the first 2 lines were rows and columns
                for (int j = 0; j < sizeof(line); j++) //while going through each value in the string of 1 line, the value will be added into the array
                {
                    pCellArray[i][j] = new Cell(line[j]);
                }
            }
            ++lineCount; //increasing line count by 1 after reading though the next file
        }
        newfile.close(); //close the file object.
    }
    countNeighborsForAllCells(); //calling the countNeighborsForAllCells() function to count the neighbors for all cells (not including doughnut or mirror modes, those will be done in their individual classes)
}
//destructor
Grid::~Grid(){
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            delete pCellArray[i][j]; //delete each cell in array
        }
    }
}
//print() function prints the total rows and and columnsand then calls the toString method from Cell class to output each value of the cell in the respected rows and columns
void Grid::print() {
    cout << "[" << this->rows << ":" << this->cols <<"]" << endl;
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            cout << pCellArray[i][j]->toString();
        }
        cout << endl; //new line for the end of each row
    }
}
//function counts the number of X's each cell's neighbors have
void Grid::countNeighborsForAllCells() {
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            // reset count of neighbors
            pCellArray[i][j]->neighborCount = 0;
            int pii = (i-1 < 0) ? 0 : i-1; // prev edge boundary of the row
            int qii = (i+1>this->rows-1) ? this->rows-1 : i+1;// next edge boundary of the row
            int pjj = (j-1 < 0) ? 0 : j-1; // prev edge boundary of the col
            int qjj = (j+1>this->cols-1) ? this->cols-1 : j+1;// next edge boundary of the col
            // enter the boundary for each cell for calculating the neighbor count
            for (int ii = pii; ii <= qii; ++ii){ //rows
                for (int jj = pjj; jj <= qjj; ++jj){ //column
                    if (i == ii && j == jj) {
                        ; // do nothing or skip
                    } else {
                        if(pCellArray[ii][jj]->getValue() == 'X') { //if the neighbor has X value, increase the neighbor count by 1
                            pCellArray[i][j]->neighborCount++;
                        }
                    }
                }
            }
        }
    }
}
//uses the function calcNextGenVal() from Cell class to calculate the cell's value in the next generation at that positions depending on the number of neighbors that have Xs
void Grid::calcNextGenerationValuesForAllCells() {
    for (int i = 0; i < this->rows; ++i){ //rows
        for (int j = 0; j < this->cols; ++j){ //columns
            pCellArray[i][j]->calcNextGenVal();
        }
    }
}
//function move the cell to the next generation by calling the calcNextGenerationValuesForAllCells() and countNeighborsForAllCells() functions
void Grid::moveToNextGeneration() {
    this->calcNextGenerationValuesForAllCells();
    this->countNeighborsForAllCells();
}
//function counts the neighbors for each cell that is on the edge of the row, which is the same pattern followed for the Doughnut and Mirror modes
void Grid::helpCountEdgeRowNeighbors(int curr_row, int neigh_row){
    for(int j=0; j<cols; j++) { //for each column
        int pjj = (j-1 < 0) ? 0 : j-1; // prev edge boundary of the col
        int qjj = (j+1>cols-1) ? cols-1 : j+1; // next edge boundary of the col
        for (int jj = pjj; jj <= qjj; ++jj) {
            if(pCellArray[neigh_row][jj]->getValue() == 'X') { //if the neighbor has X value, increase the neighbor count by 1
                pCellArray[curr_row][j]->neighborCount++;
            }
        }
    }
}
//function counts the neighbors for each cell that is on the edge of the columns, which is the same pattern followed for the Doughnut and Mirror modes
void Grid::helpCountEdgeColNeighbors(int curr_col, int neigh_col){
    for(int i=0; i<rows; i++) { //for each row
        int pii = (i-1 < 0) ? 0 : i-1; //prev edge boundary of the row
        int qii = (i+1>rows-1) ? rows-1 : i+1; // next edge boundary of the row
        for (int ii = pii; ii <= qii; ++ii) {
            if(pCellArray[ii][neigh_col]->getValue() == 'X') { //if the neighbor has X value, increase the neighbor count by 1
                pCellArray[i][curr_col]->neighborCount++;
            }
        }
    }
}

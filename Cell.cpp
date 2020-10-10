
#include "Cell.hpp"
#include <iostream>
#include <string>

using namespace std;

//Cell

//default constructor
Cell::Cell(){
    value = '-';
}
//overloaded constructor
Cell::Cell(char v){
    value = v;
}
//destructor
Cell::~Cell(){
}
//toString function that returns the value as a char
char Cell::toString(){
    return this->value;
}
//accessor for value
char Cell::getValue() {
    return this->value;
}
//calculating the next generation value for each cell given the amount of neighbors that are X
void Cell::calcNextGenVal() {
    if(neighborCount <= 1) { //if the there is 1 or less neighbors, the next generation for that cell is -
        value = '-';
    } else if (neighborCount == 2){ //if the there are 2 neighbors, the next generation for that cell is the same as the previous generation
        ;
    } else if (neighborCount == 3){ //if the there are 3 neighbors, the next generation for that cell is X
        value = 'X';
    } else { //if there are 4 or more neighbors, the next generation for that cell is - due to overcrowding
        value = '-';
    }
}



#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
//#include "MyLinkedList.hpp"
#include <string>

using namespace std;

class Cell{
    public:
        Cell(); //default
        Cell(char v); //overloaded constructor
        ~Cell(); //destructor
    
        //furnctions
        char toString();
        void calcNextGenVal();
    
        // accessor
        char getValue();
    
        // attributes
        int neighborCount = 0;
    
    private:
        // attributes
        char value;
};

#endif /* Cell_hpp */


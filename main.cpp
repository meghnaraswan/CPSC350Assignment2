
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

#include "ClassicGrid.hpp"
#include "DoughnutGrid.hpp"
#include "MirrorGrid.hpp"
#include "Grid.hpp"
#include "Cell.hpp"

using namespace std;

int main(int argc, char *argv[]) {
//    string filename = "/home/FirstCPP/GameOfLife/assign2-testFile2.txt"; //this is for my reference since this file is in this path on my computer
    string filename = "assign2-testFile2.txt"; //default file
    string fileNoFileChoice = "N"; //default choice for if the user has a file or not
    string modeChoice = "C"; //default choice for type of mode
    //user file input
    cout << "Default FileName: " << filename << endl;
    cout << "New FileName (Press Enter to use default file): ";
    string newfilename;
    getline(cin, newfilename);
    if (newfilename.length() != 0) { //if the user enters a string, then the filename will be redifined by the new file name
        filename = newfilename;
    }
    cout << endl;
    //user mode input
    cout << "Which mode would you like to use? Classic ('c'), Doughnut ('d'), Mirror ('m'). (Press Enter for default mode as Classic): ";
    string newModeChoice;
    getline(cin, newModeChoice);
    if (newModeChoice.length() != 0) { //if the user enters a string, then the default mode will be redifined by the new mode choice
        modeChoice = newModeChoice;
    }
    cout << endl;
    //user generation input
    string genStr = "10"; //default number of generations in 10
    cout << "How many Generation? (Press Enter for default value of " << genStr << "): ";
    string newGenStr;
    getline(cin, newGenStr);
    if (newGenStr.length() != 0) { //if the user enters a string, then the default mode will be redifined by the new generation string number
        genStr = newGenStr;
    }
    int generationNumber = 10;
    stringstream ssGenStr(genStr); //converting string to integer
    ssGenStr >> generationNumber;
    cout << endl;
    cout << filename << " : " << modeChoice << " : " << generationNumber << endl; //shows the user what choices they chose
    cout << endl;
    int gen_i=1;
    cout << "Generation::" << gen_i << endl;
    if(modeChoice == "D" || modeChoice == "d") { //choice is D
        DoughnutGrid doughnutGrid = DoughnutGrid(filename); //making Doughnut Grid object
        doughnutGrid.print(); //calling print() function
        for (gen_i=2; gen_i <= generationNumber; gen_i++) { //for every generation that goes by, call moveToNextGeneration() and then print() function to display the generation
            cout << "Generation::" << gen_i << endl;
            doughnutGrid.moveToNextGeneration();
            doughnutGrid.print();
            cout << endl;
        }
    } else if(modeChoice == "M" || modeChoice == "m") { //choice is M
        MirrorGrid mirrorGrid = MirrorGrid(filename); //making Mirror Grid object
        mirrorGrid.print(); //calling print() function
        for (gen_i=2; gen_i <= generationNumber; gen_i++) { //for every generation that goes by, call moveToNextGeneration() and then print() function to display the generation
            cout << "Generation::" << gen_i << endl;
            mirrorGrid.moveToNextGeneration();
            mirrorGrid.print();
            cout << endl;
        }
    } else { //if(modeChoice == "C" || modeChoice == "c") {
        ClassicGrid classicGrid = ClassicGrid(filename); //making Classic Grid object
        classicGrid.print(); //calling print() function
        for (gen_i=2; gen_i <= generationNumber; gen_i++) { //for every generation that goes by, call moveToNextGeneration() and then print() function to display the generation
            cout << "Generation::" << gen_i << endl;
            classicGrid.moveToNextGeneration();
            classicGrid.print();
            cout << endl;
        }
    }
    cout << "Bye!!!" << endl; //Bye!!!
    return 0;
}

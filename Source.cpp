//============================================================================
// Name        : project2final.cpp
// Author      : Travis Waggoner
// Version     : 1.0
// Copyright   : Southern new hampshire univeristy
// Description : final project 2
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <cstdlib>

using namespace std;

void loadFile() {
    ifstream file; //Load file
    file.open("ABCU_Advising_Program_Input.txt"); //select text file
    if (file.is_open()) { // checks to see if file is open
        cout << "File is open." << endl; //tells user the file is good
    }
    else {
        cout << "File did not open." << endl; // tells user the file has a problem
    }
}

void sortFile() {
    vector<string> names; //sets up vector 

    ifstream file;//name for file in code
    file.open("ABCU_Advising_Program_Input.txt");//opens file and gives name

    string classes;//initalize classes
    while (getline(file, classes)) {// gets lines from class and pushes them back
        names.push_back(classes);
    }
    sort(classes.begin(), classes.end()); // sorts system
    for (size_t i = 0; i < classes.size(); i++) {// prints class list
        cout << classes[i] << endl;
    }

}

void printClass() {
    string search; //intitalizes search
    int set; // initalizes set
    string line;//initalizes line

    ifstream file;//set file name
    file.open("ABCU_Advising_Program_Input.txt");// open file
    cout << "Type name of class you are looking for?" << endl << "Enter Class Number: " << endl;//promt user to search for class
    cin >> search; // takes in users input
    if (file.is_open()) { //Makes sure the file is open and ready to search
        while (!file.eof()) { // while file is not the input
            getline(file, line);//get line
            if ((set = line.find(search, 0)) != string::npos) { // If word is found
                cout << "class found: " << endl << line << endl; //prints class information
            }
            file.close(); //Closes file

        }
        
    }
}



int main(int argc, char* argv[]) {
 //initalizes choice
    int choice = 0;
    //sets up menu
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course." << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        //sets up switch with choice as the input
        switch (choice) {

        case 1:
            loadFile; // refurs to the load file system
            break;

        


        case 2:
            sortFile; // refurs to the sort file section
            break;


        case 3:
            printClass; // prints  Class for user
            break;

        default: //corrects any users errors for inputs
            cout << "Error invald input please try one of the menu options.";
            break;

        }
        


    }

    return;
}
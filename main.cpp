//main.cpp
#include <iostream>
#include <string>
#include "creator.h"
#include "directions.h"


using namespace std;

int main() {
    //Prompting the user to create a game or continue from where they left off
    string initialChoice;
    cout << "Welcome to the Dungeon Crawl Game" << endl;
    cout << "Would you like to create a new game or load a previous game? (create/load)" << endl;
    cin >> initialChoice;
    cin.ignore();
    //Calling the creater function and fromspawn function based on initialChoice of "create"
    if (initialChoice == "create") {
        creator();
        fromSpawn();
    //Calling the loadCharacter function and fromOther function based on initialChoice of "load"
    } else if (initialChoice == "load") {
        loadCharacter();
        fromOther();
    } else {
        cout << "Invalid input. Please try again." << endl; 
    }
    
    return 0;
}
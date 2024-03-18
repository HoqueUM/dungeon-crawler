#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "loot.h"
#include "npcs.h"
#include "enemies.h"
#include "rewrite.h"

using namespace std;



void fromSpawn(){
    //This function works exactly the same as fromOther, it is just a different welcome message.
    string chosenPath;
    cout << "Welcome " << characterName << "!" << endl;
    cout << "You begin your journey at Grand Rapids Community College, tasked with the adventure of a lifetime: go to a mystical magical world filled with wonder." << endl;
    cout << "Your first assignment is to venture off into the unknown, given two options each time you do so." << endl;
    while(true){
        //Prompts the user to input whether they want to continue or not (yes = else statement, no = break the loop)
        cout << "Continue? (yes/no)" << endl;
        cin >> chosenPath;
        if (chosenPath == "no"){
            //Breaks the loop and calls the rewrite function
            cout << "Game has been terminated." << endl;
            rewrite();
            break;
            
        //Creating secret command that outputs every useful character info on json file
        } else if (chosenPath == "progress") {
            cout << "Room: " << location << endl;
            cout << "Experience: " << experience << endl;
            cout << "Experience needed: " << experienceNeeded << endl;
            cout << "Experience points: " << experiencePoints << endl;
            cout << "Health: " << health << endl;
            cout << "Attack: " << attack << endl;
            cout << "Defense: " << defense << endl;
            cout << "Luck: " << luck << endl;
            cout << "Gold: " << gold << endl;
            cout << "Weapons: " << endl;
            for (int i = 0; i < weaponsVector.size(); ++i) {
                cout << weaponsVector[i] << endl;
            }

            cout << "Potions: " << endl;
            for (int i = 0; i < potionsVector.size(); ++i){
                cout << potionsVector[i] << endl;
            }


        } else if (chosenPath == "spend") {
            string traitChoice;
            cout << "What would you like to increase?" << endl;
            cout << "attack" << endl;
            cout << "defense" << endl;
            cout << "luck" << endl;
            cin >> traitChoice;

            if (traitChoice == "attack") {
                attack++;
                experiencePoints--;
                cout << "Attack has increased to " << attack << "." << endl;
            } else if (traitChoice == "defense") {
                defense++;
                experiencePoints--;
                cout << "Defense has increased to " << attack << "." << endl;
            } else if (traitChoice == "luck") {
                luck++;
                experiencePoints--;
                cout << "Luck has increased to " << attack << "." << endl;
            }
            continue;
        
        } else {
            //Randomly selects a function to call 
            if (chosenPath == "yes"){
                //Gives experience each time the user progresses the game
                experience += 50;
                //Creating level up system
                if (experience == experienceNeeded) {
                    string experienceChoice;
                    string traitChoice;
                    level++;
                    experiencePoints++;
                    experienceNeeded += 500;
                    experience = 0;
                    cout << "Congratulations! You just leveled up to level " << level << " and received 1 experience point!" << endl;
                    cout << "Would you like to spend this now or save it for the next level up (spend/save)?" << endl;
                    cin >> experienceChoice;
                    if (experienceChoice == "spend"){
                        cout << "What would you like to increase?" << endl;
                        cout << "attack" << endl;
                        cout << "defense" << endl;
                        cout << "luck" << endl;
                        cin >> traitChoice;

                        if (traitChoice == "attack") {
                            attack++;
                            experiencePoints--;
                            cout << "Attack has increased to " << attack << "." << endl;
                        } else if (traitChoice == "defense") {
                            defense++;
                            experiencePoints--;
                            cout << "Defense has increased to " << attack << "." << endl;
                        } else if (traitChoice == "luck") {
                            luck++;
                            experiencePoints--;
                            cout << "Luck has increased to " << attack << "." << endl;
                        }
                        continue;
                    } else {
                        cout << "Player has chosen to wait until the next level up to spend experience points." << endl;
                        continue;
                    }
                    
                }

                int randomAction = rand() % 101;
                if ( 0 <= randomAction && randomAction <= 33) {
                    enemies();
                } else if(34 <= randomAction && randomAction <= 66){
                    loot();
                } else if(67 <= randomAction && randomAction <= 100) {
                    npc();
                }

                location += 1;
            } else {
                cout << "Incorrect path, please try again." << endl;

            }
        }
    }
}

void fromOther(){
    string chosenPath;
    cout << "Welcome back to the CIS 127 Dungeon Crawl Game " << characterName << "!" << endl;
    cout << "You last ended your journey at room #" << location << "." << endl;
    while(true){
        //Prompts the user to input whether they want to continue or not (yes = else statement, no = break the loop)
        cout << "Continue? (yes/no)" << endl;
        cin >> chosenPath;
        if (chosenPath == "no"){
            //Breaks the loop and calls the rewrite function
            cout << "Game has been terminated." << endl;
            rewrite();
            break;
        //Creating secret command that outputs every useful character info on json file
        } else if (chosenPath == "progress") {
            cout << "Room: " << location << endl;
            cout << "Experience: " << experience << endl;
            cout << "Experience needed: " << experienceNeeded << endl;
            cout << "Experience points: " << experiencePoints << endl;
            cout << "Health: " << health << endl;
            cout << "Attack: " << attack << endl;
            cout << "Defense: " << defense << endl;
            cout << "Luck: " << luck << endl;
            cout << "Gold: " << gold << endl;
            cout << "Weapons: " << endl;
            for (int i = 0; i < weaponsVector.size(); ++i) {
                cout << weaponsVector[i] << endl;
            }

            cout << "Potions: " << endl;
            for (int i = 0; i < potionsVector.size(); ++i){
                cout << potionsVector[i] << endl;
            }


        } else if (chosenPath == "spend") {
            string traitChoice;
            cout << "What would you like to increase?" << endl;
            cout << "attack" << endl;
            cout << "defense" << endl;
            cout << "luck" << endl;
            cin >> traitChoice;

            if (traitChoice == "attack") {
                attack++;
                experiencePoints--;
                cout << "Attack has increased to " << attack << "." << endl;
            } else if (traitChoice == "defense") {
                defense++;
                experiencePoints--;
                cout << "Defense has increased to " << attack << "." << endl;
            } else if (traitChoice == "luck") {
                luck++;
                experiencePoints--;
                cout << "Luck has increased to " << attack << "." << endl;
            }
            continue;
        
        } else {
            //Randomly selects a function to call
            if (chosenPath == "yes"){
                //Gives experience each time the user progresses the game
                experience += 50;
                //Creating level up system
                if (experience == experienceNeeded) {
                    string experienceChoice;
                    string traitChoice;
                    level++;
                    experiencePoints++;
                    experienceNeeded += 500;
                    experience = 0;
                    cout << "Congratulations! You just leveled up to level " << level << " and received 1 experience point!" << endl;
                    cout << "Would you like to spend this now or save it for the next level up (spend/save)?" << endl;
                    cin >> experienceChoice;
                    if (experienceChoice == "spend"){
                        cout << "What would you like to increase?" << endl;
                        cout << "attack" << endl;
                        cout << "defense" << endl;
                        cout << "luck" << endl;
                        cin >> traitChoice;
                        
                        if (traitChoice == "attack") {
                            attack++;
                            experiencePoints--;
                            cout << "Attack has increased to " << attack << "." << endl;
                        } else if (traitChoice == "defense") {
                            defense++;
                            experiencePoints--;
                            cout << "Defense has increased to " << attack << "." << endl;
                        } else if (traitChoice == "luck") {
                            luck++;
                            experiencePoints--;
                            cout << "Luck has increased to " << attack << "." << endl;
                        }
                        continue;
                    } else {
                        cout << "Player has chosen to wait until the next level up to spend experience points." << endl;
                        continue;
                    }
                    
                }
                int randomAction = rand() % 101;
                if ( 0 <= randomAction && randomAction <= 33) {
                    enemies();
                } else if(34 <= randomAction && randomAction <= 66){
                    loot();
                } else if(67 <= randomAction && randomAction <= 100) {
                    npc();
                }
                location += 1;

            } else {
                cout << "Incorrect path, please try again." << endl;
            }
        }
    }
 }
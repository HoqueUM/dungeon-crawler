#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;




void enemies(){
    //Defining variables for the enemies function
    string actionChoice;
    //Increases chances for damage based on character's luck trait
    double randMultiplier = luck * .1;
    vector<string> enemiesVector = {"Skeleton", "Goblin", "Ogre", "Troll"};
    //Chooses a random enemy from the enemiesVector
    int randEnemy = rand() % enemiesVector.size();
    string finalEnemy = enemiesVector[randEnemy];
    double enemyHealth = 100;
    //Scales the enemy health based on level of the character
    enemyHealth += enemyHealth * (level/10);
    cout << "You found a " << finalEnemy << "!" << endl;
    while (enemyHealth >= 0){
        //Prompts the user to choose whether they want to fight, use a potion, or flee
        int randDmg = rand() % 100;
        randDmg += randDmg * randMultiplier;
        cout << "Would you like to fight, use a potion or flee? (fight/potion/flee)" << endl;
        cin >> actionChoice;
        //Begins by prompting what weapon they would like to use (does not make a difference at the moment)
        if (actionChoice == "fight"){
            string weaponChoice;
            cout << "Please choose a weapon: " << endl;
            for (int i = 0; i < weaponsVector.size(); i++){
                cout << weaponsVector[i] << endl;
            }
            cin >> weaponChoice;
            for (int i = 0; i < weaponsVector.size(); i++){
                if (weaponChoice != weaponsVector[i]){
                    continue;
                } else if (weaponChoice == weaponsVector[i]){
                    cout << weaponChoice << " has been chosen!" << endl;
                    break;
                }
            }
            //Randomly does a set amount of damage to the enemy
            if (0 <= randDmg <= 75 ){
                cout << "You did 50 damage!" << endl;
                cout << "The " << finalEnemy <<"  hits you for 15 damage!" << endl;
                cout << "Health remaining: " << health << endl;
                cout << "Enemy health remaining: " << enemyHealth << endl;
                health -= 15;
                enemyHealth -= 50;
            } else if (76 <= randDmg <= 99){
                cout << "You did 75 damage!" << endl;
                cout << "The " << finalEnemy << " hits you for 15 damage!" << endl;
                cout << "Health remaining: " << endl;
                cout << "Enemy health remaining: " << enemyHealth;
                health -= 15;
                enemyHealth -= 75;
            } else {
                cout << "Congratulations! You just one hit the enemy!" << endl;
                enemyHealth = 0;
            }

            if (enemyHealth == 0) {
                experience += 50;
            }
        //Prompts the user what potion they would like to use based off of their inventory
        } else if (actionChoice == "potion") {
            string potionChoice;
            cout << "Please choose a potion:" << endl;
            for (int i = 0; i < potionsVector.size(); ++i){
                cout << potionsVector[i] << endl;
            }
            cin >> potionChoice;
            for (int i = 0; i < potionsVector.size(); ++i){
                if (potionChoice != potionsVector[i]){
                    continue;
                } else if (potionChoice == potionsVector[i]) {
                    potionsVector.erase(potionsVector.begin() + i);
                    cout << potionChoice << " has been chosen!" << endl;
                    //Increases health
                    if (potionChoice == "Health") {
                        health += 25;
                        cout << "Health has increased by 25 to " << health << endl;

                    //Increases damage for this instance only
                    } else if (potionChoice == "Damage") {
                        randDmg += 10;
                        cout << "Damage chances has been increased." << endl;
                    }
                    break;
                }
            }
        //Breaks the loop if flee
        } else if (actionChoice == "flee") {
            enemyHealth = 0;
            cout << "You have fled the fight and gain nothing from this encounter." << endl;
            break;
        }
    }
}
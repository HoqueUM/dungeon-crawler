#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;

int loot() {
    //Defines the possible loot and aggregates it in one vector
    vector<string> weaponsLoot = {"Sword", "Mace", "Dagger"};
    vector<string> potionsLoot = {"Healing", "Damage"};
    vector<int> goldLoot = {10, 20, 30, 40, 50};
    vector<pair<vector<string>, vector<int>>> allLoot = {{weaponsLoot, {}}, {potionsLoot, {}}, {{}, goldLoot}};

    //Randomly chooses which vector index to use
    int categoryIndex = rand() % allLoot.size();
    auto& categoryLoot = allLoot[categoryIndex];

    string lootName = "";
    int lootValue = 0;

    //Adds the values to the global variables based on the loot found
    if (!categoryLoot.first.empty()) {
        int lootIndex = rand() % categoryLoot.first.size();
        lootName = categoryLoot.first[lootIndex];
        if (categoryIndex == 0) {
            weaponsVector.push_back(lootName);
        } else if(categoryIndex == 1) {
            potionsVector.push_back(lootName);
        }
    }
    if (!categoryLoot.second.empty()) {
        int lootIndex = rand() % categoryLoot.second.size();
        lootValue = categoryLoot.second[lootIndex];
        gold += lootValue;
    }

    //Outputs what the user found
    if (!lootName.empty()) {
        if (lootName == "Sword" || lootName == "Mace" || lootName == "Dagger"){
            cout << "You have received a " << lootName << "!"<< endl;
        } else {
            cout << "You have received a " << lootName << " potion!"<< endl;
        }
    }
    if (lootValue > 0) {
        cout << "You have received " << lootValue << " gold coins!" << endl;
    }

    return 0;
}
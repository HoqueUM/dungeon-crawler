#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"


using namespace rapidjson;
using namespace std;

//Defining global variables
string characterName;
string characterRace;
string characterClass;
int location;
int characterLevel;
int experienceNeeded;
int experiencePoints;
int experience;
int health;
int attack;
int defense;
int level;
int luck;
int gold;
vector<string> weaponsVector;
vector<string> potionsVector;




void creator() {
    //Defines variables only used in the creater funciton
    potionsVector = {"Health", "Health", "Health", "Health", "Health"};
    string json;
    string startingWeapon;
    location = 1;
    experience = 0;
    experienceNeeded = 1000;
    experiencePoints = 0;
   
    //Prompting the user to give the name, race, and class of the character.
    cout << "Welcome to the CIS 127 Dungeon Crawl Game!" << endl;
    cout << "Please enter the name of your Character: " << endl;
    getline(cin, characterName);
    cout << "Please enter the race of your Character (human, elf, dwarf, orc): " << endl;
    cin >> characterRace;
    cout << "Welcome " << characterName << "!" << endl;
    cout << "Please enter the class of your Character (warrior, tank, assassin): " << endl;
    cin >> characterClass;

    //Initializes stats based on chosen class
    if (characterClass == "warrior" || characterClass == "tank" || characterClass == "assassin") {
        cout << "You are a " << characterRace << " " << characterClass << "!" << endl;
        level = 1;
        if (characterClass == "warrior") {
            cout << "You are a strong warrior with a sword and shield. I begin the game with well rounded stats and knowledge of the battlefield." << endl;
            startingWeapon = "Sword";
            weaponsVector.push_back(startingWeapon);
            health = 100;
            attack = 5;
            defense = 5;
            luck = 5;
            
        } else if (characterClass == "tank") {
            cout << "You are a strong sentinel with a mace and shield. You are a powerful being that towers over your opponents, hitting the hardest and the highest health." << endl;
            startingWeapon = "Mace";
            weaponsVector.push_back(startingWeapon);
            health = 125;
            attack = 10;
            defense = 10;
            luck = 3;
        } else if (characterClass == "assassin") {
            cout << "You are a powerful thief with a dagger and cloak. You are the fastest on the field, but at the cost of health." << endl;
            startingWeapon = "Dagger";
            weaponsVector.push_back(startingWeapon);
            health = 75;
            attack = 10;
            defense = 2;
            luck = 10;
        } 




    Document document;
    document.SetObject();
    Document::AllocatorType& allocator = document.GetAllocator();

    //Creating the character object
    document.AddMember("name", Value(characterName.c_str(), allocator).Move(), allocator);
    document.AddMember("race", Value(characterRace.c_str(), allocator).Move(), allocator);
    document.AddMember("class", Value(characterClass.c_str(), allocator).Move(), allocator);
    document.AddMember("location", location, allocator);
    document.AddMember("level", level, allocator);
    document.AddMember("experience", experience, allocator);
    document.AddMember("experienceNeeded", experienceNeeded, allocator);
    document.AddMember("experiencePoints", experiencePoints, allocator);

    //Creating the traits object
    Value traits(kObjectType);
    traits.AddMember("health", health, allocator);
    traits.AddMember("attack", attack, allocator);
    traits.AddMember("defense", defense, allocator);
    traits.AddMember("luck", luck, allocator);


    //Creating the inventory object
    Value inventory(kObjectType);
    inventory.AddMember("gold", gold, allocator);

    //Creating the items object
    Value items(kObjectType);
    Value weapons(kArrayType); 
    Value potions(kArrayType); 
    weapons.PushBack(Value(startingWeapon.c_str(), allocator).Move(), allocator);
    
    for (int i = 0; i < potionsVector.size(); i++){
        potions.PushBack(Value(potionsVector[i].c_str(), allocator).Move(), allocator);
    }
    items.AddMember("weapons", weapons, allocator);
    items.AddMember("potions", potions, allocator);
    
    //Adding the objects to the document
    inventory.AddMember("items", items, allocator);
    document.AddMember("traits", traits, allocator);
    document.AddMember("inventory", inventory, allocator);
    

    

    StringBuffer buffer;

    PrettyWriter<StringBuffer> writer(buffer);

    document.Accept(writer);

    json = buffer.GetString();
    
    string fileName = ".\\characters\\" + characterName + ".json";
   
    ofstream file(fileName);

    if (file.is_open()){
        file << json;
        file.close();
        cout << "File created successfully." << endl;
    } else {
        cout << "Unable to create file." << endl;
    }
    } else {
        cout << "Invalid input. Please try again." << endl;
    }




}

void loadCharacter(){
    //Welcoming back the user and opening the file to be read
    cout << "Welcome back to the CIS 127 Dungeon Crawl Game!" << endl;
    vector<string> characterNames;
    string directory = ".\\characters\\";
    DIR *dir;

    struct dirent *ent;

    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            struct stat statbuf;
            if (stat((directory + ent->d_name).c_str(), &statbuf) == -1) {
                continue;
            }
            if (S_ISREG(statbuf.st_mode) && ent->d_name[0] != '.') {
                string filename = ent->d_name;
                size_t extensionIndex = filename.find(".json");
                if (extensionIndex != string::npos) {
                    string characterName = filename.substr(0, extensionIndex);
                    characterNames.push_back(characterName);
                }
            }
        }
        closedir (dir);
    } else {
    cout << "Error: could not open directory" << endl;
    return;
    }

    //Gives the user the option to choose whether they want to select a character by name or number in the folder
    string preference;
    string filename;
    cout << "Would you like to select by number or name?" << endl;
    getline(cin, preference);

    if (preference == "number"){
        int characterChoice;
        cout << "Please choose a character: " << endl;
            for (int i = 0; i < characterNames.size(); i++){
                cout << i + 1 << ". " << characterNames[i] << endl;
            }
        cin >> characterChoice;
        cout << characterNames[characterChoice - 1] << " has been chosen!" << endl;
        filename = directory + characterNames[characterChoice - 1] + ".json";

    } else if (preference == "name"){
            string charChoice;
            cout << "Please choose a character: " << endl;

            for (int i = 0; i < characterNames.size(); i++){
                cout << i + 1 << ". " << characterNames[i] << endl;
            }
            getline(cin, charChoice);

            for (int i = 0; i < characterNames.size(); i++){
                if (charChoice == characterNames[i]){
                    cout << charChoice << " has been chosen!" << endl;
                    break;
                }
            }
        filename = directory + charChoice + ".json";
    } else {
        cout << "Incorrect input, process will now be terminated." << endl;
    }
    
    ifstream characterFile(filename);

    IStreamWrapper isw(characterFile);
    
    Document document;
    document.ParseStream(isw);

    //Reinitializing variables based o the values in the .json file
    characterName = document["name"].GetString();
    characterRace = document["race"].GetString();
    characterClass = document["class"].GetString();
    location = document["location"].GetInt();
    characterLevel = document["level"].GetInt();
    experience = document["experience"].GetInt();
    experienceNeeded = document["experienceNeeded"].GetInt();
    experiencePoints =  document["experiencePoints"].GetInt();
    health = document["traits"]["health"].GetInt();
    attack = document["traits"]["attack"].GetInt();
    defense = document["traits"]["defense"].GetInt();
    luck = document["traits"]["luck"].GetInt();
    gold = document["inventory"]["gold"].GetInt();
    const auto& weapons = document["inventory"]["items"]["weapons"].GetArray();
    const auto& potions = document["inventory"]["items"]["potions"].GetArray();


    for (SizeType i = 0; i < weapons.Size(); i++) {
        weaponsVector.push_back(weapons[i].GetString());
    }

    for (SizeType i = 0; i < potions.Size(); i++){
        potionsVector.push_back(potions[i].GetString());
    }

    
} 

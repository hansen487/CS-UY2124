//Hansen Chen, Medieval Battle Simulator
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct Warrior{
    string name;
    int strength;
    int count;
};

void Battle(Warrior& warrior1, Warrior& warrior2);

int main()
{
    vector<Warrior> warriors;
    ifstream ifs("warriors.txt");
    string file_text;
    while (ifs >> file_text){
        //Creates new Warrior
        if (file_text == "Warrior"){
            Warrior fighter;s
            ifs >> fighter.name;
            ifs >> fighter.strength;
            warriors.push_back(fighter);
        }
        //Simulates Battle
        else if (file_text == "Battle"){
            string w1;
            string w2;
            ifs >> w1;
            ifs >> w2;
            Warrior warrior1;
            Warrior warrior2;
            int counter = 0;
            //finds which warrior matches the names
            for (Warrior warrior : warriors){
                if (warrior.name == w1){
                    warrior1 = warrior;
                    warrior1.count = counter;
                }
                else if (warrior.name == w2){
                    warrior2 = warrior;
                    warrior2.count = counter;
                }
                counter++;
            }
            Battle(warrior1, warrior2);
            //updates the strengths of the warriors
            warriors[warrior1.count].strength = warrior1.strength;
            warriors[warrior2.count].strength = warrior2.strength;
        }
        //Prints Status
        else if (file_text == "Status"){
            cout << "There are: " << warriors.size() << " warriors" << endl;
            for (Warrior warrior : warriors){
                cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
            }
        }
    }
    ifs.close();
}

//Battle function
void Battle(Warrior& warrior1, Warrior& warrior2){
    cout << warrior1.name << " battles " << warrior2.name << endl;
    //Scenario if warrior 1 is stronger than warrior 2
    if (warrior1.strength > warrior2.strength){
        //scenario where warrior 2 is dead
        if (warrior2.strength == 0 && warrior1.strength != 0){
            cout << "He's dead, " << warrior1.name << endl;
        }
        //scenario where warrior 1 defeats warrior 2
        else{
            cout << warrior1.name << " defeats " << warrior2.name << endl;
        }
        //strength adjustments
        warrior1.strength -= warrior2.strength;
        warrior2.strength = 0;
    }
    //scenario where warrior 2 is stronger than warrior 1
    else if (warrior1.strength < warrior2.strength){
        //scenario where warrior 1 is dead
        if (warrior1.strength == 0 && warrior2.strength != 0){
            cout << "He's dead, " << warrior2.name << endl;
        }
    //scenario where warrior 2 defeats warrior 1
        else{
            cout << warrior2.name << " defeats " << warrior1.name << endl;
        }
        //strength adjustments
        warrior2.strength -= warrior1.strength;
        warrior1.strength = 0;
    }
    //in case warriors both have same strength
    else if (warrior1.strength == warrior2.strength){
        //scenario where they're both dead
        if (warrior1.strength == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        //scenario where they're equally matched
        else{
            cout << "Mutual Annihilation: " << warrior1.name <<" and " << warrior2.name << " die at each other's hands" << endl;
        }
        //strength adjustments
        warrior1.strength = warrior2.strength = 0;

    }
}


//Hansen Chen, Medieval Battle Simulator
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

//warrior class
class Warrior{
public:
    Warrior() {}
    Warrior(string& name, string& weapon_name, int& strength) : warrior_name(name), weapon(weapon_name, strength) {}
    string name(){
        return warrior_name;
    }
    string weapon_name(){
        return weapon.name();
    }
    int strength(){
        return weapon.strength();
    }

    void set_strength(int new_strength){
        weapon.set_strength(new_strength);
    }

    void subtract_strength(int number){
        weapon.subtract_strength(number);
    }

private:
    string warrior_name;
    //weapon class
    class Weapon{
        public:
            Weapon() {}
            Weapon(string& name, int& strength) : weapon_name(name), weapon_strength(strength) {}
            string name(){
                return weapon_name;
            }
            int strength(){
                return weapon_strength;
            }
            void set_strength(int new_strength){
                weapon_strength = new_strength;
            }

            void subtract_strength(int number){
                weapon_strength -= number;
            }
        private:
            string weapon_name;
            int weapon_strength;
    };
    Weapon weapon;
};

//prototype
void Battle(Warrior& warrior1, Warrior& warrior2);

int main()
{
    vector<Warrior> warriors;
    ifstream ifs("warriors.txt");
    string file_text;
    while (ifs >> file_text){
        //Creates new Warrior
        if (file_text == "Warrior"){
            int strength;
            string weapon_name, warrior_name;
            ifs >> warrior_name >> weapon_name >> strength;
            Warrior fighter(warrior_name, weapon_name, strength);
            warriors.push_back(fighter);
        }
        //Simulates Battle
        else if (file_text == "Battle"){
            string w1, w2;
            ifs >> w1 >> w2;
            Warrior warrior1, warrior2;
            int w1_count, w2_count;
            int counter = 0;
            //finds which warrior matches the names
            for (Warrior warrior : warriors){
                if (warrior.name() == w1){
                    warrior1 = warrior;
                    w1_count = counter;
                }
                else if (warrior.name() == w2){
                    warrior2 = warrior;
                    w2_count = counter;
                }
                counter++;
            }
            Battle(warrior1, warrior2);
            //updates the strengths of the warriors
            warriors[w1_count].set_strength(warrior1.strength());
            warriors[w2_count].set_strength(warrior2.strength());
        }
        //Prints Status
        else if (file_text == "Status"){
            cout << "There are: " << warriors.size() << " warriors" << endl;
            for (Warrior warrior : warriors){
                cout << "Warrior: " << warrior.name() << ", weapon: " << warrior.weapon_name() << ", " << warrior.strength() << endl;
            }
        }
    }
    ifs.close();
}

//Battle function
void Battle(Warrior& warrior1, Warrior& warrior2){
    cout << warrior1.name() << " battles " << warrior2.name() << endl;
    //Scenario if warrior 1 is stronger than warrior 2
    if (warrior1.strength() > warrior2.strength()){
        //scenario where warrior 2 is dead
        if (warrior2.strength() == 0 && warrior1.strength() != 0){
            cout << "He's dead, " << warrior1.name() << endl;
        }
        //scenario where warrior 1 defeats warrior 2
        else{
            cout << warrior1.name() << " defeats " << warrior2.name() << endl;
        }
        //strength adjustments
        warrior1.subtract_strength(warrior2.strength());
        warrior2.set_strength(0);
    }
    //scenario where warrior 2 is stronger than warrior 1
    else if (warrior1.strength() < warrior2.strength()){
        //scenario where warrior 1 is dead
        if (warrior1.strength() == 0 && warrior2.strength() != 0){
            cout << "He's dead, " << warrior2.name() << endl;
        }
    //scenario where warrior 2 defeats warrior 1
        else{
            cout << warrior2.name() << " defeats " << warrior1.name() << endl;
        }
        //strength adjustments
        warrior2.subtract_strength(warrior1.strength());
        warrior1.set_strength(0);
    }
    //in case warriors both have same strength
    else if (warrior1.strength() == warrior2.strength()){
        //scenario where they're both dead
        if (warrior1.strength() == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        //scenario where they're equally matched
        else{
            cout << "Mutual Annihilation: " << warrior1.name() <<" and " << warrior2.name() << " die at each other's hands" << endl;
        }
        //strength adjustments
        warrior1.set_strength(0);
        warrior2.set_strength(0);

    }
}


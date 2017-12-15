//Hansen Chen, medieval simulation with dynamic memory
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Warrior class
class Warrior{
public:
    Warrior(const string& name, int strength) : warrior_name(name), warrior_strength(strength) {}

    void set_hired(bool status) {
        hired = status;
    }

    bool get_hired_status() const{
        return hired;
    }

    string get_name() const{
        return warrior_name;
    }

    int get_strength() const{
        return warrior_strength;
    }

    bool status() const{
        return dead;
    }

    void set_strength(int new_strength){
        warrior_strength = new_strength;
    }
private:
    string warrior_name;
    int warrior_strength;
    bool hired = false;
    bool dead = false;
};

//Noble Class
class Noble{
public:
    Noble(const string& name) : noble_name(name) {}
    ~Noble(){
        for (Warrior* warrior: army){
            delete warrior;
        }
        army.clear();
    }

    void hire(Warrior* warrior){
        if (warrior -> get_hired_status() == false && warrior -> status() == false){
            army.push_back(warrior);
            warrior -> set_hired(true);
            noble_strength += warrior -> get_strength();
        }
        else{
            cout << "Warrior " << warrior -> get_name() << " is already hired!" << endl;
            exit(1);
        }
    }

    void fire(Warrior* fired, const int position){
        if (fired == nullptr && position == -1){
            cout << "Error! Warrior isn't hired" << endl;
            exit(1);
        }
        else{
            cout << "You don't work for me anymore " << fired -> get_name() << "! -- " << noble_name << '.' << endl;
            noble_strength -= fired -> get_strength();
            swap(army[position], army[army.size() - 1]);
            fired -> set_hired(false);
            army.pop_back();
        }

    }

    void display() const{
        cout << noble_name << " has an army of " << army.size() << endl;
        for (Warrior* warrior: army){
            cout << '\t' << warrior -> get_name() << ": " << warrior -> get_strength() << endl;
        }
    }

    void battle(Noble* other_noble){
        cout << noble_name << " battles " << other_noble -> get_name() << endl;
        //if both nobles are dead
        if (noble_strength == other_noble -> noble_strength){
            if (noble_strength == 0){
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
            else{
                cout << "Mutual Annihilation: " << noble_name << " and " << other_noble -> get_name() << " die at each other's hands" << endl;
                noble_strength = 0;
                for (Warrior* warrior: army){
                    warrior -> set_strength(0);
                }
                other_noble -> noble_strength = 0;
                for (Warrior* warrior: other_noble -> army){
                    warrior -> set_strength(0);
                }
            }
        }
        else{
            //if only one noble is dead
            if (other_noble -> noble_strength == 0){
                cout << "He's dead " << noble_name << endl;
            }
            //else, simulate battle
            else if (noble_strength != 0 && other_noble -> noble_strength != 0){
                if (noble_strength > other_noble -> noble_strength){
                    cout << noble_name << " defeats " << other_noble -> noble_name << endl;
                    int old_strength = other_noble -> noble_strength;
                    //decrease winning noble's strength
                    for (Warrior* warrior: army){
                        warrior -> set_strength(warrior -> get_strength() - old_strength);
                    }
                    //set the losing noble's strength and his warrior's strengths to 0
                    other_noble -> noble_strength = 0;
                    for (Warrior* warrior: other_noble -> army){
                        warrior -> set_strength(0);
                    }
                }
            }
        }
    }

    string get_name() const{
        return noble_name;
    }

    int get_strength() const{
        return noble_strength;
    }

    vector<Warrior*> get_army() const{
        return army;
    }

    Warrior* find_warrior(string& warrior_name){
        for (Warrior* warrior: army){
            if (warrior_name == warrior -> get_name()){
                return warrior;
            }
        }
        return nullptr;
    }

    int find_position(string& warrior_name){
        int position = 0;
        for (Warrior* warrior: army){
            if (warrior_name == warrior -> get_name()){
                return position;
            }
            position++;
        }
        return -1;
    }

private:
    string noble_name;
    vector<Warrior*> army;
    int noble_strength = 0;
};

int main()
{
    vector<Noble*> nobles;
    vector<Warrior*> warriors;
    ifstream ifs("nobleWarriors.txt");
    string action;

    while (ifs >> action){
        if (action == "Noble"){
            string noble_name;
            ifs >> noble_name;
            bool noble_exists = false;
            if (nobles.size() != 0){
                for (Noble* noble: nobles){
                    if (noble -> get_name() == noble_name){
                        cout << "Error! Noble already exists!" << endl;
                        noble_exists = true;
                        exit(1);
                    }
                }
            }
            if (noble_exists == false){
                Noble* noble = new Noble(noble_name);
                nobles.push_back(noble);
            }
        }

        else if(action == "Warrior"){
            string warrior_name;
            int strength;
            ifs >> warrior_name >> strength;
            bool warrior_exists = false;
            if (warriors.size() != 0){
                for (Warrior* warrior: warriors){
                    if (warrior -> get_name() == warrior_name){
                        cout << "Error! Warrior " << warrior_name << " already exists!" << endl;
                        warrior_exists = true;
                        exit(1);
                    }
                }
            }
            if (warrior_exists == false){
                Warrior* warrior = new Warrior(warrior_name, strength);
                warriors.push_back(warrior);
            }
        }

        else if(action == "Hire"){
            string noble_name, warrior_name;
            ifs >> noble_name >> warrior_name;
            int position = 0;
            for (Noble* noble: nobles){
                if (noble -> get_name() == noble_name){
                    int counter = 0;
                    for (Warrior* warrior: warriors){
                        if (warrior -> get_name() == warrior_name){
                            position = counter;
                            noble -> hire(warrior);
                        }
                        counter++;
                    }
                }
            }
            swap(warriors[position], warriors[warriors.size() - 1]);
            warriors.pop_back();
        }

        else if(action == "Status"){
            cout << "Status" << endl;
            cout << "======" << endl;
            cout << "Nobles" << endl;
            if (nobles.size() == 0){
                cout << "NONE" << endl;
            }
            else{
                for (Noble* noble: nobles){
                vector<Warrior*> army = noble -> get_army();
                cout << noble -> get_name() <<" has an army of "<< army.size() << endl;
                    for (Warrior* warrior: army){
                    cout << '\t' << warrior -> get_name() << ": " << warrior -> get_strength() << endl;
                    }
                }
            }
            cout << "Unemployed Warriors:" << endl;
            if (warriors.size() == 0){
                cout << "NONE" << endl;
            }
            else{
                for (Warrior* warrior: warriors){
                    cout << warrior -> get_name() << ": " << warrior -> get_strength() << endl;
                }
            }
        }

        else if (action == "Fire"){
            string noble_name, warrior_name;
            ifs >> noble_name >> warrior_name;
            bool noble_exists = false;
            for (Noble* noble: nobles){
                if (noble -> get_name() == noble_name){
                    noble_exists = true;
                    Warrior* fired_warrior = noble -> find_warrior(warrior_name);
                    noble -> fire(fired_warrior, noble -> find_position(warrior_name));
                    warriors.push_back(fired_warrior);
                }
            }
            if (noble_exists == false){
                cout << "Noble doesn't exist" << endl;
                exit(1);
            }
        }

        else if (action == "Battle"){
            string noble1_name, noble2_name;
            Noble* noble1 = nullptr;
            Noble* noble2 = nullptr;
            ifs >> noble1_name >> noble2_name;
            for (Noble* noble: nobles){
                if (noble1_name == noble -> get_name()){
                    noble1 = noble;
                }
                else if (noble2_name == noble -> get_name()){
                    noble2 = noble;
                }
            }
            noble1 -> battle(noble2);
        }

        else if (action == "Clear"){
        for (Noble* noble: nobles){
            delete noble;
        }
        nobles.clear();
        for (Warrior* warrior: warriors){
            delete warrior;
        }
        warriors.clear();
        }
    }
}


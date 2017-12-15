#include "protector.h"
#include "noble.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

namespace WarriorCraft{
    class Protector;

    Noble::Noble(const string& name){
        noble_name = name;
    }

    void Noble::hire(Protector& protector){
        if (protector.get_hired_status() == false && protector.status() == false){
            army.push_back(&protector);
            protector.set_hired(true);
            noble_strength += protector.get_strength();
            protector.set_noble(this);
        }
        else{
            cout << "Protector " << protector.get_name() << " is already hired!" << endl;
            exit(1);
        }
    }

    void Noble::fire(Protector& fired){
        if (fired.status() == false){
            cout << "Error! Protector isn't hired" << endl;
            exit(1);
        }
        else{
            cout << "You don't work for me anymore " << fired.get_name() << "! -- " << noble_name << '.' << endl;
            noble_strength -= fired.get_strength();
            int position = find_position(fired.get_name());
            swap(army[position], army.back());
            army.pop_back();
        }

    }

    int Noble::find_position(const string& name){
        int position = 0;
        for (Protector* protector: army){
            if (name == protector -> get_name()){
                return position;
            }
            position++;
        }
        return -1;
    }

    void Noble::remove_warrior(const string& name){
        int position = find_position(name);
        noble_strength -= army[position] -> get_strength();
        swap(army[position], army.back());
        army.pop_back();
    }

//    ostream& operator<< (ostream& os, const Noble& rhs){
//        cout << rhs.noble_name << " has an army of " << rhs.army.size() << endl;
//        for (Protector* protector: rhs.army){
//            cout << protector << endl;
//        }
//        return os;
//    }

    void Noble::battle(Noble& other_noble){
        cout << noble_name << " battles " << other_noble.get_name() << endl;
        //if both nobles are dead
        if (noble_strength == other_noble.noble_strength){
            if (noble_strength == 0){
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
            else{
                cout << "Mutual Annihilation: " << noble_name << " and " << other_noble.get_name() << " die at each other's hands" << endl;
                noble_strength = 0;
                for (Protector* protector: army){
                    protector -> set_strength(0);
                }
                other_noble.noble_strength = 0;
                for (Protector* protector: other_noble.army){
                    protector -> set_strength(0);
                }
            }
        }
        else{
            //if only one noble is dead
            if (other_noble.noble_strength == 0){
                cout << "He's dead " << noble_name << endl;
            }
            //else, simulate battle
            else if (noble_strength != 0 && other_noble.noble_strength != 0){
                if (noble_strength > other_noble.noble_strength){
                    cout << noble_name << " defeats " << other_noble.noble_name << endl;
                    int old_strength = other_noble.noble_strength;
                    //decrease winning noble's strength
                    for (Protector* protector: army){
                        protector -> set_strength(protector -> get_strength() - old_strength);
                    }
                    //set the losing noble's strength and his warrior's strengths to 0
                    other_noble.noble_strength = 0;
                    for (Protector* protector: other_noble.army){
                        protector -> set_strength(0);
                    }
                }
            }
        }
    }


    string Noble::get_name() const{
        return noble_name;
    }

    int Noble::get_strength() const{
        return noble_strength;
    }

    vector<Warrior> Noble::get_army() const{
        return army;
    }
}


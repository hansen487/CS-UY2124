#include "protector.h"
#include "noble.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
namespace WarriorCraft{
    class Protector;

    Noble::Noble(const string& name) : noble_name(name) {}
    Noble::Noble(const string& name, int strength) : noble_name(name), noble_strength(strength) {}

    string Noble::get_name() const{
        return noble_name;
    }

    void Noble::hires(Protector& protector){
        if (protector.get_hired_status() == false && protector.status() == false){
            army.push_back(&protector);
            noble_strength += protector.get_strength();
            protector.set_noble(this);
        }
    }

    void Noble::fire(Protector& fired){
        if (fired.status() == false){
            cout << "Error! Warrior isn't hired" << endl;
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

    int Noble::get_strength()const {
        return noble_strength;
    }

    void Noble::set_status(){
        dead = !dead;
    }

    bool Noble::get_status(){
        return dead;
    }

    void Noble::battle(Noble& other_noble){
        cout << noble_name << " battles " << other_noble.get_name() << endl;
        if (army.size() != 0 && dead == false){
            for (Protector* protector: army){
                if (protector -> status() == false){
                    protector -> battlecry();
                }
            }
        }
        //if both nobles are dead
        if (dead == true || other_noble.dead == true){
            if (dead == true && other_noble.dead == true){
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
            else if (dead == true){
                cout << "He's dead, " << other_noble.get_name() << endl;
            }
            else if (other_noble.dead == true) {
                cout << "He's dead, " << noble_name << endl;
            }
        }

        else if (noble_strength == other_noble.noble_strength){
            cout << "Mutual Annihilation: " << noble_name << " and " << other_noble.get_name() << " die at each other's hands" << endl;
            noble_strength = 0;
            dead = true;
            for (Protector* protector: army){
                protector -> set_strength(0);
            }
            other_noble.noble_strength = 0;
            for (Protector* protector: other_noble.army){
                protector -> set_strength(0);
            }
            other_noble.dead = true;
        }
        else{
            if (noble_strength > other_noble.get_strength()){
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
                other_noble.set_status();
            }
            else{
                cout << other_noble.noble_name << " defeats " << noble_name << endl;
                int old_strength = noble_strength;
                for (Protector* protector: other_noble.army) {
                    protector -> set_strength(protector -> get_strength() - old_strength);
                }
                noble_strength = 0;
                for (Protector* protector: army){
                    protector -> set_strength(0);
                }
                dead = true;
            }
        }
    }

    void Noble::remove_warrior(const string& name){
        int position = find_position(name);
        noble_strength -= army[position] -> get_strength();
        swap(army[position], army.back());
        army.pop_back();
    }
}



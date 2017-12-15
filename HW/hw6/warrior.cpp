#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{
        class Noble;

        Warrior::Warrior(const string& name, int strength) {
            warrior_name = name;
            warrior_strength = strength;
        }

        void Warrior::set_hired(bool status) {
            hired = status;
        }

        bool Warrior::get_hired_status() const{
            return hired;
        }

        string Warrior::get_name() const{
            return warrior_name;
        }

        int Warrior::get_strength() const{
            return warrior_strength;
        }

        bool Warrior::status() const{
            return dead;
        }

        void Warrior::set_strength(int new_strength){
            warrior_strength = new_strength;
        }

        void Warrior::set_noble(Noble* noble_ptr){
            noble = noble_ptr;
        }

        void Warrior::runaway(){
            cout << warrior_name << " flees in terror, abandoning his lord, " << noble -> get_name() << endl;
            noble -> remove_warrior(warrior_name);
            hired = false;
            noble = nullptr;
        }

        ostream& operator<< (std::ostream& os, const Warrior& rhs){
            cout << '\t' << rhs.warrior_name << ": " << rhs.warrior_strength;
        }
}

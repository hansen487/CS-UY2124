#include "protector.h"
#include "noble.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace WarriorCraft{
    class Noble;

    Protector::Protector(const string& name, int strength) : name(name), strength(strength) {}

    bool Protector::get_hired_status() const{
        return (noble != nullptr);
    }

    void Protector::battlecry() const{};

    string Protector::get_name() const{
        return name;
    }

    Noble* Protector::get_noble() const{
        return noble;
    }

    bool Protector::status() const{
        return strength == 0;
    }

    int Protector::get_strength() const{
        return strength;
    }

    void Protector::set_noble(Noble* hired){
        noble = hired;
    }

    void Protector::set_strength(int increment){
        strength = increment;
    }


    void Protector::runaway(){
        cout << name << " flees in terror, abandoning his lord, " << noble -> get_name() << endl;
        noble -> remove_warrior(name);
        noble = nullptr;
    }
}

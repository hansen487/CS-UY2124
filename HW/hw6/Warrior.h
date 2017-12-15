#ifndef WARRIOR_H_INCLUDED
#define WARRIOR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Noble.h"


namespace WarriorCraft{
    class Noble;

    class Warrior{
        friend std::ostream& operator<< (std::ostream& os, const Warrior& rhs);
    public:
        Warrior(const std::string& name, int strength);

        void set_hired(bool status);
        bool get_hired_status() const;
        std::string get_name() const;
        int get_strength() const;
        bool status() const;
        void set_strength(int new_strength);
        void runaway();
        void set_noble(Noble* noble_ptr);
    private:
        std::string warrior_name;
        int warrior_strength;
        bool hired = false;
        bool dead = false;
        Noble* noble = nullptr;
    };
}


#endif // WARRIOR_H_INCLUDED

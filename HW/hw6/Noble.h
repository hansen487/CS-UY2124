#ifndef NOBLE_H_INCLUDED
#define NOBLE_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "Warrior.h"


namespace WarriorCraft{
    class Warrior;

    class Noble{
        friend std::ostream& operator<< (std::ostream& os, const Noble& rhs);
    public:
        Noble(const std::string& name);
        void hire(Warrior& warrior);
        void fire(Warrior& fired);
        void battle(Noble& other_noble);
        std::string get_name() const;
        int get_strength() const;
        std::vector<Warrior> get_army() const;
        int find_position(const std::string& name);
        void remove_warrior(const std::string& name);


    private:
        std::string noble_name;
        std::vector<Warrior> army;
        int noble_strength = 0;
    };
}



#endif // NOBLE_H_INCLUDED

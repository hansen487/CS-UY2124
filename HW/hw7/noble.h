#ifndef NOBLE_H_INCLUDED
#define NOBLE_H_INCLUDED
#include "protector.h"
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft{
    class Protector;
    class Noble{
    public:
        Noble(const std::string& name);
        Noble(const std::string& name, int strength);
        virtual void hires(Protector& protector);
        virtual void fire(Protector& protector);
        virtual void battle(Noble& other_noble);
        std::string get_name() const;
        int find_position(const std::string& name);
        int get_strength() const;
        void set_status();
        bool get_status();
        void remove_warrior(const std::string& name);
    private:
        std::string noble_name;
        int noble_strength = 0;
        std::vector<Protector*> army;
        bool dead = false;
    };
}



#endif // NOBLE_H_INCLUDED

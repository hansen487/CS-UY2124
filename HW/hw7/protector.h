#ifndef PROTECTOR_H_INCLUDED
#define PROTECTOR_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "noble.h"

namespace WarriorCraft{
    class Noble;
    class Protector{
    public:
        Protector(const std::string& name, int strength);
        bool get_hired_status() const;
        virtual void battlecry() const;
        std::string get_name() const;
        int get_strength() const;
        void runaway();
        Noble* get_noble() const;
        bool status() const;
        void set_noble(Noble* hired);
        void set_strength(int increment);

    private:
        std::string name;
        int strength;
        Noble* noble = nullptr;
    };
}


#endif // PROTECTOR_H_INCLUDED

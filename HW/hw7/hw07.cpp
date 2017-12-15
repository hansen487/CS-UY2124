#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "noble.h"
#include "protector.h"

using namespace std;
using namespace WarriorCraft;

class Lord : public Noble{
public:
    Lord(const string& name) : Noble(name) {}
};

class PersonWithStrengthToFight : public Noble{
public:
    PersonWithStrengthToFight(const string& name, int strength) : Noble(name, strength) {}
};

class Wizard : public Protector{
public:
    Wizard(const string& name, int strength) : Protector(name, strength) {}
    virtual void battlecry() const{
        cout << "POOF!" << endl;
    }
};

class Warrior : public Protector{
public:
    Warrior(const string& name, int strength) : Protector(name, strength) {}
    virtual void battlecry() const{
        cout << Protector::get_name() << " says: Take that in the name of my lord, " << Protector::get_noble() -> get_name() << endl;
    }
};

class Archer : public Warrior{
public:
    Archer(const string& name, int strength) : Warrior(name, strength) {}
    void battlecry() const{
        cout << "TWANG! ";
        Warrior::battlecry();
    }
};

class Swordsman : public Warrior{
public:
    Swordsman(const string& name, int strength) : Warrior(name, strength) {}
    void battlecry() const{
        cout << "CLANG! ";
        Warrior::battlecry();
    }
};

int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}

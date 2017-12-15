//Hansen Chen, medieval warfare simulation with nobles
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//Warrior class
class Warrior{
public:
    Warrior() {}
    Warrior(const string& name, int strength) : warrior_name(name), warrior_strength(strength) {}

    void set_hired(bool status){
        hired = status;
    }

    bool get_hired_status(){
        return hired;
    }

    string get_name(){
        return warrior_name;
    }

    int get_strength(){
        return warrior_strength;
    }

    bool status(){
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

//Noble class
class Noble{
public:
    Noble(const string& name) : noble_name(name) {}

    void hire(Warrior& warrior){
        Warrior* warrior_p = &warrior;
        if (warrior_p -> get_hired_status() == false && warrior_p -> status() == false){
            army.push_back(warrior_p);
            warrior_p -> set_hired(true);
            noble_strength += warrior_p -> get_strength();
        }
        else{
            cout << "Warrior is already hired!" << endl;
        }
    }

    void fire(Warrior& warrior){
        Warrior* fired;
        if (warrior.get_hired_status() == true) {
            for(Warrior* warrior_p: army){
                if (warrior_p == &warrior){
                    fired = warrior_p;
                }
            }
            cout << warrior.get_name() << ", you're fired! -- " << noble_name << endl;
            noble_strength -= fired -> get_strength();
            Warrior* last = army.back();
            swap(fired, last);
            fired -> set_hired(false);
            army.pop_back();
        }
        else{
            cout << "Warrior is not hired!" << endl;
        }
    }

    void display(){
        cout << noble_name << " has an army of " << army.size() << endl;
        for (Warrior* warrior: army){
            cout << '\t' << warrior -> get_name() << ": " << warrior -> get_strength() << endl;
        }
    }

    void battle(Noble& noble){
        Noble* noble_p = &noble;
        cout << noble_name << " battles " << noble_p -> get_name() << endl;
        //if both nobles are dead
        if (noble_strength == noble_p -> noble_strength){
            if (noble_strength == 0){
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
            else{
                cout << "Mutual Annihilation: " << noble_name << " and " << noble_p -> get_name() << " die at each other's hands" << endl;
                noble_strength = 0;
                for (Warrior* warrior: army){
                    warrior -> set_strength(0);
                }
                noble_p -> noble_strength = 0;
                for (Warrior* warrior: noble_p -> army){
                    warrior -> set_strength(0);
                }
            }
        }
        else{
            //if only one noble is dead
            if (noble_p -> noble_strength == 0){
                cout << "He's dead " << noble_name << endl;
            }
            //else, simulate battle
            else if (noble_strength != 0 && noble_p -> noble_strength != 0){
                if (noble_strength > noble_p -> noble_strength){
                    cout << noble_name << " defeats " << noble_p -> noble_name << endl;
                    int old_strength = noble_p -> noble_strength;
                    //set the losing noble's strength and his warrior's strengths to 0
                    noble_p -> noble_strength = 0;
                    for (Warrior* warrior: noble_p -> army){
                        warrior -> set_strength(0);
                    }
                    //decrease winning noble's strength
                    int scalar = noble_strength / old_strength;
                    noble_strength /= scalar;
                    for (Warrior* warrior: noble_p -> army){
                        warrior -> set_strength(warrior -> get_strength() * scalar);
                    }
                }
            }
        }
    }

    string get_name(){
        return noble_name;
    }

    int get_strength(){
        return noble_strength;
    }



private:
    string noble_name;
    vector<Warrior*> army;
    int noble_strength = 0;
};


int main()
{
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}

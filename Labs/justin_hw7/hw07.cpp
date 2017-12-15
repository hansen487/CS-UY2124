#include "Nobles.h"
#include "protectors.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace WarriorCraft;

// class Noble{
// public:
//     Noble(const string& name) : name(name), alive(true) {}
//     string getName() const{
//         return name;
//     }
//     void kill(){
//         alive = false;
//     }
//     bool isAlive(){
//         return alive;
//     }
//     virtual double getStrength() const = 0;
//     virtual void setStrength(double newStrength) {}
//     virtual void defend() const = 0;
//     void battle(Noble& aNoble){
//         cout << getName() << " battles " << aNoble.getName() << endl;
//         if (isAlive() == true && aNoble.isAlive() == true){
//             double newStrength;
//             if(getStrength() > aNoble.getStrength()){
//                 defend();
//                 aNoble.defend();
//                 aNoble.kill();
//                 newStrength = getStrength() * (1-(aNoble.getStrength()/getStrength()));
//                 setStrength(newStrength);
//                 cout << getName() << " defeats " << aNoble.getName() << endl;
//             }
//             else if (aNoble.getStrength() > getStrength()){
//                 aNoble.defend();
//                 defend();
//                 kill();
//                 newStrength = aNoble.getStrength() * (1-(getStrength()/aNoble.getStrength()));
//                 setStrength(newStrength);
//                 cout << aNoble.getName() << " defeats " << getName() << endl;
//             }
//             else if (getStrength() == aNoble.getStrength()){
//                 kill();
//                 aNoble.kill();
//                 cout << "Mutual Annihilation: " << getName() << " and " << aNoble.getName() << " die at each other's hands." << endl;
//             }
//         }
//         else if (isAlive() == true && aNoble.isAlive() == false){
//             cout << "He's dead, " << getName() << endl;
//         }
//         else if (isAlive() == false && aNoble.isAlive() == true){
//             cout << "He's dead, " << aNoble.getName() << endl;
//         }
//         else if (isAlive() == false && aNoble.isAlive() == false){
//             cout << "Oh, NO! They're both dead! Yuck!" << endl;
//         }
//     }
// private:
//     string name;
//     bool alive;
// };
//
// class Protector{
// public:
//     Protector(const string& name, double strength) : name(name), strength(strength), alive(true), leader(nullptr) {}
//     string getName() const{
//         return name;
//     }
//     string getLeaderName() const{
//         return leader->getName();
//     }
//     double getStrength() const{
//         return strength;
//     }
//     virtual void defend() const = 0;
//     bool isHired(){
//         return hired;
//     }
//     void setLeader(Noble* aLeader){
//         leader = aLeader;
//     }
//     bool isAlive(){
//         return alive;
//     }
//     void kill(){
//         alive = false;
//     }
//     void setStrength(double newStrength){
//         strength = newStrength;
//     }
// private:
//     string name;
//     double strength;
//     Noble* leader;
//     bool hired;
//     bool alive;
// };
//
// class Wizard : public Protector{
// public:
//     Wizard(const string& name, double strength) : Protector(name, strength) {}
//     void defend() const{
//         cout << "POOF" << endl;
//     }
// };
//
// class Warrior : public Protector{
// public:
//     Warrior(const string& name, double strength) : Protector(name, strength) {}
// };
//
// class Archer : public Warrior{
// public:
//     Archer(const string& name, double strength) : Warrior(name, strength) {}
//     void defend() const{
//         cout << "TWANG! " << getName() << " says: Take that in the name of my lord, " << getLeaderName() << endl;
//     }
// };
//
// class Swordsman : public Warrior{
// public:
//     Swordsman(const string& name, double strength) : Warrior(name, strength) {}
//     void defend() const{
//         cout << "CLANG! " << getName() << " says: Take that in the name of my lord, " << getLeaderName() << endl;
//     }
// };
//
// class Lord : public Noble{
// public:
//     Lord(const string& name) : Noble(name) {}
//     void hires(Protector& aProtector){
//         if (aProtector.isHired() == false && aProtector.isAlive() == true){
//             aProtector.setLeader(this);
//             protectors.push_back(&aProtector);
//         }
//     }
//     void kill(){
//         for (int i = 0; i < protectors.size(); i++){
//             protectors[i]->kill();
//             Noble::kill();
//         }
//     }
//     void defend() const{
//         for (int i = 0; i < protectors.size(); i++){
//             protectors[i]->defend();
//         }
//     }
//     double getStrength() const{
//         int totalStrength = 0;
//         for (int i = 0; i < protectors.size(); i++){
//             totalStrength += protectors[i]->getStrength();
//         }
//         return totalStrength;
//     }
//     void setStrength(double newStrength){
//         for (int i = 0; i < protectors.size(); i++){
//             protectors[i]->setStrength(newStrength);
//         }
//     }
// private:
//     vector<Protector*> protectors;
// };
//
// class PersonWithStrengthToFight : public Noble{
// public:
//     PersonWithStrengthToFight(const string& name, double strength) : Noble(name), strength(strength) {}
//     double getStrength() const{
//         return strength;
//     }
//     void defend() const{}
//     void kill(){
//         Noble::kill();
//     }
//     void setStrength(double newStrength){
//         strength = newStrength;
//     }
// private:
//     double strength;
// };

int main(){
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

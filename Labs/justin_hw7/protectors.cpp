#include "Nobles.h"
#include "protectors.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace WarriorCraft{

  Protector::Protector(const string& name, double strength) : name(name), strength(strength), alive(true), leader(nullptr) {}
  string Protector::getName() const{
      return name;
  }
  string Protector::getLeaderName() const{
      return leader->getName();
  }
  double Protector::getStrength() const{
      return strength;
  }
  void Protector::defend() const {}
  bool Protector::isHired(){
      return hired;
  }
  void Protector::setLeader(Noble* aLeader){
      leader = aLeader;
  }
  bool Protector::isAlive(){
      return alive;
  }
  void Protector::kill(){
      alive = false;
  }
  void Protector::setStrength(double newStrength){
      strength = newStrength;
  }

  Warrior::Warrior(const string& name, double strength) : Protector(name, strength) {}
  void Warrior::defend() const{
      cout << getName() << "says: Take that in the name of my lord, " << getLeaderName() << endl;
  }

  Wizard::Wizard(const string& name, double strength) : Protector(name, strength) {}
  void Wizard::defend() const{
      cout << "POOF" << endl;
  }


  Archer::Archer(const string& name, double strength) : Warrior(name, strength) {}
  void Archer::defend() const{
      cout << "TWANG! ";
      Warrior::defend();
  }

  Swordsman::Swordsman(const string& name, double strength) : Warrior(name, strength) {}
  void Swordsman::defend() const{
      cout << "CLANG! " ;
      Warrior::defend();
  }
}

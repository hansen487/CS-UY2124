#include "Nobles.h"
#include "protectors.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace WarriorCraft {
  Noble::Noble(const string& name) : name(name), alive(true) {}
  string Noble::getName() const{
      return name;
  }
  void Noble::kill(){
      alive = false;
  }
  bool Noble::isAlive(){
      return alive;
  }
  double Noble::getStrength() const{}
  void Noble::setStrength(double newStrength) {}
  void Noble::defend() const {}
  void Noble::battle(Noble& aNoble){
      cout << getName() << " battles " << aNoble.getName() << endl;
      if (isAlive() == true && aNoble.isAlive() == true){
          double newStrength;
          if(getStrength() > aNoble.getStrength()){
              defend();
              aNoble.defend();
              aNoble.kill();
              newStrength = getStrength() * (1-(aNoble.getStrength()/getStrength()));
              setStrength(newStrength);
              cout << getName() << " defeats " << aNoble.getName() << endl;
          }
          else if (aNoble.getStrength() > getStrength()){
              aNoble.defend();
              defend();
              kill();
              newStrength = aNoble.getStrength() * (1-(getStrength()/aNoble.getStrength()));
              setStrength(newStrength);
              cout << aNoble.getName() << " defeats " << getName() << endl;
          }
          else if (getStrength() == aNoble.getStrength()){
              kill();
              aNoble.kill();
              cout << "Mutual Annihilation: " << getName() << " and " << aNoble.getName() << " die at each other's hands." << endl;
          }
      }
      else if (isAlive() == true && aNoble.isAlive() == false){
          cout << "He's dead, " << getName() << endl;
      }
      else if (isAlive() == false && aNoble.isAlive() == true){
          cout << "He's dead, " << aNoble.getName() << endl;
      }
      else if (isAlive() == false && aNoble.isAlive() == false){
          cout << "Oh, NO! They're both dead! Yuck!" << endl;
      }
  }

  Lord::Lord(const string& name) : Noble(name) {}
  void Lord::hires(Protector& aProtector){
      if (aProtector.isHired() == false && aProtector.isAlive() == true){
          aProtector.setLeader(this);
          protectors.push_back(&aProtector);
      }
  }
  void Lord::kill(){
      for (int i = 0; i < protectors.size(); i++){
          protectors[i]->kill();
          Noble::kill();
      }
  }
  void Lord::defend() const{
      for (int i = 0; i < protectors.size(); i++){
          protectors[i]->defend();
      }
  }
  double Lord::getStrength() const{
      int totalStrength = 0;
      for (int i = 0; i < protectors.size(); i++){
          totalStrength += protectors[i]->getStrength();
      }
      return totalStrength;
  }
  void Lord::setStrength(double newStrength) const{
      for (int i = 0; i < protectors.size(); i++){
          protectors[i]->setStrength(newStrength);
      }
  }

  PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, double strength) : Noble(name), strength(strength) {}
  double PersonWithStrengthToFight::getStrength() const{
      return strength;
  }
  void PersonWithStrengthToFight::defend() const{}
  void PersonWithStrengthToFight::kill(){
      Noble::kill();
  }
  void PersonWithStrengthToFight::setStrength(double newStrength){
      strength = newStrength;
  }
}

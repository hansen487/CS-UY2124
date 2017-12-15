#ifndef PROTECTORS_H
#define PROTECTORS_H

#include "Nobles.h"
#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft{
  class Noble;
  class Protector{
  public:
      Protector(const std::string& name, double strength);// : name(name), strength(strength), alive(true), leader(nullptr) {}
      std::string getName() const;
      std::string getLeaderName() const;
      double getStrength() const;
      virtual void defend() const = 0;
      bool isHired();
      void setLeader(Noble* aLeader);
      bool isAlive();
      void kill();
      void setStrength(double newStrength);
  private:
      std::string name;
      double strength;
      Noble* leader;
      bool hired;
      bool alive;
  };

  class Wizard : public Protector{
  public:
      Wizard(const std::string& name, double strength); // : Protector(name, strength) {}
      void defend() const;
  };

  class Warrior : public Protector{
  public:
      Warrior(const std::string& name, double strength); //: Protector(name, strength) {}
      void defend() const;
  };

  class Archer : public Warrior{
  public:
      Archer(const std::string& name, double strength); //: Warrior(name, strength) {}
      void defend() const;
  };

  class Swordsman : public Warrior{
  public:
      Swordsman(const std::string& name, double strength); //: Warrior(name, strength) {}
      void defend() const;
  };
}

#endif

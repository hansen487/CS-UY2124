#ifndef NOBLE_H
#define NOBLE_H

#include "protectors.h"
#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft{
  class Protector;
  class Noble{
  public:
      Noble(const std::string& name);
      std::string getName() const;
      void kill();
      bool isAlive();
      virtual double getStrength() const;
      virtual void setStrength(double newStrength);
      virtual void defend() const;
      void battle(Noble& aNoble);
  private:
      std::string name;
      bool alive;
  };

  class Lord: public Noble{
  public:
      Lord(const std::string& name);
      void hires(Protector& aProtector);
      void kill();
      void defend() const;
      double getStrength() const;
      void setStrength(double newStrength) const;
  private:
      std::vector<Protector*> protectors;
  };

  class PersonWithStrengthToFight : public Noble{
  public:
      PersonWithStrengthToFight(const std::string& name, double strength); // : Noble(name), strength(strength) {}
      double getStrength() const;
      void defend() const;
      void kill();
      void setStrength(double newStrength);
  private:
      double strength;
  };

}
#endif

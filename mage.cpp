#include "mage.h"

mage::mage(int n)
{
  health=180;
  damage=30;
  attackRange=15;
  speed=n/5;
  cost=30;
  name="mag";
}

int mage::attack()
{
  attackName="czar";
  return damage;
}

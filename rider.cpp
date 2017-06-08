#include "rider.h"

rider::rider(int n)
{
  health=320;
  damage=35;
  attackRange=2;
  speed=n/3;
  cost=40;
  name="jezdziec";
}

int rider::attack()
{
  attackName="szarza";
  return damage;
}

#include "archer.h"

archer::archer(int n)
{
  health=170;
  damage=15;
  attackRange=n;
  speed=n/5;
  cost=30;
  name="lowca";
}

int archer::attack()
{
  attackName="strzal";
  return damage;
}


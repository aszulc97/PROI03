#include "knight.h"

knight::knight(int n)
{
  health=200;
  damage=20;
  attackRange=1;
  speed=n/2;
  cost=20;
  name="rycerz";
}

int knight::attack()
{
  attackName="dzgniecie";
  return damage;
}

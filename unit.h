#ifndef UNIT_H_
#define UNIT_H_
#include <iostream>
class unit
{
  public:
    int health;
    int damage;
    int attackRange;
    int speed;
    int cost;

    void walk();
    void attack();
    void gettingDamaged();
};
#endif //UNIT_H_


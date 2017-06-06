#ifndef UNIT_H_
#define UNIT_H_
#include <iostream>
class unit
{
  public:
    void walk();
    void attack();
    void gettingDamaged();
    void showDetails();
    int getCost();

  protected:
    int health;
    int damage;
    int attackRange;
    int speed;
    int cost;

};
#endif //UNIT_H_


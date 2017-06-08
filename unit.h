#ifndef UNIT_H_
#define UNIT_H_
#include <iostream>
#include <string>
using namespace std;
class unit
{
  public:
    int walk();
    virtual int attack() =0;  //pure virtual method
    void gettingDamaged();
    void showDetails();
    int getHealth();
    int getDamage();
    int getCost();
    void battleTable(int y);
    string name;
    string attackName;

  protected:
    int health;
    int damage;
    int attackRange;
    int speed;
    int cost;

};
#endif //UNIT_H_


#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

class player
{
  public:
    player();
    int getMoney();
    int archers;
    int mages;
    int knights;
    int riders;
    int warriors;
    void showArmy();
    int shopping;
    int teamHealth(int unit, int unitHealth);


  private:
    int money;

};
#endif //PLAYER_H_

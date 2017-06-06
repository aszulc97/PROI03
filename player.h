#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

class player
{
  public:
    player();
    int getMoney();
    void showUnits();
    int archers;
    int mages;
    int knights;
    int riders;
    int warriors;
    int shopping;


  private:
    int money;

};
#endif //PLAYER_H_

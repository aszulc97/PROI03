#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

class player
{
  public:
    player();
    int getMoney();
    void showUnits();

  private:
    int money;
    int archers;
    int mages;
    int knights;
    int riders;
    int warriors;

};
#endif //PLAYER_H_

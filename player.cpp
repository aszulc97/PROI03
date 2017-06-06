#include <ncurses.h>
#include "player.h"

player::player()
{
  money = 300;
}

int player::getMoney()
{
  return money;
}

void player::showArmy()
{
  printw("\nTwoja armia:\n");
  printw("Lowcy: %d\n", archers);
  printw("Jezdzcy: %d\n", riders);
  printw("Magowie: %d\n", mages);
  printw("Rycerze: %d\n", knights);
  printw("Wojownicy: %d\n", warriors);
}

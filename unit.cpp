#include <ncurses.h>
#include "unit.h"
using namespace std;

int unit::walk()
{
  return speed;
}

/*int unit::attack()
{
  return damage;
}*/

void unit::showDetails()
{
  printw("%d\t%d\t%d\t%d\t %d\n", damage, health,cost,speed,attackRange);
}

int unit::getCost()
{
  return cost;
}

int unit::getHealth()
{
  return health;
}

/*void unit::battleTableRow(int y)
{
  mvprintw( 1,y, "\t\tAtak\tZdrowie\tPredkosc Zasieg");
  mvprintw( 2,y, "Lowca: %d", player2.archers);
  mvprintw( 3,y, "Jezdziec: %d", player2.riders);
  mvprintw( 4,y, "Mag: %d", player2.mages);
  mvprintw( 5,y, "Rycerz: %d", player2.knights);
  mvprintw( 6,y, "Wojownik: %d", player2.warriors);
}*/

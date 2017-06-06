#include <ncurses.h>
#include "unit.h"
using namespace std;

void unit::walk()
{

}

void unit::attack()
{

}

void unit::showDetails()
{
  printw("%d\t%d\t%d\t%d\t %d\n", damage, health,cost,speed,attackRange);
}

int unit::getCost()
{
  return cost;
}

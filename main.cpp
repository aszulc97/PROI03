#include <iostream>
#include <ncurses.h>
#include "player.h"
#include "archer.h"
#include "rider.h"
#include "knight.h"
#include "mage.h"
#include "warrior.h"

using namespace std;

int columns = 0;
int rows = 0;
int fieldSize=10;
//char text[] = "sample";

int main()
{
  player player1;
  player player2;
  archer archer1(10);
  rider rider1(10);
  mage mage1(10);
  knight knight1(10);
  warrior warrior1(10);


  initscr();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);

  getmaxyx( stdscr, rows, columns );

  attron(COLOR_PAIR(1));
  mvprintw( (rows/2)-2,( columns/2)-13, "Witajcie w grze!" );
  getch();
  clear();

  //text = "Graczu 1, masz monet"
  attron(COLOR_PAIR(3));
  mvprintw( 1, 0, "Graczu 1, masz %d monet", player1.getMoney() );
  mvprintw( 2, 0, "Jakie jednostki chcesz za to kupic?\n");

  printw("\t\tAtak\tZdrowie Koszt\tPredkosc Zasieg\n");
  printw("Lowca\t\t");
  archer1.showDetails();
  printw("Jezdziec\t");
  rider1.showDetails();
  printw("Mag\t\t");
  mage1.showDetails();
  printw("Rycerz\t\t");
  knight1.showDetails();
  printw("Wojownik\t");
  warrior1.showDetails();

  getch();
  endwin();
}

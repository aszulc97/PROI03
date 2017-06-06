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
  getch();

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

  printw("\nIlu lowcow kupujesz?: ");
  player1.archers=getch(); //here's a character
  player1.shopping=player1.getMoney()-(player1.archers-48)*archer1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu jezdzcow kupujesz?: ");
  player1.riders=getch(); //here's a character
  player1.shopping-=(player1.riders-48)*rider1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu magow kupujesz?: ");
  player1.mages=getch(); //here's a character
  player1.shopping-=(player1.mages-48)*mage1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu rycerzy kupujesz?: ");
  player1.knights=getch(); //here's a character
  player1.shopping-=(player1.knights-48)*knight1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu wojownikow kupujesz?: ");
  player1.warriors=getch(); //here's a character
  player1.shopping-=(player1.warriors-48)*warrior1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nTwoja armia:\n");
  printw("Lowcy: %d\n", player1.archers-48);
  printw("Jezdzcy: %d\n", player1.riders-48);
  printw("Magowie: %d\n", player1.mages-48);
  printw("Rycerze: %d\n", player1.knights-48);
  printw("Wojownicy: %d\n", player1.warriors-48);

  //PLAYER II

  clear();
  getch();
  mvprintw( 1, 0, "Graczu 2, masz %d monet", player2.getMoney() );
  mvprintw( 2, 0, "Jakie jednostki chcesz za to kupic?\n");
  getch();

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

  printw("\nIlu lowcow kupujesz?: ");
  player2.archers=getch(); //here's a character
  player2.shopping=player2.getMoney()-(player2.archers-48)*archer1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nIlu jezdzcow kupujesz?: ");
  player2.riders=getch(); //here's a character
  player2.shopping-=(player2.riders-48)*rider1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nIlu magow kupujesz?: ");
  player2.mages=getch(); //here's a character
  player2.shopping-=(player2.mages-48)*mage1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nIlu rycerzy kupujesz?: ");
  player2.knights=getch(); //here's a character
  player2.shopping-=(player2.knights-48)*knight1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nIlu wojownikow kupujesz?: ");
  player2.warriors=getch(); //here's a character
  player2.shopping-=(player2.warriors-48)*warrior1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nTwoja armia:\n");
  printw("Lowcy: %d\n", player2.archers-48);
  printw("Jezdzcy: %d\n", player2.riders-48);
  printw("Magowie: %d\n", player2.mages-48);
  printw("Rycerze: %d\n", player2.knights-48);
  printw("Wojownicy: %d\n", player2.warriors-48);
  getch();
  endwin();
}

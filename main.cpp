#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>

#include "player.h"
#include "archer.h"
#include "rider.h"
#include "knight.h"
#include "mage.h"
#include "warrior.h"

using namespace std;

int main()
{
  int columns = 0;
  int rows = 0;

  int fieldSize;
  char str_fieldSize[80];

  player player1;
  player player2;

  initscr();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);

  getmaxyx( stdscr, rows, columns );

  attron(COLOR_PAIR(1));
  mvprintw( (rows/2)-2,( columns/2)-13, "Witajcie w grze!" );
  mvprintw( (rows/2),( columns/2)-17, "Rozmiar pola walki: " );

  fstream file;  //getting size of battlefield
  file.open( "plik.txt", std::ios::in);
  if (!file.is_open())
  {
    printw("Plik uszkodzony!\n");  //no file error
    getch();
    return 1;
  }

  file>>str_fieldSize;
  fieldSize = atoi(str_fieldSize);
  printw("%d", fieldSize);
  getch();
  clear();


  archer archer1(fieldSize);
  rider rider1(fieldSize);
  mage mage1(fieldSize);
  knight knight1(fieldSize);
  warrior warrior1(fieldSize);

  //BUYING UNITS - PLAYER I

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
  player1.archers=getch()-48; //here's a character
  player1.shopping=player1.getMoney()-(player1.archers)*archer1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu jezdzcow kupujesz?: ");
  player1.riders=getch()-48; //here's a character
  player1.shopping-=(player1.riders)*rider1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu magow kupujesz?: ");
  player1.mages=getch()-48; //here's a character
  player1.shopping-=(player1.mages)*mage1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu rycerzy kupujesz?: ");
  player1.knights=getch()-48; //here's a character
  player1.shopping-=(player1.knights)*knight1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  printw("\nIlu wojownikow kupujesz?: ");
  player1.warriors=getch()-48; //here's a character
  player1.shopping-=(player1.warriors)*warrior1.getCost();
  printw("\nZostalo Ci %d monet",player1.shopping);

  player1.showArmy();
  getch();

  //PLAYER II

  clear();
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

  while(true)
  {
  printw("\nIlu lowcow kupujesz?(max. 9): ");
  player2.archers=getch()-48;
  player2.shopping=player2.getMoney()-(player2.archers)*archer1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  printw("\nIlu jezdzcow kupujesz?(max. 9): ");
  player2.riders=getch()-48;
  player2.shopping-=(player2.riders)*rider1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  if (player2.shopping<1)
  {
    printw("\nKoniec zakupow!");
    getch();
    break;
  }

  printw("\nIlu magow kupujesz?(max. 9): ");
  player2.mages=getch()-48;
  player2.shopping-=(player2.mages)*mage1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  if (player2.shopping<1)
  {
    printw("\nKoniec zakupow!");
    getch();
    break;
  }

  printw("\nIlu rycerzy kupujesz?(max. 9): ");
  player2.knights=getch()-48;
  player2.shopping-=(player2.knights)*knight1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);

  if (player2.shopping<1)
  {
    printw("\nKoniec zakupow!");
    getch();
    break;
  }

  printw("\nIlu wojownikow kupujesz?(max. 9): ");
  player2.warriors=getch()-48;
  player2.shopping-=(player2.warriors)*warrior1.getCost();
  printw("\nZostalo Ci %d monet",player2.shopping);
  break;
  }
  player2.showArmy();
  getch();
  clear();

  //UNITS SUMMARY

  attron(COLOR_PAIR(1));
  mvprintw( 1,1, " Gracz 1:" );
  attron(COLOR_PAIR(2));
  mvprintw( 2,1, " Lowcy: %d\n  Jezdzcy: %d\n  Magowie: %d\n  Rycerze: %d\n  Wojownicy: %d\n",
    player1.archers, player1.riders, player1.mages, player1.knights, player1.warriors );

  attron(COLOR_PAIR(1));
  mvprintw( 1,30, " Gracz 2:" );
  attron(COLOR_PAIR(2));
  mvprintw( 2,30, "Lowcy: %d", player2.archers);
  mvprintw( 3,30, "Jezdzcy: %d", player2.riders);
  mvprintw( 4,30, "Magowie: %d", player2.mages);
  mvprintw( 5,30, "Rycerze: %d", player2.knights);
  mvprintw( 6,30, "Wojownicy: %d", player2.warriors);

  attron(COLOR_PAIR(1));
  mvprintw( (rows/2)-2, 13, "Zaczynamy gre!" );
  getch();
/*
  vector <int> player1Army;
  vector <int> player2Army;
  for(int i = 0; i < fieldSize; i++ ) player1Army.at(i)=0;
  for(int i = 0; i < fieldSize; i++ ) player2Army.at(i)=0;

  player1.archersPosition=player1.knightsPosition=player1.ridersPosition=player1.magesPosition=player1.warriorsPosition=0;
  player1Army.at(0)=5;

  player2.archersPosition=player2.knightsPosition=player2.ridersPosition=player2.magesPosition=player2.warriorsPosition=fieldSize;
  player2Army.at(fieldSize)=5;*/

  char choice;
  char action;

  attron(COLOR_PAIR(3));
  do
  {
    clear();

    //GAME

    printw("\nGraczu 1, ktora jednostke wybierasz?");
    printw("\n1.Lowca");
    printw("\n2.Jezdziec");
    printw("\n3.Mag");
    printw("\n4.Rycerz");
    printw("\n5.Wojownik");
    printw("\n6.Szczegoly nt. jednostek");
    printw("\nWcisnij q aby zakonczyc");
    printw("\nTwoj wybor: ");
    choice=getch();

    if (choice=='q') continue;
    else if (choice!='6')
    {
      printw("\n\nWybrales: ");
      switch(choice)
      {
        case '1': {printw(archer1.name.c_str());}break;
        case '2': {printw(rider1.name.c_str());}break;
        case '3': {printw(mage1.name.c_str());}break;
        case '4': {printw(knight1.name.c_str());}break;
        case '5': {printw(warrior1.name.c_str());}break;
      }
      printw("\nCo chcesz zrobic?");
      printw("\na.Atakowac");
      printw("\nb.Podejsc blizej");
      action=getch();
      if (action=='a')
      {
        //if
      }
      else if (action=='b')
      {

      }
      //else

    }
    else if (choice=='6')
    {
      printw("\n\t\tAtak\tZdrowie Koszt\tPredkosc Zasieg\n");
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
//      continue;
    }

  } while (choice!='q');
  getch();

  endwin();
}

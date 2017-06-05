#include <iostream>
#include <ncurses.h>
#include "player.h"

using namespace std;

int columns = 0;
int rows = 0;
//char text[] = "sample";

int main()
{
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
  getch();
  clear();

  //text = "Graczu 1, masz monet"
  attron(COLOR_PAIR(3));
  mvprintw( 1, 1, "Graczu 1, masz %d monet", player1.getMoney() );
  getch();

  endwin();
}

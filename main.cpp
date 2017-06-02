
#include <iostream>
#include <ncurses.h>

int columns = 0;
int rows = 0;

int main()
{
    initscr();

    start_color();          /* Włącza kolor             */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    getmaxyx( stdscr, rows, columns );

    attron(COLOR_PAIR(1));
    mvprintw( (rows / 2)-2,( columns / 2 ) - 13, "Witajcie w grze!" );
    getch();
    clear();

    attron(COLOR_PAIR(2));
    mvprintw( (rows / 2)-2,( columns / 2 ) - 13, "LOL!" );
    getch();

    endwin();
}

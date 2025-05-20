#include <conio.h>

void clreol(void)
{
    int x, y;

    con_get_cursor_pos(&x, &y);
    clrscr();
    gotoxy(x, y);
}

int wherex(void)
{
    int x, y;

    con_get_cursor_pos(&x, &y);

    return x;
}

int wherey(void)
{
    int x, y;

    con_get_cursor_pos(&x, &y);

    return y;
}

void insline(void)
{
    con_write_asciiz("\n");
}

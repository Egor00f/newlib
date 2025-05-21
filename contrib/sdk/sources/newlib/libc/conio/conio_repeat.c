#include <conio.h>

#undef kbhit
#undef gotoxy
#undef clrscr
#undef getch

/*
Это просто повтеорение некоторых define'ов для тех, кто считатет, что include для слабаков.
Всё же лучше conio.h подключить если используешь эти функции т.к. я сомневаюсь линкер
оптимизирует это.
*/

int kbhit()
{
    return con_kbhit();
}

int gotoxy(int x, int y)
{
    con_set_cursor_pos(x, y);
}

void clrscr()
{
    con_cls();
}

#include <conio.h>
#include <sys/ksys.h>


void clreol()
{
    int x, y;

    con_get_cursor_pos(&x, &y);
    clrscr();
    gotoxy(x, y);
}

int wherex()
{
    int x, y;

    con_get_cursor_pos(&x, &y);

    return x;
}

int wherey()
{
    int x, y;

    con_get_cursor_pos(&x, &y);

    return y;
}

void insline()
{
    fputc('\n', stdout);
}

int getch()
{   // потом какнибудь сделаю реализацию для работы ungetch
    return con_getch();
}

int ungetch(int ch)
{
    /*
        Невозможно на данный момент
    */
}


static uint8_t colors = (BLACK << 4) | WHITE;

void textbackground(enum COLORS _color)
{
    /*
        смотрим enum COLORS и доку к консоли. Коды 40 - 47 коды простых цветов
    */
    if (_color >= 7)
    {
        printf("\033[4%dm", _color);
    }
    else
    {
        _color -= 10;
        printf("\033[4%d;5m", _color);  // яркий фон... да-да..
    }

    colors = (_color << 4) | (colors & 0b1111);
}

void textcolor(enum COLORS _color)
{
    /*
        смотрим enum COLORS и доку к консоли. Коды 30 - 37 коды простых цветов
    */
    if (_color >= 7)
    {
        printf("\033[3%dm", _color);
    }
    else
    {
        _color -= 10;
        printf("\033[3%d;1m", _color);
    }

    colors |= (colors << 4) | (_color & 0b1111);
}

void textattr(int _attr)
{
    textcolor(_attr & 0b00001111);
    textbackground(_attr & 0b01110000);
}

void highvideo()
{
    puts("\033[1m", stdout);
}

void lowvideo()
{
    puts("\033[0m", stdout);
    textattr(colors);
}

char* getpass(const char* str)
{
    printf("%s: ", str);

    static char psswd[9];

    for (uint8_t i = 0; i <= 8; i++)
    {
        char a = getch();
        if (a != '\n')
        {
            psswd[i] = a;
        }
        else
        {
            psswd[i] = 0;
            break;
        }
    }

    return psswd;
}

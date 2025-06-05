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
	putc('\n', stdout);
	fflush(stdout);
}

int getch()
{   // потом какнибудь сделаю реализацию для работы ungetch
	return getc(stdin);
}

int getche()
{
	int ch = getch();
	putc(ch, stdout);

	return ch;
}

int ungetch(int ch)
{
	return ungetc(ch, stdin);
}


int __conio_attributes = (BLACK << 4) | WHITE;

void textbackground(enum COLORS _color)
{
	/*
		смотрим enum COLORS и доку к консоли. Коды 40 - 47 коды простых цветов
	*/
	if (_color <= 7)
	{
		printf("\033[4%dm", _color);
	}
	else
	{
		printf("\033[4%d;5m", _color - 10);  // яркий фон... да-да..
	}

	__conio_attributes = (_color << 4) | (__conio_attributes & 0b1111);
}

void textcolor(enum COLORS _color)
{
	/*
		смотрим enum COLORS и доку к консоли. Коды 30 - 37 коды простых цветов
	*/
	if (_color <= 7)
	{
		printf("\033[3%dm", _color);
	}
	else
	{
		printf("\033[3%d;1m", _color - 10);
	}

	__conio_attributes |= (__conio_attributes << 4) | (_color & 0b1111);
}

void textattr(int _attr)
{
	textcolor(_attr & 0b00001111);
	textbackground(_attr >> 4);
}

void gettextinfo(struct text_info* _r)
{
	con_get_cursor_pos(&_r->curx, &_r->cury);
	_r->screenwidth = 80;
	_r->attribute = __conio_attributes;
	_r->normattr = (BLACK << 4) | WHITE;
}

void highvideo()
{
	puts("\033[1m");
}

void lowvideo()
{
	puts("\033[0m");

	uint8_t back = (__conio_attributes << 4);
	uint8_t text = (__conio_attributes & 0b1111);

	if (back > 7)   // нафиг интенсивные цвета
		back -= 10; // см enum COLORS, там интенсивные цвета начинаются с 10
	if (text > 7)
		text -= 10;

	textattr(text | (back << 4));
}

void normvideo(void)
{
	puts("\033[0m");
}

char* getpass(const char* str)
{
	printf("%s: ", str);
	fflush(stdout);

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

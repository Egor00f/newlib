#ifndef _CONIO_H_
#define _CONIO_H_

#include <stdio.h>

#define CON_WINDOW_CLOSED 0x200
#define CON_COLOR_BLUE 0x01
#define CON_COLOR_GREEN 0x02
#define CON_COLOR_RED 0x04
#define CON_COLOR_BRIGHT 0x08
/* background color */

#define CON_BGR_BLUE 0x10
#define CON_BGR_GREEN 0x20
#define CON_BGR_RED 0x40
#define CON_BGR_BRIGHT 0x80
/* output controls */

#define CON_IGNORE_SPECIALS 0x100

#define __con_api __stdcall

_BEGIN_STD_C
typedef int (*con_gets2_callback)(int keycode, char** pstr, int* pn, int* ppos);

struct text_info {
	unsigned char winleft;
	unsigned char wintop;
	unsigned char winright;
	unsigned char winbottom;
	unsigned char attribute;
	unsigned char normattr;
	unsigned char currmode;
	unsigned char screenheight;
	unsigned char screenwidth;
	unsigned char curx;
	unsigned char cury;
};

enum COLORS {
	/*  dark colors     */
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BROWN = RED,    // Как бы коричневый близок к оранжевому, а оранжевый близок к красному
	/*  light colors    */
	DARKGRAY = 10, /* "light black" */
	LIGHTRED,
	LIGHTGREEN,
	LIGHTYELLOW,
	LIGHTBLUE,
	LIGHTMAGENTA,
	LIGHTCYAN,

};

enum MODES {
	BW40,
	C40,
	BW80,
	C80,
	MONO,
	C4350 = 64,
	LASTMODE = -1
};

extern int __stdcall  con_init(uint32_t wnd_width, uint32_t wnd_height, uint32_t scr_width, uint32_t scr_height, const char* title);
extern void __stdcall   con_exit(int bCloseWindow);
extern void __stdcall   con_set_title(const char* title);
extern void __stdcall  con_write_asciiz(const char* str);
extern void __stdcall  con_write_string(const char* str, uint32_t length);
extern uint32_t __stdcall con_get_flags(void);
extern uint32_t __stdcall con_set_flags(uint32_t new_flags);
extern int __stdcall   con_get_font_height(void);
extern int __stdcall   con_get_cursor_height(void);
extern int __stdcall   con_set_cursor_height(int new_height);
extern int __stdcall   con_getch(void);
extern uint16_t __stdcall  con_getch2(void);
extern int __stdcall   con_kbhit(void);
extern char* __stdcall con_gets(char* str, int n);
extern char* __stdcall con_gets2(con_gets2_callback callback, char* str, int n);
extern void __stdcall  con_cls(void);
extern void __stdcall  con_get_cursor_pos(int* px, int* py);
extern void __stdcall  con_set_cursor_pos(int x, int y);

#define kbhit con_kbhit
#define gotoxy con_set_cursor_pos
#define clrscr con_cls

#define _cprintf printf
#define _cputch(ch) putc(ch, stdout)
#define _cputs puts
#define _cscanf scanf
#define _cgets gets

void blinkvideo(void);
char* cgets(char* _str);
void clreol(void);
void insline(void);
void delline(void);
int gettext(int _left, int _top, int _right, int _bottom, void* _destin);
void gettextinfo(struct text_info* _r);
void highvideo(void);
void lowvideo(void);
void normvideo(void);
int movetext(int _left, int _top, int _right, int _bottom, int _destleft, int _desttop);
int puttext(int _left, int _top, int _right, int _bottom, void* _source);
void setcursortype(int _type);
void set_screen_lines(int _nlines);
void textattr(int _attr);
void textbackground(enum COLORS _color);
void textcolor(enum COLORS _color);
void textmode(enum MODES _mode);
int getch();
int getche(void);
int ungetch(int);
int wherex(void);
int wherey(void);
char* getpass(const char* str);
void window(int _left, int _top, int _right, int _bottom);

_END_STD_C

#endif

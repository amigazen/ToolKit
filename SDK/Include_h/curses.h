/*
 *
 *    Author  : Simon J Raybould.
 *
 *    Date    : 16th Feb 1990
 *
 *    Desc    : Header file for my AMIGA CURSES package.
 *              This should be included instead of stdio.h, this will
 *              include stdio.h for you.
 *
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * $Log: curses.h,v $
 * Revision 1.13  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.12  1992/12/25  22:18:08  sie
 * GNU port
 *
 * Revision 1.11  92/06/20  10:58:39  sie
 * Removed CreatWindow prototype.
 * 
 * Revision 1.10  92/06/20  10:55:57  sie
 * removed prototype for _setcursestype()
 * 
 * Revision 1.9  92/06/10  23:44:32  sie
 * Added serial support.
 * 
 * Revision 1.8  92/01/25  23:52:19  sie
 * defines for some more unsupported keys.
 * 
 * Revision 1.7  91/12/30  10:31:27  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 * 
 * Revision 1.6  91/12/28  22:43:40  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.5  91/12/28  14:03:02  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.4  91/12/27  10:01:32  sie
 * Added some more key defines.
 * 
 * Revision 1.3  91/09/07  11:54:52  sie
 * V2.00 curses library.
 * 
 * Revision 1.2  91/08/23  21:38:21  sie
 * Port to GNU C.
 * 
 * Revision 1.1  91/02/05  21:19:07  sie
 * Initial revision
 * 
 *
 */

#ifndef CURSES_H
#define CURSES_H

#ifndef stdin			/* May be a better way to do this !! */
#include <stdio.h>
#endif

#include <exec/types.h>		/* for prototypes & TRUE&FALSE */

#define ERR      -1
#define OK        0


/*
 *    Macros
 */

#define addch(c)                   waddch(stdscr, (c))
#define addstr(str)                waddstr(stdscr, (str))
#define attrset(attr)              wattrset(stdscr, (attr))
#define attron(attr)               wattron(stdscr, (attr))
#define attroff(attr)              wattroff(stdscr, (attr))
#define clear()                    wclear(stdscr)
#define clrtoeol()                 wclrtoeol(stdscr)
#define clrtobot()                 wclrtobot(stdscr)
#define crmode()                   cbreak()
#define delch()                    wdelch(stdscr)
#define deleteln()                 wdeleteln(stdscr)
#define erase()                    werase(stdscr)
#define inch()                     winch(stdscr)
#define insch(c)                   winsch(stdscr, (c))
#define insertln()                 winsertln(stdscr)
#define getch()                    wgetch(stdscr)
#define getstr(ptr)                wgetstr(stdscr, (ptr))
#define getyx(win,y,x)             ((y) = (win)->_cury, (x) = (win)->_curx)
#define move(line, col)            wmove(stdscr, (line), (col))
#define mvdelch(y, x)              (move((y), (x)), delch())
#define mvwdelch(win, y, x)        (wmove((win),(y),(x)),wdelch((win)))
#define mvgetch(y, x)              (move((y), (x)), getch())
#define mvwgetch(win, y, x)        (wmove((win),(y),(x)),wgetch((win)))
#define mvgetstr(y, x, ptr)        (move((y), (x)), getstr((ptr)))
#define mvwgetstr(win, y, x, ptr)  (wmove((win), (y), (x)), \
                                     wgetstr((win), (ptr)))
#define mvinsch(y, x, c)           (move((y), (x)), insch((c)))
#define mvwinsch(win, y, x, c)     (wmove((win), (y), (x)), \
                                     winsch((win), (c)))
#define mvinch(y, x)               (move((y), (x)), inch())
#define mvwinch(win, y, x)         (wmove((win), (y), (x)),winch((win)))
#define mvaddch(y, x, c)           (move((y), (x)), addch((c)))
#define mvwaddch(win, y, x, c)     (wmove((win), (y), (x)), \
                                     waddch((win), (c)))
#define mvaddstr(y, x, str)        (move((y), (x)), addstr((str)))
#define mvwaddstr(win, y, x, str)  (wmove((win), (y), (x)), \
                                     waddstr((win), (str)))

#define nocrmode()                 nocbreak()
#define noraw()                    nocbreak()
#define raw()                      cbreak()
#define refresh()                  wrefresh(stdscr)
#define noutrefresh()              wnoutrefresh(stdscr)
#define setscrreg(top, bottom)     wsetscrreg(stdscr, (top), (bottom))
#define standend()                 wstandend(stdscr)
#define standout()                 wstandout(stdscr)

/*
 *    NON STANDARD MACROS
 */

#define pencolour(n)    wpencolour(stdscr, (n))

/*
 *    Colours
 */

#define COLOR_BLACK     0
#define COLOR_WHITE     1
#define COLOR_YELLOW    2
#define COLOR_BLUE      3
#define COLOR_MAGENTA   4
#define COLOR_CYAN      5
#define COLOR_RED       6
#define COLOR_GREEN     7


/*
 *    Video Attributes.
 */

#define A_NORMAL      0000
#define A_STANDOUT    0010
#define A_UNDERLINE   0020
#define A_BOLD        0040

#define A_REVERSE     A_STANDOUT
#define A_BLINK       A_NORMAL	/* NOT SUPPORTED */
#define A_DIM         A_NORMAL	/* NOT SUPPORTED */
#define _STANDOUT     A_STANDOUT /* for compatibility with old curses */

#define A_CLRPART     0007
#define A_ATRPART     0770

#define bool    char
#define reg     register

struct _win_st {
  UBYTE _cury, _curx;
  UBYTE _maxy, _maxx;
  UBYTE _begy, _begx;
  UBYTE _flags;
  UBYTE _attrs;
  bool _clear;			/* T=clear on next refresh */
  bool _scroll;
  bool _nodelay;		/* T=don't wait for tty input */
  struct _win_st *ParentWin;
  UBYTE ScrollTop;
  UBYTE ScrollBot;
  struct lnel {
    bool Touched;		/* This line needs refreshing */
    char *Line;			/* Actual text */
    UBYTE *ATTRS;		/* Attributes */
    UBYTE StartCol;
    UBYTE EndCol;
  } *LnArry;
  UBYTE NLines;
};

typedef struct _win_st  WINDOW;
extern WINDOW *stdscr, *curscr;
extern int LINES, COLS, DEPTH;


/*
 * Special keys.
 */

#define KEY_BACKSPACE   0010	/* backspace */
#define KEY_DC          0177	/* Delete character */
#define KEY_DOWN        0400	/* The down arrow key */
#define KEY_UP          0401	/* The up arrow key */
#define KEY_LEFT        0402	/* The left arrow key */
#define KEY_RIGHT       0403	/* The right arrow key */
#define KEY_HELP        0404	/* Help Key */
#define KEY_F0          0405	/* Function keys */
#define KEY_F(n)        (KEY_F0+(n))

/*
 * Keys not on Amiga keyboard
 */
#define KEY_IL		0501    /* Not supported */
#define KEY_DL		0502    /* Not supported */
#define KEY_CLEAR	0503    /* Not supported */
#define KEY_IC		0504    /* Not supported */
#define KEY_EIC		0505    /* Not supported */
#define KEY_HOME	0506    /* Not supported */
#define KEY_B2		0507    /* Not supported */
#define KEY_NPAGE	0510    /* Not supported */
#define KEY_PPAGE	0511    /* Not supported */
#define KEY_UNDO	0512    /* Not supported */

/*
 * Prototypes.
 */

int initscr(void);
int endwin(void);
int init_color(WORD n, UWORD r, UWORD g, UWORD b);
int start_color(void);
int has_colors(void);
int waddstr(WINDOW *WinPtr, char *Str);
int waddch(WINDOW *WinPtr, char c);
int winsch(WINDOW *WinPtr, char c);
int wdelch(WINDOW *WinPtr);
int wclear(WINDOW *WinPtr);
int werase(WINDOW *WinPtr);
int clearok(WINDOW *WinPtr, int flag);
int wclrtoeol(WINDOW *WinPtr);
int wclrtobot(WINDOW *WinPtr);
int flushinp(void);
int wgetch(WINDOW *WinPtr);
int wgetstr(WINDOW *WinPtr, char *ptr);
int winch(WINDOW *WinPtr);
int wmove(WINDOW *WinPtr, int Line, int Col);
int mvcur(int CurLine, int CurCol, int NewLine, int NewCol);
int printw(char *fmt, ...);
int wprintw(WINDOW *WinPtr, char *fmt, ...);
int mvprintw(int Line, int Col, char *fmt, ...);
int mvwprintw(WINDOW *WinPtr, int Line, int Col, char *fmt, ...);
int wrefresh(WINDOW *WinPtr);
#ifndef NO_SCAN_PROTOS
int scanw(char *fmt, ...);
int wscanw(WINDOW *WinPtr, char *fmt, ...);
int mvscanw(int Line, int Col, char *fmt, ...);
int mvwscanw(WINDOW *WinPtr, int Line, int Col, char *fmt, ...);
#endif /* ndef NO_SCAN_PROTOS */
int wstandout(WINDOW *WinPtr);
int wstandend(WINDOW *WinPtr);
int wattrset(WINDOW *WinPtr, UBYTE attr);
int wattron(WINDOW *WinPtr, UBYTE attr);
int wattroff(WINDOW *WinPtr, UBYTE attr);
int cbreak(void);
int nocbreak(void);
int idlok(WINDOW *WinPtr, int flag);
int winsertln(WINDOW *WinPtr);
int wdeleteln(WINDOW *WinPtr);
int nodelay(WINDOW *WinPtr, int flag);
int echo(void);
int noecho(void);
int keypad(WINDOW *WinPtr, char flag);
int beep(void);
int flash(void);
int leaveok(WINDOW *WinPtr, int flag);
int resetty(void);
int savetty(void);
int resetterm(void);
int fixterm(void);
int saveterm(void);
int baudrate(void);
int nl(void);
int nonl(void);
int box(WINDOW *WinPtr, char vert, char hor);
WINDOW *subwin(WINDOW *Orig,
	       unsigned int NLines,
	       unsigned int NCols,
               unsigned int StartLine,
               unsigned int StartCol);
WINDOW *newwin(unsigned int NLines,
               unsigned int NCols,
               unsigned int StartLine,
               unsigned int StartCol);
int touchwin(WINDOW *WinPtr);
int delwin(WINDOW *WinPtr);
int mvwin(WINDOW *WinPtr, int NewLine, int NewCol);
int scroll(WINDOW *WinPtr);
int wsetscrreg(WINDOW *WinPtr, int top, int bottom);
int scrollok(WINDOW *WinPtr, int flag);
int wnoutrefresh(WINDOW *WinPtr);
int doupdate(void);
int tgetent(char * , char * );
char * tgetstr(char * , char ** );
int tputs(char * , int , int (* )(char ));
char * tgoto(char * , int , int );
int tgetnum(char * );
int tgetflag(char * );

#endif /* CURSES_H */

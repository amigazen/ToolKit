// $Id: window.h 1.5 1998/04/08 15:13:40 dlorre Exp dlorre $
#if !defined( CLASS_WINDOW_H )
#define CLASS_WINDOW_H 1


#if !defined( EXEC_TYPES_H )
#include <exec/types.h>
#endif

#if !defined( GRAPHICS_TYPES_H )
#include <graphics/gfxbase.h>
#endif

#if !defined( GRAPHICS_GFXMACROS_H )
#include <graphics/gfxmacros.h>
#endif

#if !defined( INTUITION_GADGETCLASS_H )
#include <intuition/gadgetclass.h>
#endif

#if !defined( LIBRARIES_GADTOOLS_H )
#include <libraries/gadtools.h>
#endif

#ifndef CLASS_SLIST_H
#include "slist.h"
#endif

#include "rectangle.h"
#include "screen.h"
#include "locale.h"

#ifndef CLASS_GADGETLIST_H
#include "gadgetlist.h"
#endif

#ifndef CLASS_GADGET_H
class window ;
#include "gadgets/gadget.h"
#endif

#ifndef CLASS_STRING_H
#include "gadgets/string.h"
#endif

#ifdef open
#undef open
#endif

#ifdef close
#undef close
#endif

class menustate {
public:
    MenuItem    *item ;
    BOOL        enable ;
    BOOL        checked ;
    menustate() : item(NULL), enable(TRUE), checked(FALSE) {}
} ;

class window ;

class wlink : public nlink
{
public:
    window *win ;
} ;

// ========================================================================
// ========================== WINDOW CLASS ================================
// ========================================================================



class window : public rectangle {
friend class gadgetlist ;
private:
    TagItem     *tags ;
    Region      *clipregion ;
    Rectangle   *cliprect ;

    short       awidth ;
    short       aheight ;
    int         asize ;
    WORD        *areaBuffer ;
    UBYTE       *tmpBuffer;     // PLANEPTR
    BitMap      *tmpBitMap ;
    AreaInfo    *areaInfo ;
    TmpRas      *tmpRas ;
    short       drawmode ;
    RastPort    *bgrp ;
    BitMap      *bgbm ;
    wlink       link ;
protected:
    gadgetlist  *g ;            // the gadgets attached to this window
    void        (*reqfunc)(long, unsigned long, unsigned short) ;

    ULONG       idcmp ;         // the IDCMP flags
    BOOL        hasgadgets ;    // window contains gadgets
    BOOL        hasmenus ;      // window contains menus
    BOOL        selfmsg ;       // the MsgPort is not shared
public:
    screen      *ws ;
    Window      *win ;          // useful pointers
    MsgPort     *mp ;
    Menu        *menu ;
    RastPort    *rp ;

    BOOL        active ;        // user did not request for closing
    BOOL        initok ;        // open window succeeds
    ULONG       signal ;        // the MsgPort signal bit

    char        sname[256] ;    // storage (name in dialog box)
    BOOL        okflag ;        // user accept dialog box
    BOOL        applique ;      // do the changes now
    LONG        emode ;         // extended mode set to 1 if special action
public:
    window(short l, short t, short w, short h) ;
    virtual ~window() ;
protected:
    // Standard Gadget Routines
    virtual void fok(gadget *g, unsigned long classe, unsigned short code) ;
    virtual void fcancel(gadget *g, unsigned long classe, unsigned short code) ;
    virtual void fapply(gadget *g, unsigned long classe, unsigned short code) ;
    virtual void fname(gadget *g, unsigned long classe, unsigned short code) ;
    virtual void handlevkey(USHORT code) ;
    virtual void handlerawkey(USHORT code) ;
    virtual void handlemousebuttons(USHORT code, WORD x, WORD y, UWORD qualifier) ;
public:
    virtual void open(screen *) ;
    virtual void close() ;
    virtual void simpleevent(IntuiMessage *msg) ;
    virtual void otext( long x, long y, const char *string ) ;
protected:
    void _open(MsgPort *, ULONG, ULONG, ...) ;
    void _open(MsgPort *, ULONG, TagItem *) ;

    void strip() ;
    void stripimsg() ;
    void resetidcmp() ;

public:
    void prepbox(BOOL center=FALSE) ;    // Initialization routine
    void eventloop() ;
    void processevents(IntuiMessage *msg) ;
    void setfunc(void (*func)(long , unsigned long, unsigned short)) ;

    // Window management functions
    void move(short dx, short dy=0) ;
    void size(short dw, short dh=0) ;
    void box(short x, short y, short w, short h) ;
    void limits(short wmin, short hmin, short wmax, short hmax) ;
    void titles(const char *wt, const char *st) ;
    void activate() ;
    void front() ;
    void back() ;

    // Gadtools & Menus routines
    void recessedbox(short x, short y, short w, short h) ;
    void bevelbox(short x, short y, short w, short h) ;
    void setmenus(struct NewMenu *menu1, ...) ;
    void expandmenu(Menu *, NewMenu *extmenu) ;
    void menuchanges(menustate *, LONG count) ;
    MenuItem *itemaddress( unsigned long menuNumber ) ;
    MenuItem *itemaddress(LONG m, LONG i, LONG s) ;
    void clearmenustrip(void) ;
    BOOL resetmenustrip(void) ;

    // Gfx routines
    void pmove(long x, long y) ;                    // Move(rp, ...)
    void draw(long x, long y) ;                     // Draw(rp, ...)
    void polydraw(long count, WORD *polyTable) ;
    void rectfill(long xMin, long yMin, long xMax, long yMax) ;
    void eraserect(long xMin, long yMin, long xMax, long yMax ) ;
    void setapen(unsigned long pen) ;
    void setbpen(unsigned long pen) ;
    void setopen(unsigned long pen) ;
    void setrast(unsigned long pen) ;
    void setdrmd(unsigned long drawMode) ;
    void setdrpt(UWORD pattern) ;
    void setafpt(const UWORD *pattern, BYTE count) ;
    short textlength(const char *string, unsigned long count ) ;
    void text( const char *string, unsigned long count ) ;
    unsigned long textfit(const char *string, unsigned long strLen,
        struct TextExtent *textExtent, struct TextExtent *constrainingExtent,
        long strDirection, unsigned long constrainingBitWidth,
        unsigned long constrainingBitHeight ) ;
    void setfont(TextFont *font) ;

    // Intuition Drawing Routines
    void printitext(IntuiText *iText, long left, long top ) ;
    void drawborder( Border *border, long leftOffset, long topOffset ) ;
    void drawimage( struct Image *image, long leftOffset, long topOffset ) ;
    void eraseimage( struct Image *image, long leftOffset, long topOffset ) ;

    // Clip Routines
    int newregion(void) ;
    void disposeregion(void) ;
    BOOL addregion(short l, short t, short w, short h) ;
    void installclip(void) ;
    void removeclip(void) ;

    // Pointer Routines
    void setpointer( UWORD *pointer, long height,
        long width, long xOffset, long yOffset ) ;
    void clearpointer() ;

    // Area Routines
    short initarea(short w, short h, int size=1000) ;
    void freearea() ;
    long areaellipse(long xCenter, long yCenter, long a, long b ) ;
    long areamove( long x, long y ) ;
    long areadraw( long x, long y ) ;
    long areaend() ;
    BOOL flood( unsigned long mode, long x, long y ) ;

    // BackGround Drawing routines
    void setbgrp(RastPort *brp) ;
    void clearbgrp() ;

    void flushbg(int x, int y, int w, int h, int mode=0xC0) ;

    // Refresh routines
    void beginrefresh() ;
    void endrefresh(BOOL end) ;
    void refreshwindowframe() ;

} ;

inline void window::fok(gadget *g, unsigned long classe, unsigned short code)
{
    okflag = TRUE; active = FALSE ; emode = 0 ; applique = FALSE ;
}

inline void window::fcancel(gadget *g, unsigned long classe, unsigned short code)
{
    okflag = FALSE; active = FALSE ; emode = 0 ; applique = FALSE ;
}

inline void window::fapply(gadget *g, unsigned long classe, unsigned short code)
{
    okflag = TRUE; active = FALSE ; emode = 0 ; applique = TRUE ;
}

inline void window::handlevkey(USHORT code)
{
    if (code == 0x0D) {
        g->selectgadget(g->getcount()-2, FALSE) ;
    }
    else if (code == 0x1B) {
        g->selectgadget(g->getcount()-1, FALSE) ;
    }
    else
        g->parsegadgets(code) ;
}

inline void window::handlerawkey(USHORT code)
{
}

inline void window::handlemousebuttons(USHORT code, WORD x, WORD y, UWORD qualifier)
{
}

#if !defined( CLASS_WINDOW_INLINES_H ) && !defined( NO_CLASS_WINDOW_INLINES )
#include "window_inlines.h"
#endif

typedef void (window::*WFUNC)(gadget *, unsigned long, unsigned short) ;
#endif


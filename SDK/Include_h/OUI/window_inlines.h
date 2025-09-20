// $Id: window_inlines.h 1.1 1997/07/14 04:24:06 dlorre Exp $
#if !defined( CLASS_WINDOW_INLINES_H )
#define CLASS_WINDOW_INLINES_H

#include <stdio.h>
#include <string.h>

#include <proto/exec.h>
#include <proto/graphics.h>
#include <proto/layers.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <proto/utility.h>

inline void window::setfunc(void (*func)(long , unsigned long, unsigned short))
{
    reqfunc = func ;
}

inline void window::titles(const char *wt, const char *st)
{
    if (win) SetWindowTitles(win, (UBYTE *)wt, (UBYTE *)st) ;
}

inline void window::activate()
{
    if (win) ActivateWindow(win) ;
}

inline void window::front()
{
    if (win) WindowToFront(win) ;
}

inline void window::back()
{
    if (win) WindowToBack(win) ;
}

inline void window::resetidcmp()
{
    ModifyIDCMP(win, idcmp) ;
}

inline void window::recessedbox(short x, short y, short w, short h)
{
    if (win)
        DrawBevelBox(rp, x, y, w, h,
        GT_VisualInfo, ws->vi,
        GTBB_Recessed, TRUE,
        TAG_END);
}


inline void window::bevelbox(short x, short y, short w, short h)
{
    if (win)
        DrawBevelBox(rp, x, y, w, h,
        GT_VisualInfo, ws->vi,
        TAG_END);
}


inline MenuItem *window::itemaddress( unsigned long menuNumber )
{
    return ItemAddress( menu, menuNumber) ;
}

inline MenuItem *window::itemaddress(LONG m, LONG i, LONG s)
{
    return ItemAddress(menu, FULLMENUNUM(m, i, s)) ;
}

inline void window::clearmenustrip(void)
{
    ClearMenuStrip(win) ;
}

inline BOOL window::resetmenustrip(void)
{
    return ResetMenuStrip(win, menu) ;
}


inline void window::draw(long x, long y)                       // Draw(rp, ...)
{
    Draw(rp, x, y) ;
}

inline void window::polydraw(long count, WORD *polyTable)
{
    PolyDraw(rp, count, polyTable) ;
}

inline void window::rectfill(long xMin, long yMin, long xMax, long yMax)
{
    RectFill(rp, xMin, yMin, xMax, yMax) ;
}

inline void window::eraserect(long xMin, long yMin, long xMax, long yMax )
{
    EraseRect(rp, xMin, yMin, xMax, yMax) ;
}

inline void window::setapen(unsigned long pen)
{
    SetAPen(rp, pen) ;
}

inline void window::setbpen(unsigned long pen)
{
    SetBPen(rp, pen) ;
}

inline void window::setopen(unsigned long pen)
{
    SafeSetOutlinePen(rp, char(pen)) ;
}

inline void window::setrast(unsigned long pen)
{
    SetRast(rp, pen) ;
}

inline void window::setdrmd(unsigned long drawMode)
{
    SetDrMd(rp, drawMode) ;
}

inline void window::setdrpt(UWORD pattern)
{
    SetDrPt(rp, pattern) ;
}

inline void window::setafpt(const UWORD *pattern, BYTE count)
{
    SetAfPt(rp, (UWORD *)pattern, count) ;
}

inline short window::textlength(const char *string, unsigned long count )
{
    return TextLength(rp, STRPTR(string), count );
}


inline unsigned long window::textfit(const char *string, unsigned long strLen,
    struct TextExtent *textExtent, struct TextExtent *constrainingExtent,
    long strDirection, unsigned long constrainingBitWidth,
    unsigned long constrainingBitHeight )
{
    return TextFit(rp, STRPTR(string), strLen, textExtent, constrainingExtent,
        strDirection, constrainingBitWidth, constrainingBitHeight) ;
}

inline void window::setfont(TextFont *font)
{
    SetFont( rp, font) ;
}

// Intuition Drawing Routines

inline void window::printitext(IntuiText *iText, long left, long top )
{
    PrintIText( rp, iText, left, top) ;
}

inline void window::drawborder( Border *border, long leftOffset, long topOffset )
{
    DrawBorder( rp, border, leftOffset, topOffset );
}


inline void window::drawimage( struct Image *image, long leftOffset, long topOffset )
{
    DrawImage( rp, image, leftOffset, topOffset );
}

inline void window::eraseimage( struct Image *image, long leftOffset, long topOffset )
{
    EraseImage( rp, image, leftOffset,  topOffset );
}

// Clip Routines

inline int window::newregion(void)
{
    clipregion = NewRegion() ;
    if (clipregion) {
        cliprect = new Rectangle ;
        if (!cliprect) {
            DisposeRegion( clipregion ) ;
            clipregion = NULL ;
        }
    }

    return (clipregion != NULL) ;
}

inline void window::disposeregion(void)
{
    delete cliprect ;
    DisposeRegion( clipregion );
}

inline BOOL window::addregion(short l, short t, short w, short h)
{
    cliprect->MinX = l ;
    cliprect->MaxX = short(l+w) ;
    cliprect->MinY = t ;
    cliprect->MaxY = short(t+h) ;
    return OrRectRegion(clipregion, cliprect) ;
}

inline void window::installclip(void)
{
    InstallClipRegion(win->WLayer, clipregion) ;
}

inline void window::removeclip(void)
{
    clipregion = InstallClipRegion(win->WLayer, NULL) ;
}

// Pointer Routines

inline void window::setpointer( UWORD *pointer, long height,
    long width, long xOffset, long yOffset )
{
    SetPointer(win, pointer, height, width, xOffset, yOffset) ;
}

inline void window::clearpointer()
{
    ClearPointer(win) ;
}

// Area Routines

inline long window::areaellipse(long xCenter, long yCenter, long a, long b )
{
    return AreaEllipse( rp, xCenter, yCenter, a, b ) ;
}

inline long window::areamove( long x, long y )
{
    return AreaMove( rp, x, y );
}

inline long window::areadraw( long x, long y )
{
    return AreaDraw( rp, x, y );
}

inline long window::areaend()
{
    return AreaEnd( rp );
}

inline BOOL window::flood( unsigned long mode, long x, long y )
{
    return Flood( rp, mode, x, y );
}

// BackGround Drawing routines

inline void window::setbgrp(RastPort *brp)
{
    rp = bgrp = brp ;
    bgbm = bgrp->BitMap ;
}

inline void window::clearbgrp()
{
    rp = win->RPort ;
}

inline void window::flushbg(int x, int y, int w, int h, int mode)
{
    BltBitMapRastPort(bgbm, 0, 0, win->RPort, x, y, w, h, mode);
}

// Refresh routines

inline void window::beginrefresh()
{
    GT_BeginRefresh(win) ;
}

inline void window::endrefresh(BOOL end)
{
    GT_EndRefresh(win, end) ;
}

inline void window::refreshwindowframe()
{
    RefreshWindowFrame(win) ;
}
#endif

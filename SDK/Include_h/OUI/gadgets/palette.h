// $Id: palette.h 1.2 1997/07/14 04:27:16 dlorre Exp dlorre $
#ifndef CLASS_PALETTE_H
#define CLASS_PALETTE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_GADTOOLS_H
#define PLACETEXT_LEFT  0x0001  /* Right-align text on left side */
#endif

#ifndef CLASS_WINDOW_H
class window ;
#endif

#ifndef CLASS_GADGETLIST_H
class gadgetlist ;
#endif

#ifndef CLASS_GADGET_H
#include "gadgets/gadget.h"
#endif

// ========================================================================
// ===========================  PALETTE CLASS =============================
// ========================================================================

class palette : public gadget
{
    long numcolors ;
public:
    long cursel ;
    palette(gadgetlist *gl,
                void (window::*func)(gadget *, unsigned long, unsigned short),
                const char *text,
                long depth,
                long offset,
                long pen,
                long place=PLACETEXT_LEFT,
                short iwidth=20, short iheight=10) ;
    void set(long sel) ;
    void action(unsigned long classe, unsigned short code) ;
    void keystroke(BOOL shifted) ;
};

#endif

// $Id: checkbox.h 1.2 1997/07/14 04:26:26 dlorre Exp dlorre $
#ifndef CLASS_CHECKBOX_H
#define CLASS_CHECKBOX_H

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
// ==========================  CHECKBOX CLASS =============================
// ========================================================================

class checkbox : public gadget
{
public:
    long cursel ;
    checkbox(gadgetlist *gl,
             void (window::*func)(gadget *, unsigned long, unsigned short),
             const char *text, long checked=FALSE, long place=PLACETEXT_LEFT, BOOL disable=FALSE) ;
    void set(long flag) ;
    void disable(BOOL flag) ;
    void action(unsigned long, unsigned short) ;
    void keystroke(BOOL shifted) ;
};


#endif

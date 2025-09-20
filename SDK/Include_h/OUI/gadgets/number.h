// $Id: number.h 1.2 1997/07/14 04:27:12 dlorre Exp dlorre $
#ifndef CLASS_NUMBER_H
#define CLASS_NUMBER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
struct Image ;
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
// ==========================  NUMBER CLASS ===============================
// ========================================================================

class number : public gadget
{
    Image       *im ;
    TextFont    *gfont ;
public:
    long curval ;
    number(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           const char *title, long val, long max=10,
           unsigned long flags=PLACETEXT_LEFT,
           unsigned long justify=0) ;
    ~number() ;
    void action(unsigned long, unsigned short) ;
    void keystroke(BOOL shifted) ;
    void set(long val) ;
};
#endif

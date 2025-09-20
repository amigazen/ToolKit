//$Id: string.h 1.2 1997/07/14 04:27:28 dlorre Exp dlorre $
#ifndef CLASS_STRING_H
#define CLASS_STRING_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
struct Image ;
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
// ==========================  STRING CLASS ===============================
// ========================================================================

class string : public gadget
{
    Image   *im ;
    TextFont *gfont ;
public:
    long    maxsize ;
    STRPTR curstring ;
    STRPTR  buffer ;
    string(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           const char *title=NULL,
           const char *text=NULL,
           long max=64,
           unsigned long flags=PLACETEXT_LEFT,
           unsigned long justify=0) ;
    ~string() ;
    void action(unsigned long, unsigned short) ;
    void set(STRPTR) ;
    void keystroke(BOOL shifted) ;
};
#endif

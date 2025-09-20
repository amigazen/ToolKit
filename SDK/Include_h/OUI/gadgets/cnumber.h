// $Id: cnumber.h 1.3 1997/07/14 04:27:40 dlorre Exp dlorre $
#ifndef CLASS_CNUMBER_H
#define CLASS_CNUMBER_H

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

const char  INSIDECNUMBER = 0 ;
const char  RIGHTCNUMBER = 1 ;
const char  BOTTOMCNUMBER = 2 ;
const char  WIDTHCNUMBER = 4 ;
const char  HEIGHTCNUMBER = 8 ;


// ========================================================================
// ==========================  CNUMBER CLASS ==============================
// ========================================================================


class cnumber : public gadget
{
    STRPTR      norm1 ;
    STRPTR      norm2 ;
    STRPTR      under ;

    IntuiText   *it1 ;
    IntuiText   *it2 ;
    IntuiText   *it3 ;

    TextFont    *font ;
    TTextAttr   *underline ;
    TTextAttr   *plain ;
public:
    cnumber(gadgetlist *gl,
            void (window::*func)(gadget *, unsigned long, unsigned short),
            const char* t, long val,
            long border=FALSE, long place=PLACETEXT_LEFT,
            char style=INSIDECNUMBER) ;
    ~cnumber() ;
    void set(LONG val) ;
    void keystroke(BOOL shifted) ;
};

#endif

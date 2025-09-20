#ifndef CLASS_CSTRING_H
#define CLASS_CSTRING_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#if !defined( PLACETEXT_LEFT )
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


const char  INSIDECSTRING = 0 ;
const char  RIGHTCSTRING = 1 ;
const char  BOTTOMCSTRING = 2 ;
const char  WIDTHCSTRING = 4 ;
const char  HEIGHTCSTRING = 8 ;


// ========================================================================
// ==========================  CSTRING CLASS ==============================
// ========================================================================


class cstring : public gadget
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
    cstring(gadgetlist *gl,
            void (window::*func)(gadget *, unsigned long, unsigned short),
            const char*t, const char* text, long border=FALSE, long place=PLACETEXT_LEFT,
            char style=INSIDECSTRING) ;
    ~cstring() ;
    void set(const char *text) ;
    void keystroke(BOOL shifted) ;
};

#endif

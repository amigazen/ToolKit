#ifndef CLASS_FBUTTON_H
#define CLASS_FBUTTON_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
struct Image ;
struct IntuiText ;
#endif

#ifndef GRAPHICS_TEXT_H
struct TTextAttr ;
struct TextFont ;
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

#ifndef CLASS_SLIST_H
class slist ;
class slink ;
#endif

// ========================================================================
// ==========================  FBUTTON CLASS ==============================
// ========================================================================

class fbutton : public gadget
{
    STRPTR      text ;
    STRPTR      norm1 ;
    STRPTR      norm2 ;
    STRPTR      under ;

    IntuiText   *it1 ;
    IntuiText   *it2 ;
    IntuiText   *it3 ;

    TextFont    *font ;
    TTextAttr   *underline ;
public:
    fbutton(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           const char *t, BOOL def=FALSE, BOOL disable=FALSE) ;
    ~fbutton() ;
    void select(BOOL sel, BOOL disable=FALSE) ;
    void keystroke(BOOL shifted) ;
    void action(unsigned long classe, unsigned short code) ;
    void initlab(const char *t) ;
    void freelab() ;
    void set(const char *text) ;
};
#endif

// $Id: eslide.h 1.3 1997/07/14 04:26:54 dlorre Exp dlorre $
#ifndef CLASS_ESLIDE_H
#define CLASS_ESLIDE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#if !defined( PLACETEXT_LEFT )
#define PLACETEXT_LEFT  0x0001  /* Right-align text on left side */
#endif

#ifndef INTUITION_GADGETCLASS_H
#define LORIENT_HORIZ   1
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
// ============================  ESLIDE CLASS =============================
// ========================================================================


class eslide : public gadget
{
    long        cursel ;
    long        smin ;
    long        smax ;
    BOOL        disabled ;
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
    eslide(gadgetlist *gl,
               void (window::*func)(gadget *, unsigned long, unsigned short),
               long min,
               long max,
               long level,
               long freedom=LORIENT_HORIZ,
               const char *t=NULL,
               long flags=PLACETEXT_LEFT) ;
    ~eslide() ;
    void set(long level, long min=-1, long max=-1, short disable=FALSE) ;
    void action(unsigned long classe, unsigned short code) ;
    void keystroke(BOOL shifted) ;
};

#endif

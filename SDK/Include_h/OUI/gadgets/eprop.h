// $Id: eprop.h 1.2 1997/07/14 04:26:42 dlorre Exp dlorre $
#ifndef CLASS_EPROP_H
#define CLASS_EPROP_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#define LORIENT_HORIZ   1
#define LORIENT_VERT    2
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

const char  INSIDEPROP = 0 ;
const char  RIGHTPROP = 1 ;
const char  BOTTOMPROP = 2 ;
const char  WIDTHPROP = 4 ;
const char  HEIGHTPROP = 8 ;

// ========================================================================
// =============================  EPROP CLASS =============================
// ========================================================================

class eprop : public gadget
{
public:
    eprop(gadgetlist *gl,
        void    (window::*func)(gadget *, unsigned long, unsigned short),
        long    top,
        long    view,
        long    total,
        long    freedom=LORIENT_HORIZ,
        char    style=INSIDEPROP) ;

    ~eprop() ;
    void set(long top, long view, long total) ;
    void action(unsigned long classe, unsigned short code) ;
};

#endif

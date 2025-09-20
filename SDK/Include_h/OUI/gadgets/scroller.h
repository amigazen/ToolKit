// $Id: scroller.h 1.2 1997/07/14 04:27:22 dlorre Exp dlorre $
#ifndef CLASS_SCROLLER_H
#define CLASS_SCROLLER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
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
// ==========================  SCROLLER CLASS =============================
// ========================================================================


class scroller : public gadget
{
public:
    scroller(gadgetlist *gl,
             void (window::*func)(gadget *, unsigned long, unsigned short),
             long top, long view, long total,
             unsigned short arrows=TRUE) ;
};


#endif

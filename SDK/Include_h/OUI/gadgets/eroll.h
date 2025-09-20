#ifndef CLASS_EROLL_H
#define CLASS_EROLL_H

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
// ============================  EROLL CLASS =============================
// ========================================================================


class eroll : public gadget
{
long    cursel ;
long    rmin ;
long    rmax ;
BOOL    rfull ;
public:
    eroll(gadgetlist *gl,
               void (window::*func)(gadget *, unsigned long, unsigned short),
               long min,
               long max,
               long level,
               BOOL full=FALSE) ;
    ~eroll() ;
    void set(long level, long min=-1, long max=-1, short disable=FALSE) ;
    void action(unsigned long classe, unsigned short code) ;
    void keystroke(BOOL shifted) ;
};

#endif

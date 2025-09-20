#ifndef CLASS_BUTTON_H
#define CLASS_BUTTON_H

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

#ifndef CLASS_SLIST_H
class slist ;
class slink ;
#endif

// ========================================================================
// ==========================  BUTTON CLASS ===============================
// ========================================================================

class button : public gadget
{
    STRPTR text ;
public:
    button(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           const char *t) ;
    button(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           const char *t, BOOL def) ;
};
#endif

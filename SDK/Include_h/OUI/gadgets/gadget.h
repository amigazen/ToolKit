// $Id: gadget.h 1.2 1997/07/14 04:27:01 dlorre Exp dlorre $
#ifndef CLASS_GADGET_H
#define CLASS_GADGET_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
struct Gadget ;
struct Window ;
#endif

#ifndef CLASS_WINDOW_H
class window ;
#endif

#ifndef CLASS_GADGETLIST_H
class gadgetlist ;
#endif

// ========================================================================
// ==========================  GADGET CLASS ===============================
// ========================================================================

class gadget
{
protected:
    gadgetlist *glist ;
    void (window::*gfunc)(gadget *, unsigned long, unsigned short) ;
public:
    long    id ;
    Gadget  *gad ;
    Window  *w ;
    char    key ;
    gadget(gadgetlist *gl, void (window::*func)(gadget *, unsigned long, unsigned short)) ;
    virtual ~gadget() {}
    void setfunc(void (window::*func)(gadget *, unsigned long, unsigned short)) ;
    virtual void action(unsigned long, unsigned short) ;
    virtual void select(BOOL sel) ;
    virtual void keystroke(BOOL shifted) ;
    void underkey(const char *s) ;
};

inline void gadget::setfunc(void (window::*func)(gadget *, unsigned long, unsigned short))
{
    gfunc = func ;
}


#endif

// $Id: slider.h 1.2 1997/07/14 04:27:25 dlorre Exp dlorre $
#ifndef CLASS_SLIDER_H
#define CLASS_SLIDER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#define LORIENT_HORIZ   1
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
// ==========================  SLIDER CLASS ===============================
// ========================================================================

class slider : public gadget
{
    long vmin ;
    long vmax ;
public:
    long cursel ;
    slider(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           long min, long max, long level,
           long freedom=LORIENT_HORIZ,
           const char *text=NULL,
           const char *lformat=NULL,
           unsigned short mlen=0,
           long tplace=PLACETEXT_LEFT,
           long lplace=PLACETEXT_LEFT,
           long (*fdisp)(Gadget *, unsigned short)=NULL) ;
    void set(long level, long min=-1, long max=-1) ;
    void action(unsigned long classe, unsigned short code) ;
    void keystroke(BOOL shifted) ;
};
#endif

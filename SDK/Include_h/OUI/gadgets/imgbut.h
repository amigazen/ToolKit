// $Id: imgbut.h 1.2 1997/07/14 04:27:05 dlorre Exp dlorre $
#ifndef CLASS_IMGBUT_H
#define CLASS_IMGBUT_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
struct Image ;
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
// ============================  IMGBUT CLASS =============================
// ========================================================================


class imgbut : public gadget
{
public:
    imgbut(gadgetlist *gl,
           void (window::*func)(gadget *, unsigned long, unsigned short),
           Image *image,
           Image *box) ;
    ~imgbut() ;
    void select(BOOL sel) ;
    void set(Image* image) ;
};


#endif

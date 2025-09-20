// $Id: cycle.h 1.2 1997/07/14 04:26:36 dlorre Exp dlorre $
#ifndef CLASS_CYCLE_H
#define CLASS_CYCLE_H

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

#define OCYCLE_Base         (TAG_USER+100)
#define OCYCLE_Active       (OCYCLE_Base+0)
#define OCYCLE_Flags        (OCYCLE_Base+1)
#define OCYCLE_Text         (OCYCLE_Base+2)
#define OCYCLE_TextArray    (OCYCLE_Base+3)
#define OCYCLE_Label        (OCYCLE_Base+4)


// ========================================================================
// ==========================  CYCLE CLASS ================================
// ========================================================================

class cycle : public gadget
{
    const char  **xlabs ;
    STRPTR      *cylabs ;
    short       labsize ;
public:
    short   cursel ;

    cycle(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          const char *text,
          LONG      flags,
          long active, const char** table) ;
    cycle(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          const char *text,
          LONG      flags,
          long active, const char *t, ...) ;
    cycle(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          TagItem *tags) ;

    cycle(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          ULONG tag1, ...) ;
    ~cycle() ;
    void init(TagItem *tags) ;
    void initlabs(TagItem *tags) ;
    void freelabs() ;
    void action(unsigned long, unsigned short) ;
    void keystroke(BOOL shifted) ;
    void set(TagItem *tags) ;
    void set(ULONG tag1, ...) ;
};
#endif

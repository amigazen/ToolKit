// $Id: radio.h 1.3 1997/09/17 08:17:06 dlorre Exp dlorre $
#ifndef CLASS_RADIO_H
#define CLASS_RADIO_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#if !defined( UTILITY_TAGITEM_H )
#include <utility/tagitem.h>
#endif

#ifndef CLASS_WINDOW_H
class window ;
#endif

#ifndef CLASS_GADGETLIST_H
class gadgetlist ;
#endif

#ifndef CLASS_GAGDET_H
#include "gadgets/gadget.h"
#endif


#define ORADIO_Base         (TAG_USER+100)
#define ORADIO_Active       (ORADIO_Base+0)
#define ORADIO_Flags        (ORADIO_Base+1)
#define ORADIO_Spacing      (ORADIO_Base+2)
#define ORADIO_Text         (ORADIO_Base+3)
#define ORADIO_TextArray    (ORADIO_Base+4)


// ========================================================================
// ==========================  RADIO CLASS ================================
// ========================================================================


class radio : public gadget
{
    STRPTR *mxlabs ;
    LONG   labsize ;
    LONG    spacing ;
public:
    LONG cursel ;
    STRPTR curstring ;
    radio(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          TagItem *tags) ;

    radio(gadgetlist *gl,
          void (window::*func)(gadget *, unsigned long, unsigned short),
          ULONG tag1, ...) ;

    ~radio() ;
    void init(TagItem *tags) ;
    void action(unsigned long, unsigned short) ;
    void keystroke(BOOL shifted) ;
};

#endif

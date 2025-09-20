// $Id: listview.h 1.2 1997/07/14 04:27:08 dlorre Exp dlorre $
#ifndef CLASS_LISTVIEW_H
#define CLASS_LISTVIEW_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
struct Node ;
#endif

#ifndef EXEC_LISTS_H
struct List ;
#endif

#ifndef INTUITION_INTUITION_H
struct Gadget ;
struct Window ;
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

#ifndef CLASS_SLIST_H
class nlist ;
class nlink ;
#endif

// ========================================================================
// ==========================  LISTVIEW CLASS =============================
// ========================================================================

class listview : public gadget
{
    nlink *sl ;
    List *l ;
    Node *n ;
    Node *c ;
    int created ;
public:
    int count ;
    int cursel ;
    int curtop ;
    listview(gadgetlist *gl,
         void (window::*func)(gadget *, unsigned long, unsigned short),
         const char* title,
         unsigned long place,
         nlist *liste,
         unsigned short top=0,
         unsigned short sel=~0,
         short readonly=FALSE,
         unsigned short swidth=16,
         Gadget *showsel=NULL) ;

    ~listview() ;
    void set(unsigned short top, unsigned short sel=~0) ;
    void reset(nlist *liste, unsigned short top=0, unsigned short sel=~0) ;
    void keystroke(BOOL shifted) ;
    void action(unsigned long classe, unsigned short code) ;
};

#endif

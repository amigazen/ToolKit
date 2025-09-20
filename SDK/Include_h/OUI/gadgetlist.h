// $Id: gadgetlist.h 1.3 1998/01/13 20:02:45 dlorre Exp dlorre $
#ifndef CLASS_GADGETLIST_H
#define CLASS_GADGETLIST_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef GRAPHICS_TEXT_H
#include "graphics/text.h"
#endif

#ifndef INTUITION_INTUITION_H
#include "intuition/intuition.h"
#endif

#ifndef LIBRARIES_GADTOOLS_H
struct NewGadget ;
#endif

#ifndef CLASS_RECTANGLE_H
#include "rectangle.h"
#endif

class window ;
class gadget ;

// ========================================================================
// ==========================  GADGETLIST CLASS ===========================
// ========================================================================

class gadgetlist : public rectangle
{
friend class gadget ;
    gadget  **gtab ;
    WORD    count ;         // How many gadgets are currently here ?
    WORD    max ;           // How many gadgets max available ?

    IntuiText   *it ;
    TTextAttr   PlainAttr ;
    TTextAttr   BoldAttr ;
    TextFont    *bfont ;
public:
    UBYTE       gpen ;
    window      *win ;      // owner of the gadgetlist
    NewGadget   *ng ;
    Gadget      *glist ;
    Gadget      *gad ;
    Window      *wp ;

    long        fontheight ;
    BOOL        initok ;

    gadgetlist(window *w, short gmax) ;      // the creator
    ~gadgetlist() ;                         // the destructor
    void processgadget(LONG id,
                       unsigned long,
                       unsigned short) ;    // events processing
    void addgadgets() ;                     // add glist to window
    void updategadgets() ;                  // window opened with glist
    void setfont(TTextAttr *) ;
    void setdefault(BOOL bolden) ;
    long ltext(const char *) ;
    long lmax(const char **) ;
    long lmax(const char *, ...) ;
    void setgpen(UBYTE g) { gpen=g ;}
    void selectgadget(LONG id, BOOL shifted) ;
    void parsegadgets(USHORT code) ;
    gadget *getgadget(LONG id) ;
    WORD getcount() { return count ; }
} ;



#endif

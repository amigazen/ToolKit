#include <exec/types.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <dos/exall.h>
#include <graphics/gfx.h>
#include <graphics/gfxbase.h>
#include <intuition/intuition.h>
#include <intuition/classes.h>
#include <intuition/gadgetclass.h>
#include <intuition/icclass.h>
#include <libraries/gadtools.h>
#include <workbench/workbench.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/layers.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <proto/icon.h>
#include <proto/console.h>
#include <proto/utility.h>
#include <clib/macros.h>
#include <clib/alib_protos.h>
#include <mydebug.h>

#include "screen.h"
#include "window.h"
#include "gadgetlist.h"
#include "gadgets/string.h"
#include "gadgets/cstring.h"
#include "gadgets/eprop.h"
#include "gadgets/fbutton.h"
#include "slist.h"
#include "locale.h"

#define FILE    gfile->curstring
#define DRAWER  gdrawer->curstring
#define COMMENT gcom->curstring

#define DISPLAY_FILES   0
#define DISPLAY_DIRS    1
#define MAXLEN          255
#define MAXENTRIES      100

static WORD TOT_DISPLAY ;

static WORD FONTHEIGHT ;
static WORD LEFTBOX ;
static WORD TOPDBOX ;
static WORD TOPFBOX ;
static WORD WIDTHBOX ;
static WORD HEIGHTBOX ;

static WORD LEFTSEL ;
static WORD TOPSEL ;
static WORD WIDTHSEL ;
static WORD HEIGHTSEL ;

struct DClick {
    ULONG s;
    ULONG m;
} ;

class filesel : public window
{
public:
    void fparent(gadget *g, unsigned long classe, unsigned short code) ;
    void fdrawer(gadget *g, unsigned long classe, unsigned short code) ;
    void fprop(gadget *g, unsigned long classe, unsigned short code) ;
    char title[80] ;
    BOOL clipok ;
    filesel(short l, short t, short w, short h) : window(l, t, w, h) {}
    void open(screen *) ;
    void simpleevent(IntuiMessage *msg) ;
    void handlevkey(USHORT code) ;
};

static IntuiMessage     *message;       // the message the IDCMP sends us
static BPTR             clef, oldkey;

static UWORD            code;       // IDCMP stuff
static ULONG            classe;

static APTR             object;
static List             *RepList;
static Node             *RepNode, *Garage = NULL;
static ULONG            nbfics = 0;
static LONG             topentry = 0;
static char             chemin[MAXLEN];
static char             DTEMP[MAXLEN] = "";
static TextAttr         **Style;
static char             stemp[MAXLEN], stemp2[MAXLEN], tmp[MAXLEN];
static FileInfoBlock    *bloc;
static WORD             indsel, numsel ;
static char             pat[MAXLEN] ;
static char             RexxCmd[MAXLEN] ;
static DClick           declic = {0, 0};
static Region           *clipregion ;
static Rectangle        cliprect ;
static char             comstring[80] = "" ;

static LONG             lm ;

static char name[MAXLEN];
static BOOL Mode = DISPLAY_FILES;
static BOOL clickon ;

static TextAttr ITALIC80 = {
        (STRPTR)"topaz.font",
        TOPAZ_EIGHTY,FSF_ITALIC,0
};

static struct TextAttr Plain, Italic ;

static BOOL Saver ;
static IntuiText *listetext ;

IMPORT ULONG rexxsig ;
IMPORT MsgPort *RexxPort ;

static string   *gdrawer ;      // Répertoire
static string   *gfile ;        // Nom du fichier
static eprop    *gprop ;        // Scroller
static string   *gcom ;         // Commentaire Lecture/Ecriture
static cstring  *cgcom ;        // Commentaire Lecture Seule

static UBYTE    fpen ;
static UBYTE    bpen ;

IMPORT lstring  ok ;
IMPORT lstring  cancel ;
IMPORT lstring  parent ;
IMPORT lstring  drawer ;
IMPORT lstring  file ;
IMPORT lstring  comment ;

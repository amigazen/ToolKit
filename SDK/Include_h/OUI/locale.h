// $Id: locale.h 1.2 1997/07/14 04:24:43 dlorre Exp dlorre $
#ifndef CLASS_LOCALE_H
#define CLASS_LOCALE_H 1

#include <exec/types.h>
#include <libraries/locale.h>


#ifdef LOCALISE
#define NPARMS(a, b, c, d) (a, b, c, d)
#define LPARMS(a, b, c) (a, b, c)
#define OPARMS(a, b, c) (a, b, "MSG_UNDEF", c)
#define DPARMS(a, b) (a, b, "MSG_UNDEF")
#else
#define NPARMS(a, b, c, d) (a, b, d)
#define LPARMS(a, b, c) (a, b)
#define OPARMS(a, b, c) (a, b, c)
#define DPARMS(a, b) (a, b)
#endif

class catalog
{
friend class lstring ;
    Catalog *cat ;
    int locnum ;
public:
#if defined( LOCALISE )
    char catname[80] ;
    char langname[80] ;
#endif
    catalog(char *name, char *deflang, char *lang) ;
    ~catalog() ;
} ;

class lstring               // Classe de l'application
{
friend class catalog ;
public:
    char *string ;
#ifdef LOCALISE
    lstring(catalog *lc, char *def, char *desc, int id=-1) ;
#else
    lstring(catalog *lc, char *def, int id=-1) ;
#endif
    // Implicit conversion
    operator const char *() const { return (const char *)string ; }
    operator const UBYTE *() const { return (const UBYTE *)string ; }

    // Explicit conversion (used with system functions not declaring const)
    char* charptr() const { return string ; }
    UBYTE* ubyteptr() const { return (UBYTE *)string ; }
} ;
#endif
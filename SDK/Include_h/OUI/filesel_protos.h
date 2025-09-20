/* module filesel.o */

#if !defined( INTUITION_INTUITION_H )
struct IntuiMessage ;
#endif

#if !defined( DEVICES_KEYMAP_H )
struct KeyMap ;
#endif

#if !defined( CLASS_SCREEN_H )
class screen ;
#endif

extern BOOL getfile(screen *screen,  STRPTR s, STRPTR title,  STRPTR drawer,
    STRPTR comment) ;

extern LONG DeadKeyConvert(IntuiMessage *msg, UBYTE *kbuffer, LONG kbsize,
    KeyMap *kmap) ;

extern BOOL getPath(STRPTR , STRPTR );

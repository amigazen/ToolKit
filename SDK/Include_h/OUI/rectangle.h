#ifndef CLASS_RECTANGLE_H
#define CLASS_RECTANGLE_H 1

class rectangle
{
public:
    short maxw ;    // MaxWidth
    short maxh ;    // MaxHeight
    short minw ;    // MinWidth
    short minh ;    // MinHeight

    short left ;    // Left Edge
    short top ;     // Top Edge
    short width ;   // Width
    short height ;  // Height

    rectangle(short l, short, short w, short h) ;
    virtual ~rectangle() {}
    void box(short l, short t, short w, short h) ;
    void relbox(short dx, short dy, short dw, short dh) ;
    virtual void move(short dx, short dy=0) ;
    virtual void size(short dw, short dh=0) ;
    virtual void limits(short wmin, short hmin, short wmax, short hmax) ;
 };
#endif

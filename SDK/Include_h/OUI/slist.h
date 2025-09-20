// Projet : Euterpe
// Fichier : liste.h

// Auteur : Dominique Lorre
// Date de création : 15/07/94

#ifndef CLASS_SLIST_H
#define CLASS_SLIST_H

#include <exec/types.h>


// =========================================================================
// ========================== SLINK CLASS ==================================
// =========================================================================


class slink {
friend class slist ;
friend class slink_iter ;
    slink *pred ;           // preceding node
    slink *succ ;           // next node
protected:
    virtual  long type() const ;
public:
    long    indexof() ;                           // position in list

    slink() : pred(NULL), succ(NULL) {}
    virtual ~slink() ;
    virtual slink*  _follower() const
    {slink *p = next() ;
        while (p && p->type() != type()) p = p->next() ;
        return p ;
    }
    virtual slink*  _predecessor() const
    {slink *p = prev() ;
        while (p && p->type() != type()) p = p->prev() ;
        return p ;
    }
    slink*  next() const { return succ ; }     // move functions
    slink*  prev() const { return pred ; }
    slink*  follower() const
    { return _follower() ; }
    slink*  predecessor() const { return _predecessor() ; }
};


// =========================================================================
// ========================== SLIST CLASS ==================================
// =========================================================================


class slist
{
friend class slink_iter ;
    slink*  head ;
    slink*  tail ;
public:
    slist() : head(NULL), tail(NULL) {}
    virtual ~slist() ;
    void    init() { head = tail = NULL ;}
    void    free() ;
    void    addhead(slink *) ;
    void    addtail(slink *) ;
    void    insert(slink *, slink *) ;
    void    remove(slink *c) ;
    BOOL    isempty() { return head ? FALSE : TRUE ; }
    slink*  get(long) ;
    slink*  first() { return head ; }
    slink*  last() { return tail ; }
    void    replace(slink *, slink *) ;
    long    count() ;
};

// =========================================================================
// ======================== SLINK_ITER CLASS ===============================
// =========================================================================


class slink_iter {
    slink*   current ;
    slist*   cs ;
public:
    slink_iter(slist *s) : cs(s) { current = cs->head ; }
    void set_current(slink* n) { current = n ; }
    slink* get_current() { return current ; }

    slink* first() { return current = cs->head ; }
    slink* last()  { return current = cs->tail ; }

    slink* operator++()     // préfixe
    {
        return current ? current = current->succ  : NULL ;
    } // préfixe
    slink* operator++(int)  // postfixe
    {
    slink *t = current ;
        current = current? current->succ: NULL ;
        return t ;
    }
    slink* operator--()     // préfixe
    {
    return current ? current = current->pred : NULL ;
    }
    slink* operator--(int)  // postfixe
    {
    slink *t = current ;
        current = current ? current->pred : NULL ;
        return t ;
    }
};

// =========================================================================
// ========================== NLINK CLASS ==================================
// =========================================================================


class nlink : public slink {    // slink with name
public:
    STRPTR label ;
    nlink() : label(NULL) {}
    nlink*   next() { return (nlink *)slink::next() ; }
    nlink*   prev() { return (nlink *)slink::prev() ; }
};

// =========================================================================
// ========================== NLIST CLASS ==================================
// =========================================================================


class nlist : public slist
{
public:
    nlink*  findname(STRPTR name) ;
    void    enqueue(nlink *node) ;
    nlink* first() { return (nlink *)slist::first() ; }
    nlink* last() { return (nlink *)slist::last() ; }
};

// =========================================================================
// ===================== NLINK_ITER CLASS ==================================
// =========================================================================


class nlink_iter : private slink_iter {
public:
    nlink_iter(slist *s) : slink_iter(s) {}
    void set_current(nlink* n) { slink_iter::set_current((slink *)n) ; }
    nlink* get_current() { return (nlink *)slink_iter::get_current() ; }
    nlink* first() { return (nlink *) slink_iter::first() ; }
    nlink* last() { return (nlink *) slink_iter::last() ; }
    nlink* operator++() { return (nlink *) slink_iter::operator++(); }
    nlink* operator++(int) { return (nlink *) slink_iter::operator++(0); }
    nlink* operator--() { return (nlink *) slink_iter::operator--(); }
    nlink* operator--(int) { return (nlink *) slink_iter::operator--(0); }
};

#endif
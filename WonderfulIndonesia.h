#ifndef WONDERFULINDONESIA_H_INCLUDED
#define WONDERFULINDONESIA_H_INCLUDED

#include <iostream>
using namespace std;

#define infoparent(P) (P)->infoparent
#define nextparent(P) (P)->nextparent
#define prevparent(P) (P)->prevparent
#define first(L) ((L).first)
#define last(L) ((L).last)
#define nextrelasi(P) (P)->nextrelasi
#define prevrelasi(P) (P)->prevrelasi
#define nextchild(P) (P)->nextchild
#define infochild(P) (P)->infochild
#define nil NULL


typedef struct elmrelasi *adrrelasi;
typedef struct elmparent *adrparent;
typedef struct elmchild *adrchild;

struct infotypeparent{
    string nama;
    string kota;
    int jarak;
};

struct elmparent{
    infotypeparent infoparent;
    adrparent nextparent;
    adrparent prevparent;
    adrrelasi nextrelasi;
};

struct Listparent{
    adrparent first;
    adrparent last;
};

void createParent(Listparent &Lp);
adrparent createlementparent(infotypeparent xp);
void insertParent(Listparent &Lp, adrparent Pp);
void insertFirstParent(Listparent &Lp, adrparent Pp);
void insertLastParent(Listparent &Lp, adrparent Pp);
void insertAfterParent(Listparent &Lp,adrparent Precp, adrparent Pp);
void deleteFirstParent(Listparent &Lp);
void deleteLastParent(Listparent &Lp);
void deleteAfterParent(Listparent &Lp,adrparent Precp);
adrparent searchparent(Listparent Lp, string x);
void showparent(Listparent &Lp);


struct infotypechild{
    string nama;
    int kode;
};

struct elmchild{
    infotypechild infochild;
    adrchild nextchild;
};

struct Listchild{
    adrchild first;
    adrchild last;
};

void createChild(Listchild &Lc);
adrchild createlementChild(infotypechild xc);
void insertFirstChild(Listchild &Lc, adrchild Pc);
void insertLastChild(Listchild &Lc, adrchild Pc);
void insertAfterChild(Listchild &Lc, adrchild Precc, adrchild Pc);
void deleteFirstChild(Listchild &Lc);
void deleteLastChild(Listchild &Lc);
void deleteAfterChild(Listchild &Lc, adrchild Precc);
void insertchild(Listchild &Lc, adrchild Pc);
void showchild(Listchild &Lc);
adrchild searchchild(Listchild Lc, string x);

struct elmrelasi{
    adrparent nextparent;
    adrchild nextchild;
    adrrelasi nextrelasi;
    adrrelasi prevrelasi;
};

struct Listrelasi{
    adrrelasi first;
    adrrelasi last;
};

void createrelasi(Listrelasi &Lr);
adrrelasi createlementrelasi(adrparent Pp, adrchild Pc);
void insertrelasi(Listrelasi &Lr, adrrelasi P);
void insertFirstrelasi(Listrelasi &Lr, adrrelasi P);
void insertLastrelasi(Listrelasi &Lr, adrrelasi P);
void insertAfterrelasi(Listrelasi &Lr,adrrelasi Prec);
void deleteFirstrelasi(Listrelasi &Lr);
void deleteLastrelasi(Listrelasi &Lr);
void deleteAfterrelasi(Listrelasi &Lr,adrrelasi Prec);
void showrelasi(Listrelasi &Lr);
adrrelasi searchrelasi(Listrelasi &Lr,adrparent Pp,adrchild Pc);
adrrelasi searchrelationbychild(Listrelasi Lr, adrchild Pc);
adrrelasi searchrelationbyparent(Listrelasi Lr, adrparent Pp);
void deleteparent(Listparent &Lp, Listrelasi &Lr, string x);
void deleterelasi(Listrelasi &Lr, adrparent Pp, adrchild Pc);
void deletechild(Listchild &Lc, Listrelasi &Lr,string x);
adrchild palingluas(Listchild Lc,Listrelasi Lr);
void showsulit(Listparent Lp);
void showparentwithchild(Listparent Lp, Listrelasi Lr);



#endif // WONDERFULINDONESIA_H_INCLUDED

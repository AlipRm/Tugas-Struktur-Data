#include "WonderfulIndonesia.h"

void createParent(Listparent &Lp){
    first(Lp) = nil;
    last(Lp) = nil;
}
adrparent createlementparent(infotypeparent xp){
    adrparent P = new elmparent;
    infoparent(P) = xp;
    nextparent(P) = nil;
    prevparent(P) = nil;
    return P;
}

void insertParent(Listparent &Lp, adrparent Pp){
    if(first(Lp) == nil){
        insertFirstParent(Lp,Pp);
    }else{
        adrparent Q = first(Lp);
        adrparent Precp = nil;
        while(infoparent(Q).nama < infoparent(Pp).nama && nextparent(Q) != nil){
            Precp = Q;
            Q = nextparent(Q);
        }

        if(nextparent(Q) != nil && Precp != nil){
            insertAfterParent(Lp,Precp,Pp);
        } else{
            if (infoparent(Q).nama > infoparent(Pp).nama){
                insertFirstParent(Lp,Pp);
            } else {
                insertLastParent(Lp,Pp);
            }

        }
    }
}

void insertFirstParent(Listparent &Lp, adrparent Pp){
    if(first(Lp) == nil && last(Lp) == nil){
        last(Lp) = Pp;
        first(Lp) = Pp;
    }else{
        nextparent(Pp) = first(Lp);
        prevparent(first(Lp)) = Pp;
        first(Lp) = Pp;
    }
}
void insertLastParent(Listparent &Lp, adrparent Pp){
    if(first(Lp) == nil && last(Lp)){
        first(Lp) = Pp;
        last(Lp) = Pp;
    }else{
        prevparent(Pp) = last(Lp);
        nextparent(last(Lp)) = Pp;
        last(Lp) = Pp;
    }
}
void insertAfterParent(Listparent &Lp, adrparent Precp, adrparent Pp){
    nextparent(Pp) = nextparent(Precp);
    prevparent(Pp) = Precp;
    nextparent(Precp) = Pp;
    prevparent(nextparent(Pp)) = Pp;
}

void deleteFirstParent(Listparent &Lp){
    if(first(Lp) == nil){
        cout<<"Tidak ada data"<<endl;
    }else if(first(Lp) == last(Lp)){
        first(Lp) == nil;
        last(Lp) == nil;
    }else{
        adrparent P = first(Lp);
        first(Lp) = next(P);
        nextparent(P) = nil;
        prevparent(first(Lp)) == nil;
    }
}
void deleteLastParent(Listparent &Lp){
    if(first(Lp) == nil){
        cout<<"Tidak ada data"<<endl;
    }else if(nextparent(first(Lp)) == nil){
        first(Lp) = nil;
        last(Lp) = nil;
    }else{
        adrparent P = first(Lp);
        last(Lp) = prevparent(P);
        prevparent(P) = nil;
        nextparent(last(Lp)) = nil;
    }
}
void deleteAfterParent(Listparent &Lp, adrparent Precp){
    if(first(Lp) == nil ){
        cout<<"Tidak ada data"<<endl;
    }else if(first(Lp) == last(Lp)){
        first(Lp) = nil;
        last(Lp) = nil;
    }else{
        adrparent P = nextparent(Precp);
        nextparent(Precp) = nextparent(P);
        prevparent(nextparent(P)) = Precp;
        nextparent(P) = nil;
        prevparent(P) = nil;
    }
}

adrparent searchparent(Listparent Lp, string x){
    adrparent P = first(Lp);
    while(P != nil){
        if(infoparent(P).nama == x){
            return P;
        }
        P = nextparent(P);
    }
    return nil;
}
void showparent(Listparent &Lp){
    adrparent Pp = first(Lp);
    if(first(Lp) == nil){
        cout<<"Data tidak ada"<<endl;
    }else{
        while(nextparent(Pp) != nil){
            cout<<"Nama Tempat Wisata : "<<infoparent(Pp).nama<<endl;
            cout<<"Nama Kota Wisata : "<<infoparent(Pp).kota<<endl;
            cout<<"Jarak tempuh : "<<infoparent(Pp).jarak<<endl;
            Pp = nextparent(Pp);
        }
        cout<<"Nama Tempat Wisata : "<<infoparent(Pp).nama<<endl;
        cout<<"Nama Kota Wisata : "<<infoparent(Pp).kota<<endl;
        cout<<"Jarak tempuh : "<<infoparent(Pp).jarak<<endl;
    }
}
void deleteparent(Listparent &Lp, Listrelasi &Lr, string x){
    adrparent P = searchparent(Lp, x);
    if(P){
        if(first(Lp) == last(Lp)){
            deleteFirstParent(Lp);
        }else{
            adrparent Q = first(Lp);
            if(Q != P){
                while(nextparent(Q) != P){
                    Q = nextparent(Q);
                }
                deleteAfterParent(Lp,Q);
            }else if(nextparent(Q) == nil){
                deleteLastParent(Lp);
            }else{
                deleteFirstParent(Lp);
            }
            adrrelasi R = searchrelationbyparent(Lr, P);
            if(R != nil){
                adrrelasi R2 = first(Lr);
                if(R2 != R){
                    while(nextrelasi(R2) != R){
                        R2 = nextrelasi(R2);
                    }
                    deleteAfterrelasi(Lr, R2);
                }else if(nextrelasi(R2) == nil){
                    deleteLastrelasi(Lr);
                }else{
                    deleteFirstrelasi(Lr);
                }
            }
        }
    }
}
//CHILD
void createChild(Listchild &Lc){
    first(Lc) = nil;
    last(Lc) = nil;
}
adrchild createlementChild(infotypechild xc){
    adrchild P = new elmchild;
    infochild(P) = xc;
    nextchild(P) = nil;
    return P;
}
void insertFirstChild(Listchild &Lc, adrchild Pc){
    if(first(Lc) == nil){
        first(Lc) = Pc;
        last(Lc) = Pc;
        nextchild(Pc) = Pc;
    }else{
        nextchild(Pc) = first(Lc);
        first(Lc) = Pc;
        nextchild(last(Lc)) = first(Lc);
    }
}

void insertLastChild(Listchild &Lc, adrchild Pc){
    nextchild(last(Lc)) = Pc;
    last(Lc) = Pc;
    nextchild(last(Lc)) = first(Lc);
}
void insertAfterChild(Listchild &Lc, adrchild Precc, adrchild Pc){
    nextchild(Pc) = nextchild(Precc);
    nextchild(Precc) = Pc;
}
void deleteFirstChild(Listchild &Lc){
    if (first(Lc) == nil) {
        cout << "Tidak ada data" << endl;
    } else if (first(Lc) == last(Lc)) {
        first(Lc) = nil;
        last(Lc) = nil;
    } else {
        adrchild P = first(Lc);
        first(Lc) = nextchild(P);
        nextchild(last(Lc)) = first(Lc);
        nextchild(P) = nil;
    }
}
void deleteLastChild(Listchild &Lc){
    if (first(Lc) == nil) {
        cout << "Tidak ada data" << endl;
    } else if (first(Lc) == last(Lc)) {
        first(Lc) = nil;
        last(Lc) = nil;
    } else {
        adrchild P = first(Lc);
        while (nextchild(P) != last(Lc)) {
            P = nextchild(P);
        }
        nextchild(P) = first(Lc);
        last(Lc) = P;
    }
}
void deleteAfterChild(Listchild &Lc, adrchild Precc){
    if (first(Lc) == nil) {
        cout << "Tidak ada data" << endl;
    } else if (first(Lc) == last(Lc)) {
        first(Lc) = nil;
        last(Lc) = nil;
    } else {
        adrchild P = nextchild(Precc);
        nextchild(Precc) = nextchild(P);
        nextchild(P) = nil;
    }
}

void insertchild(Listchild &Lc, adrchild Pc){
    if(first(Lc) == nil){
        insertFirstChild(Lc,Pc);
    }else{
        adrchild Q = first(Lc);
        adrchild Precc = nil;
        while(infochild(Q).nama < infochild(Pc).nama && nextchild(Q) != first(Lc)){
            Precc = Q;
            Q = nextchild(Q);
        }

        if(nextchild(Q) != nil && Precc != nil){
            insertAfterChild(Lc,Precc,Pc);
        } else{
            if (infochild(Q).nama > infochild(Pc).nama){
                insertFirstChild(Lc,Pc);
            } else {
                insertLastChild(Lc,Pc);
            }

        }
    }
}

adrchild searchchild(Listchild Lc, string x){
    adrchild P = first(Lc);
    while(P != nil){
        if(infochild(P).nama == x){
            return P;
        }
        P = nextchild(P);
    }
    return nil;
}


void deletechild(Listchild &Lc, Listrelasi &Lr,string x){
    if(first(Lc) == last(Lc)){
        deleteFirstChild(Lc);
    }else{
        adrchild P = searchchild(Lc,x);
        if(P != nil){
            adrchild Q = first(Lc);
            if( Q != P){
                while(nextchild(Q) != P){
                    Q = nextchild(Q);
                }
                deleteAfterChild(Lc,Q);
            }else if(nextchild(Q) == first(Lc)){
                deleteLastChild(Lc);
            }else{
                deleteFirstChild(Lc);
            }
        }

        adrrelasi R = searchrelationbychild(Lr,P);
        if(R != nil ){
            adrrelasi R2 = first(Lr);
            if(R2 != R){
                while(nextrelasi(R2) != R){
                    R2 = nextrelasi(R2);
                }
                deleteAfterrelasi(Lr,R2);
            }else if(nextrelasi(R2) == nil){
                deleteLastrelasi(Lr);
            }else{
                deleteFirstrelasi(Lr);
            }
        }
    }
}
void showchild(Listchild &Lc){
    adrchild P = first(Lc);
    if(first(Lc) == nil){
        cout<<"Data tidak ada"<<endl;
    }else{
        while(nextchild(P) != first(Lc)){
            cout<<infochild(P).nama<<endl;
            cout<<infochild(P).kode<<endl;
            P = nextchild(P);
        }
        cout<<infochild(P).nama<<endl;
        cout<<infochild(P).kode<<endl;
    }
}


void createrelasi(Listrelasi &Lr){
    first(Lr) = nil;
    last(Lr) = nil;
}
adrrelasi createlementrelasi(adrparent PParent, adrchild PChild){
    adrrelasi P = new elmrelasi;
    nextparent(P) = PParent;
    nextchild(P) = PChild;
    nextrelasi(P) = nil;
    prevrelasi(P) = nil;
    return P;

}
void insertrelasi(Listrelasi &Lr, adrrelasi P){
    if(first(Lr) == nil){
        first(Lr) = P;
        last(Lr) = P;
        nextrelasi(P) = P;
        prevrelasi(P) = P;
    }else{
      nextrelasi(P) = first(Lr);
      prevrelasi(P) = last(Lr);
      nextrelasi(last(Lr)) = P;
      prevrelasi(first(Lr)) = P;
      last(Lr) = P;
    }
}
void insertFirstrelasi(Listrelasi &Lr, adrrelasi P){

    if(first(Lr) == nil){
        first(Lr) = P;
        last(Lr) = P;
        nextrelasi(P) = P;
        prevrelasi(P) = P;
    }else{
        nextrelasi(P) = first(Lr);
        prevrelasi(P) = last(Lr);
        nextrelasi(last(Lr)) = P;
        prevrelasi(first(Lr)) = P;
        first(Lr) = P;
    }
}
void insertLastrelasi(Listrelasi &Lr, adrrelasi P){
    if(first(Lr) == nil){
        insertFirstrelasi(Lr,P);
    }else{
        nextrelasi(P) = first(Lr);
        prevrelasi(P) = last(Lr);
        nextrelasi(last(Lr)) = P;
        prevrelasi(first(Lr)) = P;
        last(Lr) = P;
    }
}
void insertAfterrelasi(Listrelasi &Lr,adrrelasi Prec){
    adrrelasi P = first(Lr);
    nextrelasi(P) = nextrelasi(Prec);
    prevrelasi(P) = Prec;
    prevrelasi(nextrelasi(Prec)) = P;
    nextrelasi(Prec) = P;
}
void deleteFirstrelasi(Listrelasi &Lr){
    if(first(Lr) == nil){
        cout<<"Data tidak ada"<<endl;
    }else if(nextrelasi(first(Lr)) == first(Lr)){
        first(Lr) = nil;
        last(Lr) = nil;
    }else{
        adrrelasi P = first(Lr);
        first(Lr) = nextrelasi(P);
        nextrelasi(last(Lr)) = first(Lr);
        prevrelasi(first(Lr)) = last(Lr);
        nextrelasi(P) = nil;
        prevrelasi(P) = nil;
    }
}
void deleteLastrelasi(Listrelasi &Lr){
    if(first(Lr) == nil){
        cout<<"Data tidak ada"<<endl;
    }else if(nextrelasi(first(Lr)) == first(Lr)){
        first(Lr) = nil;
        last(Lr) = nil;
    }else{
        adrrelasi P = last(Lr);
        last(Lr) = prevrelasi(P);
        nextrelasi(last(Lr)) = first(Lr);
        prevrelasi(first(Lr)) = last(Lr);
        nextrelasi(P) = nil;
        prevrelasi(P) = nil;
    }
}
void deleteAfterrelasi(Listrelasi &Lr,adrrelasi Prec){
    if(first(Lr) == nil){
        cout<<"Data tidak ada"<<endl;
    }else if(nextrelasi(first(Lr)) == first(Lr)){
        first(Lr) = nil;
        last(Lr) = nil;
    }else{
        adrrelasi P = nextrelasi(Prec);
        nextrelasi(Prec) = nextrelasi(P);
        prevrelasi(nextrelasi(P)) = Prec;
        nextrelasi(P) = nil;
        prevrelasi(P) = nil;
    }
}
void showrelasi(Listrelasi &Lr){
    adrrelasi P = first(Lr);
    if(first(Lr) == nil){
        cout<<"Data tidak ada"<<endl;
    }else{
        while(nextrelasi(P) != first(Lr)){
            cout<< "Nama Wisata : " << infoparent(nextparent(P)).nama << endl;
            cout<< "Kota : " << infoparent(nextparent(P)).kota << endl;
            cout<< "Jarak : " << infoparent(nextparent(P)).jarak <<endl;
            cout<<"Agent : " <<infochild(nextchild(P)).nama <<endl;
            P = nextrelasi(P);
        }
        cout<< "Nama Wisata : " << infoparent(nextparent(P)).nama << endl;
        cout<< "Kota : " << infoparent(nextparent(P)).kota << endl;
        cout<< "Jarak : " << infoparent(nextparent(P)).jarak <<endl;
        cout<<"Agent : " <<infochild(nextchild(P)).nama <<endl;
    }
}

void deleterelasi(Listrelasi &Lr, adrparent Pp, adrchild Pc){
    adrrelasi P = searchrelasi(Lr,Pp,Pc);
    if(P){
        if(first(Lr) == last(Lr)){
            deleteFirstrelasi(Lr);
        }else{
            adrrelasi Q = first(Lr);
            if(Q != P) {
                while(next(Q) != P){
                    Q = nextrelasi(Q);
                }
                deleteAfterrelasi(Lr, Q);
            } else if(nextrelasi(Q) == nil) {
                deleteLastrelasi(Lr);
            } else {
                deleteFirstrelasi(Lr);
            }
        }
    } else {
        cout << "Relasi tidak ditemukan!" << endl;
    }
}
adrrelasi searchrelasi(Listrelasi &Lr,adrparent Pp,adrchild Pc){
    adrrelasi P = first(Lr);
    while(P != first(Lr)){
        if(nextparent(P) == Pp && nextchild(Pc) == Pc ){
            return P;
        }
        P = nextrelasi(P);
    }
    return nil;
}
adrrelasi searchrelationbyparent(Listrelasi Lr, adrparent Pp){
    adrrelasi P = first(Lr);
    while(P != first(Lr)){
        if(nextparent(P) == Pp){
            return P;
        }
        P = nextrelasi(P);
    }
    return nil;
}

adrrelasi searchrelationbychild(Listrelasi Lr, adrchild Pc){
    adrrelasi P = first(Lr);
    while(nextrelasi(P) != first(Lr)){
        if(nextchild(P) == Pc){
            return P;
        }
        P = nextrelasi(P);
    }
    if(nextchild(P) == Pc){
        return P;
    }
    return nil;
}

void showsulit(Listparent Lp){
    adrparent res;
    int jarak = 0;
    adrparent P = first(Lp);
    while(P != nil){
        if(infoparent(P).jarak > jarak){
            jarak = infoparent(P).jarak;
            res = P;
        }
        P = nextparent(P);
    }
    cout<<"Tempat Parawisata yang paling sulit dikunjungi adalah "<<infoparent(res).nama<<" yang jaraknya mencapai "<<infoparent(res).jarak<<" Kilometer"<<endl;
}

adrchild palingluas(Listchild Lc,Listrelasi Lr){
    adrchild P = first(Lc);
    int max = 0;
    string nama = "";

    if(first(Lc) != nil && first(Lr) != nil){
        int jumlah = 0;
        while(nextchild(P) != first(Lc)){
            adrrelasi Pr = first(Lr);
            while(nextrelasi(Pr) != nil){
                if(nextchild(Pr) == P){
                    jumlah++;
                }
                Pr = nextrelasi(Pr);
            }
            if(jumlah > max){
                nama = infochild(P).nama;
            }
            P = nextchild(P);
        }
        adrrelasi Pr = first(Lr);
        while(nextrelasi(Pr) != nil){
            if(nextchild(Pr) != nil){
                jumlah++;
            }
            Pr = nextrelasi(Pr);
        }
        if(jumlah > max){
            nama = infochild(P).nama;
        }
    }
    if(nama != ""){
        cout<<"Agent yang paling luas jangkauannya adalah "<<nama<<endl;
    }else{
        cout<<"Data kosong"<<endl;
    }
}

void showparentwithchild(Listparent Lp, Listrelasi Lr){
    if(first(Lp) == nil){
        cout << "Data kosong!" << endl;
    } else {
        adrparent P = first(Lp);
        while(nextparent(P) != nil){
            cout<<"Tempat Parawisata"<<endl;
            cout<<"Nama Tempat Wisata : "<<infoparent(P).nama<<endl;
            cout<<"Nama Kota : "<<infoparent(P).kota<<endl;
            cout<<"Jarak tempuh : "<<infoparent(P).jarak<<endl;
            cout<<"Nama Agent :" << endl;

            if(first(Lr) == nil) {
                cout << "Data kosong!" << endl;
            } else {
                adrrelasi R = first(Lr);
                while(nextrelasi(R)!= first(Lr)){
                    if(nextparent(R) == P){
                        cout<<infochild(nextchild(R)).nama<<endl;
                    }
                    R = nextrelasi(R);
                }
                if(nextparent(R) == P){
                    cout<<infochild(nextchild(R)).nama<<endl;
                }
                cout<<endl;
                P = nextparent(P);
            }
        }
        cout<<"Tempat Parawisata"<<endl;
        cout<<"Nama Tempat Wisata : "<<infoparent(P).nama<<endl;
        cout<<"Nama Kota : "<<infoparent(P).kota<<endl;
        cout<<"Jarak tempuh : "<<infoparent(P).jarak<<endl;
        cout<<"Nama Agent :" << endl;SS

        if(first(Lr) == nil) {
            cout << "Data kosong!" << endl;
        } else {
            adrrelasi R = first(Lr);
            while(nextrelasi(R)!= first(Lr)){
                if(nextparent(R) == P){
                    cout<<infochild(nextchild(R)).nama<<endl;
                }
                R = nextrelasi(R);
            }
            if(nextparent(R) == P){
                cout<<infochild(nextchild(R)).nama<<endl;
            }
            cout<<endl;
            P = nextparent(P);
        }
    }

}




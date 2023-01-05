#include <iostream>
#include "WonderfulIndonesia.h"
#include "Menu.h"
using namespace std;

int main()
{
    Listparent Lp;
    createParent(Lp);
    adrparent Pp;
    infotypeparent xp;

    Listchild Lc;
    createChild(Lc);
    adrchild Pc;
    infotypechild xc;

    string namaparwis,namaagent,kota;
    int jarak;

    Listrelasi Lr;
    adrrelasi Pr;
    createrelasi(Lr);

//    xp.nama = "lembang";
//    xp.kota = "bandung";
//    xp.jarak = 100;
//
//    adrparent p = createlementparent(xp);
//    insertParent(Lp,p);
//
//    xp.nama = "ciwidey";
//    xp.kota = "cianjur";
//    xp.jarak = 140;
//
//    p = createlementparent(xp);
//    insertParent(Lp,p);
//
//    xp.nama = "tangkuban";
//    xp.kota = "gatau";
//    xp.jarak = 405;
//
//    p = createlementparent(xp);
//    insertParent(Lp,p);
//
//    showparent(Lp);
//
//    adrchild c;
//
//    xc.kode = 23;
//    xc.nama = "aisha";
//
//    c = createlementChild(xc);
//    insertchild(Lc,c);
//
//    xc.kode = 45;
//    xc.nama = "alif";
//
//    c = createlementChild(xc);
//    insertchild(Lc,c);
//    //showchild(Lc);
//
//    adrrelasi r;
//
//    p = searchparent(Lp,"ciwidey");
//    c = searchchild(Lc,"aisha");
//
//    r = createlementrelasi(p,c);
//    insertLastrelasi(Lr,r);
//
//    p = searchparent(Lp,"lembang");
//    c = searchchild(Lc,"aisha");
//
//    r = createlementrelasi(p,c);
//    insertLastrelasi(Lr,r);
//
//    p = searchparent(Lp,"tangkuban");
//    c = searchchild(Lc,"alif");
//
//    r = createlementrelasi(p,c);
//    insertLastrelasi(Lr,r);
//
//    cout << "\n" <<endl;
//    showchild(Lc);
//
//    deletechild(Lc,Lr,"alif");
//
//    cout << endl;
//    showchild(Lc);
//
//    cout << endl;
    //showrelasi(Lr);


    int menu = 0;
    menu = selectMenu();

    while(menu != 0){
        switch(menu){
        case 1:{
            cout<<"====================Tambah Tempat Parawisata===================="<<endl;
            int jumlah = 0;
            cout<<"Jumlah tempat parawisata yang akan ditambah ?"<<endl;
            cin>>jumlah;
            for(int i = 0;i<jumlah;i++){
                cout<<"\nTempat ke-"<<i+1<<endl;
                cout<<"Nama tempat : ";
                cin>>xp.nama;
                cout<<endl;
                cout<<"Nama kota : ";
                cin>>xp.kota;
                cout<<endl;
                cout<<"Jarak tempuh menuju tempat wisata :";
                cin>>xp.jarak;
                Pp = createlementparent(xp);
                insertParent(Lp,Pp);
                cout<<endl;
            }
            cout<<"Nama tempat berhasil ditambahkan"<<endl;
            break;
        }
        case 2:{
            cout<<"====================Tambah Agent Parawisata===================="<<endl;
            int jumlah = 0;
            cout<<"Jumlah Agent yang akan ditambahkan ?"<<endl;
            cin>>jumlah;
            for(int i = 0; i < jumlah; i++){
                cout<<"\nAgent ke- "<< i+1<<endl;
                cout<<"Nama Agent : ";
                cin>>xc.nama;
                cout<<endl;
                cout<<"Kode Agent : ";
                cin>>xc.kode;
                Pc = createlementChild(xc);
                insertchild(Lc,Pc);
                cout<<endl;
            }
            cout<<"Agent berhasil ditambahkan"<<endl;
            break;
        }
        case 3:{
           cout<<"====================Cari Tempat Wisata===================="<<endl;
           cout<<"Nama tempat wisata yang akan dicari ?"<<endl;
           cin>>namaparwis;
           Pp = searchparent(Lp,namaparwis);
           if(Pp){
                cout<<"\nNama tempat yang ditemukan "<<endl;
                cout<<"Nama tempat wisata : "<<infoparent(Pp).nama<< " "<<endl;
           }else{
            cout<<"\nNama tempat tersebut tidak ada!"<<endl;
           }
           cout<<endl;
           break;
        }
        case 4:{
            cout<<"====================Tambah Relasi===================="<<endl;
            cout<<"Nama Tempat Parawisata : ";
            cin>>namaparwis;
            cout<<endl;
            cout<<"Nama Agentnya : ";
            cin>>namaagent;

            Pp = searchparent(Lp,namaparwis);
            Pc = searchchild(Lc,namaagent);

            if(Pp == nil){
                cout<<"Nama tempat tidak ditemukan"<<endl;
            }else if(Pc == nil){
                cout<<"Nama agent tidak ditemukan"<<endl;
            }else{
                Pr = createlementrelasi(Pp,Pc);
                insertLastrelasi(Lr,Pr);
                cout<<"Berhasil menambahkan relasi agent "<<infochild(Pc).nama<<" ke parawisata "<<infoparent(Pp).nama<<endl;
            }
            cout<<endl;
            break;
        }
        case 5:{
            cout<<"====================Cari Agent===================="<<endl;
            cout<<"Nama wisata : ";
            cout<<endl;
            cin>>namaparwis;
            Pp = searchparent(Lp,namaparwis);
            if( Pp != nil){
                cout<<"\nNama Agent yang melayani wisata "<<namaparwis<< " ditemukan"<<endl;
                cout<<"Nama Wisata: "<<infoparent(Pp).nama<<" "<<endl;
            }else{
                cout<<"\nNama Agent tidak ditemukan!"<<endl;
            }
            cout<<endl;
            break;
        }
        case 6:{
            cout<<"====================Hapus Agent===================="<<endl;
            cout<<"Nama Agent yang akan dihapus ? ";
            cout<<endl;
            cin>>namaagent;
            deleteFirstChild(Lc);
            deleteFirstrelasi(Lr);
            cout<<"\nAgent berhasil dihapus"<<endl;
            cout<<endl;
            break;
        }
        case 7:{
            cout<<"====================Hapus Tempat Wisata===================="<<endl;
            cout<<"Nama Tempat yang akan dihapus ? ";
            cout<<endl;
            cin>>namaparwis;
            cout<<"Nama Agent yang berelasi dengan wisata yang akan dihapus ?";
            cout<<endl;
            cin>>namaagent;

            Pp = searchparent(Lp,namaparwis);
            Pc = searchchild(Lc,namaagent);

            deleterelasi(Lr,Pp,Pc);
            cout<<"\nNama tempat wisata berhasil dihapus"<<endl;
            cout<<endl;
            break;
        }
        case 8:{
            cout<<"====================Tampilkan Tempat Wisata dengan Agenntnya===================="<<endl;
            showparentwithchild(Lp,Lr);
            cout<<endl;
            break;
        }
        case 9:{
            cout<<"====================Tempat Wisata yang paling sulit diakses===================="<<endl;
            showsulit(Lp);
            break;
        }
        case 10:{
            cout<<"====================Agent yang paling luas jangkauannya===================="<<endl;
            palingluas(Lc,Lr);
            break;
        }
        case 11:{
            cout<<"====================Tempat Parawisata===================="<<endl;
            showparent(Lp);
            cout<<endl;
            break;
        }
        case 12:{
            cout<<"====================Nama Agent===================="<<endl;
            showchild(Lc);
            cout<<endl;
            break;
        }
    }
        char balik;
        cout<<"Kembali ke menu utama ?(Y/N) : ";
        cin>>balik;
        cout<<endl;

        if(balik == 'Y' || balik == 'y'){
            menu = selectMenu();
        }else{
            menu = 0;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI APLIKASI"<<endl;

    return 0;

}

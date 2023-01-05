#include "Menu.h"
#include <iostream>

int selectMenu(){
    cout <<"==========Selamat Datang Pada Alif Travel=========="<<endl;
    cout<<"1. Tambah Tempat Parawisata"<<endl;
    cout<<"2. Tambah Agent Parawisata"<<endl;
    cout<<"3. Mencari Tempat Wisata"<<endl;
    cout<<"4. Tambah Relasi Tempat Wisata dan Agentnya"<<endl;
    cout<<"5. Mencari Agent Yang Melayani Wisata"<<endl;
    cout<<"6. Menghapus Agent dan Relasinya"<<endl;
    cout<<"7. Menghapus Tempat Wisata dari Agent "<<endl;
    cout<<"8. Menampilkan Tempat Wisata beserta Agentnya"<<endl;
    cout<<"9. Menampilkan Tempat Wisata Yang Sulit Diakses"<<endl;
    cout<<"10. Menampilkan Agent Wisata Yang Paling Luas Jangkauannya"<<endl;
    cout<<"11. Menampilkan Tempat Parawisata"<<endl;
    cout<<"12. Menampilkan Agent Parawisata"<<endl;
    cout<<"0. Keluar"<<endl;

    cout<<"Pilih Menu :";

    int input = 0;
    cin>>input;
    cout<<endl;
    return input;
}

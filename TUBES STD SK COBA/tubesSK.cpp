#include "tubesSK.h"
using namespace std;

int selectMenu(){
    int input;
    cout<<" ==========================  MENU  =========================="<<endl;
    cout<<" 1. Menambah pasien"<<endl;
    cout<<" 2. Menghapus pasien"<<endl;
    cout<<" 3. Menampilkan pasien"<<endl;
    cout<<" 4. Menambahkan poliklinik ke pasien"<<endl;
    cout<<" 5. Menghapus poliklinik dari pasien"<<endl;
    cout<<" 6. Menampilkan poliklinik dari pasien"<<endl;
    cout<<" 7. Total poliklinik dari pasien"<<endl;
    cout << " 8. Menampilkan semua data" << endl;
    cout<<" Masukan menu : ";
    cin>>input;
    return input;
}

void createlistPasien(listPasien &P){
    first(P) = nil;
}

adrpasien findpasien(listPasien P){
    int FindNumber;
    adrpasien Q;

    cout<<" Masukkan nomor pasien : ";
    cin>>FindNumber;

    Q = first(P);
    while(Q != nil){
        if(info(Q).noPasien == FindNumber){
            return Q;
        }
        Q = next(Q);
    }
    if(Q == nil){
        cout<<" Tidak ditemukan."<<endl;
        return Q;
    }
}

void addpasien(listPasien &P){
    pasien data;
    adrpasien R, Q;

    cout<<" Nomor pasien : ";
    cin>>data.noPasien;
    cout<<" Nama : ";
    cin>>data.nama;
    cout<<" NIK : ";
    cin>>data.nik;
    cout<<" Umur: ";
    cin>>data.umur;
    cout<<" Keluhan : ";
    cin>>data.keluhan;

    R = new elmpasien;
    info(R) = data;
    next(R) = nil;
    child(R) = nil;

    if(first(P) == nil){
        first(P) = R;
    }else{
        Q = first(P);
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = R;
    }
}

void deletepasien(listPasien &P){
    adrpasien R, Q;

    R = findpasien(P);
    if(R != nil){
        if(next(first(P)) == nil){
            first(P) = nil;
        }else if(R == first(P)){
            first(P) = next(R);
            next(R) = nil;
        }else if(next(R) == nil){
            Q = first(P);
            while(next(Q) != R){
                Q = next(Q);
            }
            next(Q) = nil;
        }else{
            Q = first(P);
            while(next(Q) != R){
                Q = next(Q);
            }
            next(Q) = next(R);
            next(R) = nil;
        }
    }
}

void showpasien(listPasien P){
    adrpasien R = first(P);
    while(R != nil){
        cout<<" Nama   : "<<info(R).nama<<endl;
        cout<<" NIK   : "<<info(R).nik<<endl;
        cout<<" Umur   : "<<info(R).umur<<endl;
        cout<<" Keluhan   : "<<info(R).keluhan<<endl;
        cout<<" Nomor Pasien   : "<<info(R).noPasien<<endl<<endl;
        R = next(R);
    }
}

adrpoli findpoli(listPasien P, adrpasien R){
    adrpoli Q;
    string FindName;

    if(R != nil){
        cout<<" Nama poli : ";
        cin>>FindName;
        Q = child(R);
        while(Q != nil){
            if(info(Q).jenis == FindName){
                return Q;
            }
            Q = next(Q);
        }
        if(Q == nil){
            cout<<" Tidak ditemukan."<<endl;
            return Q;
        }
    }else{
        Q = nil;
        return Q;
    }
}

void addpoli(listPasien &P){
    poli data;
    adrpoli Q;

    cout<<" Nama Poliklinik : ";
    cin>>data.jenis;

    Q = new elmpoli;
    info(Q) = data;
    next(Q) = nil;

    connectChild(P, Q);
}

void deletepoli(listPasien &P){
    adrpasien R;
    adrpoli Q;

    R = findpasien(P);
    if(R != nil){
        Q = findpoli(P, R);
        hapusChild(P, R, Q);
    }
}

void showpoli(listPasien P){
    adrpasien R;
    adrpoli Q;

    R = findpasien(P);
    if(R != nil){
        Q = child(R);
        while(Q != nil){
            cout<<" Nama Poliklinik : "<<info(Q).jenis<<endl;
            Q = next(Q);
        }
    }
}

void connectChild(listPasien &P, adrpoli Q){
    adrpasien S;
    adrpoli R;

    S = findpasien(P);
    if(S != nil){
        if(child(S) == nil){
            child(S) = Q;
        }else{
            R = child(S);
            while(next(R) != nil){
                R = next(R);
            }
            next(R) = Q;
        }
    }
}

void hapusChild(listPasien &P, adrpasien S, adrpoli Q){
    adrpoli R;

    if(Q == child(S)){
        child(S) = next(Q);
        next(Q) = nil;
    }else{
        R = child(S);
        while(next(R) != Q){
            R = next(R);
        }
        next(R) = next(Q);
        next(Q) = nil;
    }
}

void countPoliklinik(listPasien P){
    adrpasien S;
    adrpoli Q;
    int noPasien;
    int total = 0;

    cout<<" Masukkan no pasien : ";
    cin>>noPasien;

    S = first(P);
    while(S != nil){
        if(info(S).noPasien == noPasien){
            Q = child(S);
            while(Q != nil){
                total++;
                Q = next(Q);
            }
        }
        S = next(S);
    }
    cout<<" Total poliklinik : "<<total<< " poliklinik" <<endl;
}

void selectMenu2(int &pilihan) {
    cout << " Kembali ke menu utama? (Y/N) : ";
    char input;
    cin >> input;
    cout << endl;
    if (input == 'Y' || input == 'y') {
        pilihan = selectMenu();
    } else if (input == 'N' || input == 'n') {
        pilihan = 0;
    }
};

void showAll(listPasien P, adrpasien a) {
    if (first(P) == nil) {
        cout << " Data Kosong" << endl;
    }else{
        a = first(P);
        while (a != nil) {
            cout << " Nomor Pasien: " << info(a).noPasien << endl;
            cout << " Nama: " << info(a).nama << endl;
            cout << " NIK: " << info(a).nik << endl;
            cout << " Umur: " << info(a).umur << endl;
            cout << " Keluhan: " << info(a).keluhan << endl;
            adrpoli b = child(a);
            while (b != nil) {
                cout << " Poliklinik: " << info(b).jenis << endl;
                b = next(b);
            }
            cout << endl;
            a = next(a);
        }
        cout << endl;
    }
}

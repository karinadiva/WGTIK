#ifndef TUBESSK_H_INCLUDED
#define TUBESSK_H_INCLUDED

using namespace std;
#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child
#define first(P) ((P).first)
#define nil NULL

struct pasien{
    string nama;
    int nik;
    int umur;
    string keluhan;
    int noPasien;
};

struct poli{
    string jenis;
};

typedef struct elmpasien* adrpasien;
typedef struct elmpoli* adrpoli;

struct elmpasien{
    pasien info;
    adrpasien next;
    adrpoli child;
};

struct elmpoli{
    poli info;
    adrpoli next;
};

struct listPasien{
    adrpasien first;
};

struct listPoli{
    adrpoli first;
};

int selectMenu();

void createlistPasien(listPasien &P);
adrpasien findpasien(listPasien P);
void addpasien(listPasien &P);
void deletepasien(listPasien &P);
void showpasien(listPasien P);


adrpoli findpoli(listPasien P, adrpasien R);
void addpoli(listPasien &P);
void deletepoli(listPasien &P);
void showpoli(listPasien P);
void connectChild(listPasien &P, adrpoli Q);
void hapusChild(listPasien &P, adrpasien S, adrpoli Q);
void countPoliklinik(listPasien P);
void selectMenu2(int &pilihan);
void showAll(listPasien P, adrpasien a);

#endif // TUBESSK_H_INCLUDED

#include "tubesSK.h"
#include <iostream>

using namespace std;

#include <cstdlib>

int main()
{
    listPasien Puskesmas;
    int masukan;

    createlistPasien(Puskesmas);

    masukan = selectMenu();
    while(masukan != 0){
        if(masukan == 1){
            cout << endl;
            addpasien(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 2){
            cout << endl;
            deletepasien(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 3){
            cout << endl;
            showpasien(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 4){
            cout << endl;
            addpoli(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 5){
            cout << endl;
            deletepoli(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 6){
            cout << endl;
            showpoli(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 7){
            cout << endl;
            countPoliklinik(Puskesmas);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 8){
            cout << endl;
            adrpasien a;
            showAll(Puskesmas, a);
            cout << endl;
            selectMenu2(masukan);
        }
    }
}

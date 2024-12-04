#include <iostream>
#include "mll.h"

using namespace std;

void createList(ListMahasiswa &L) {
    first(L) = nullptr;
}
adrMahasiswa createElemenMahasiswa(elemMahasiswa x) {
    adrMahasiswa P = new elemMahasiswa;
    info(P) = x;
    // ask this part, how tf do i do ts with that header structure
}
adrTugas createElemenTugas(elemTugas x) {
    adrTugas P = new elemTugas;
    info(P) = x;
    // this too lil nigga
}
void addMahasiswa(ListMahasiswa &L, adrMahasiswa P) {
    //1
    cout << "Choose insert: " << endl;
    cout << "1. Insert first" << endl;
    cout << "2. Insert last" << endl;
    int input;
    cin >> input;
    if (input == 1) {
        //do dat insert first dawg
    } else if (input == 2) {
        //do dat insert last ya heard
    } else {
        cout << "Invalid choice" << endl;
    }
}
void showMahasiswa(ListMahasiswa L) {
    //2
    adrMahasiswa P = first(L);
    if (P!=nullptr) {
        while (P!=nullptr) {
            //outputtin dat data ting
            P = nextMhs(P);
        }
    } else {
        cout << "No data shown" << endl;
    }
}
void deleteMahasiswa(ListMahasiswa &L, adrMahasiswa P){
    //3
    adrMahasiswa Q = first(L);
    if (Q!=nullptr) {
        while (Q!=nullptr) {
             if (Q == P) {
                // do dem deletin like u smokin dem opps
                break;
             }
             Q = nextMhs(Q);
        }
    } else {
        cout << "No data shown" << endl;
    }
}
void searchMahasiswa(ListMahasiswa L, adrMahasiswa P){
    //4
    adrMahasiswa Q = first(L);
    if (Q!=nullptr) {
        while (Q!=nullptr) {
             if (Q == P) {
                // search dat shit circlin dem opps block
                break;
             }
             Q = nextMhs(Q);
        }
    } else {
        cout << "No data shown" << endl;
    }
}
void addTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
    //5
    //man my brain aint brainin rn
}
void connectTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
    //6
    //man fuck this
}
void showAll(ListMahasiswa L) {
    //7

}
void searchTugas(ListMahasiswa L, adrTugas P) {
    //8

}
void deleteTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
    //9

}
void countTugas(ListMahasiswa &L, adrMahasiswa P) {
    //10

}

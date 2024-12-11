#include <iostream>
#include "mll.h"

using namespace std;

void createList(ListMahasiswa &L) {
    first(L) = nullptr;
}
adrMahasiswa createElemenMahasiswa(infotypeMhs x) {
    adrMahasiswa P = new elemMahasiswa;
    info(P) = x;
    nextMhs(P) = nullptr;
    return P;
}
adrTugas createElemenTugas(infotypeTug x) {
    adrTugas P = new elemTugas;
    info(P) = x;
    nextTug(P) = nullptr;
    return P;
}
void addMahasiswa(ListMahasiswa &L, adrMahasiswa P) {
    //1
    cout << "Choose insert: " << endl;
    cout << "1. Insert first" << endl;
    cout << "2. Insert last" << endl;
    int input;
    cin >> input;
    if (input == 1) {
        //insert first
        if (first(L) != nullptr) {
            nextMhs(P) = first(L);
            first(L) = P;
        } else {
            first(L) = P;
        }
    } else if (input == 2) {
        //insert last
        if (first(L) != nullptr) {
            adrMahasiswa Q = first(L);
            for (nextMhs(Q) != nullptr) {
                Q = nextMhs(Q);
            }
            nextMhs(Q) = P;
        } else {
            first(L) = P;
        }
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
            cout << "Nama: " << info(P).nama << endl;
            cout << "Kelas: " << info(P).kelas << endl;
            cout << "Angkatan: " << info(P).angkatan << endl;
            cout << "Jurusan: " << info(P).jurusan << endl;
            cout << "Gender: " << info(P).gender << endl;
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
             if (nextMhs(Q) == P) {
                //Made it myself
                nextMhs(Q) = nextMhs(nextMhs(Q));
                Q = nextMhs(Q);
                Q = nullptr;
                break;
             }
             Q = nextMhs(Q);
        }
    } else {
        cout << "No data shown" << endl;
    }
}
adrMahasiswa searchMahasiswa(ListMahasiswa L, string name){
    //4
    adrMahasiswa Q = first(L);
    adrMahasiswa result = nullptr;
    if (Q!=nullptr) {
        while (Q!=nullptr) {
             if (info(Q).nama == name) {
                // search dat shit circlin dem opps block
                cout << "Mahasiswa " << name << " Exist" << endl;
                result = Q;
                break;
             }
             Q = nextMhs(Q);
        }
    } else {
        cout << "No data shown" << endl;
    }
    return result;
}
void addTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
    //5
    //Whichever used, they be same
    //For efficiency shit, just use ins first
    //insert first
    if (first(L) != nullptr){
        nextMhs(P) = nextTug(Q);
        nextTug(Q) = P;
    } else {
        cout << "List is empty" << endl;
    }
    //insert last
    adrTugas R = nextTug(Q);
    while(nextMhs(R)!=nullptr) {
        R = nextMhs(R);
    }
    nextMhs(R) = P;
}
//void connectTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
//    //6
//    //man fuck this
//}
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
//

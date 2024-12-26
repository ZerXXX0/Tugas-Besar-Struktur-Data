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
    cout << "3. Insert after" << endl;
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
            while (nextMhs(Q) != nullptr) {
                Q = nextMhs(Q);
            }
            nextMhs(Q) = P;
        } else {
            first(L) = P;
        }
    } else if (input == 3) {
        cout << "Masukkan Nilai Prec(nama mahasiswa yang menjadi patokan): " << endl;
        string input2;
        cin >> input2;

        adrMahasiswa prec = searchMahasiswa(L, input2);
        if (prec != nullptr) {
            nextMhs(P) = nextMhs(prec);
            nextMhs(prec) = P;
        } else {
            cout << "Cannot do operation, prec not found exception";
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
    /*
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
    */

    // Correction
    // Supposed to be insert in child, not parent
    cout << "Choose insert: " << endl;
    cout << "1. Insert first" << endl;
    cout << "2. Insert last" << endl;
    cout << "3. Insert after" << endl;
    int input;
    cin >> input;
    if (input == 1) {
        //insert first
        if (first(L) != nullptr){
            if (nextTug(P) != nullptr) {
                nextTug(P) = nextTug(Q);
                nextTug(Q) = P;
            } else {
                nextTug(Q) = P;
            }
        } else {
            cout << "List is empty" << endl;
        }
    } else if (input == 2) {
       //insert last
       if (nextTug(Q) != nullptr) {
            adrTugas R = nextTug(Q);
            while(nextTug(R)!= nullptr) {
                R = nextTug(R);
            }
            nextTug(R) = P;
       } else {
            nextTug(P) = P;
       }

    } else if (input == 3) {
        //insert after
        cout << "Masukkan Nilai Prec(nama tugas yang menjadi patokan): " << endl;
        string input2;
        cin >> input2;

        adrTugas prec = searchTugas(L, input2);
        if (prec != nullptr) {
            nextTug(Q) = nextTug(prec);
            nextTug(prec) = P;
        } else {
            cout << "Cannot do operation, prec not found exception";
        }
    } else {
        cout << "Invalid choice" << endl;
    }
}
//void connectTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
//    //6
//    //man fuck this
//}
void showAll(ListMahasiswa L) {
    //7
    if (first(L) != nullptr) {
        adrMahasiswa P = first(L);
        while (P != nullptr) {
            cout << "Nama: " << info(P).nama << endl;
            cout << "Kelas: " << info(P).kelas << endl;
            cout << "Angkatan: " << info(P).angkatan << endl;
            cout << "Jurusan: " << info(P).jurusan << endl;
            cout << "Gender: " << info(P).gender << endl;
            cout << "Tugas: " << endl;
            adrTugas Q = nextTug(P);
            while (Q != nullptr) {
                cout << "   Nama: " << info(Q).nama << endl;
                cout << "   Matkul: " << info(Q).matkul << endl;
                cout << "   Kode Matkul: " << info(Q).kodeMatkul << endl;
                cout << "   Deadline: " << info(Q).deadline << endl;
                Q = nextTug(Q);
            }
            P = nextMhs(P);
        }
    }
}
adrTugas searchTugas(ListMahasiswa L, string name) {
    //8
    adrTugas found;
    if (first(L) != nullptr) {
        adrMahasiswa P = first(L);
        while (P != nullptr) {
            adrTugas Q = nextTug(P);
            while (Q != nullptr) {
                if (info(Q).nama == name) {
                    found = Q;
                    break;
                }
                Q = nextTug(Q);
            }
            P = nextMhs(P);
        }
    }
    return found;
}
void deleteTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q) {
    //9
    adrMahasiswa R = first(L);
    if (R!=nullptr) {
        while (R!=nullptr) {
            adrTugas S = nextTug(R);
            while (S!=nullptr) {
                if (S == P) {
                    nextTug(R) = nextTug(nextTug(S));
                    S = nullptr;
                    break;
                } else if (nextTug(S) == P) {
                    //Made it myself
                    nextTug(S) = nextTug(nextTug(S));
                    S = nextTug(S);
                    S = nullptr;
                    break;
                 }
                 S = nextTug(S);
            }
        }
    } else {
        cout << "No data in list" << endl;
    }
}
void countTugas(ListMahasiswa &L, adrMahasiswa P) {
    //10
    int count = 0;
    if (first(L) != nullptr) {
        adrTugas Q = nextTug(P);
        while (Q != nullptr) {
            count++;
            Q = nextTug(Q);
        }
    }
    cout << "Assignment from this student: " << count << endl;
}
//

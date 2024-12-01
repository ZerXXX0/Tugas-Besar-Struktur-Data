#include <iostream>
#define info(P) P->info
#define nextMhs(P) P->nextMhs
#define first(L) L.first
#define nextTug(P) P->nextTug

using namespace std;

typedef struct elemMahasiswa *adrMahasiswa;
typedef struct elemTugas *adrTugas;
struct elemMahasiswa {
    string nama, kelas, jurusan, gender;
    int angkatan;
    adrMahasiswa nextMhs;
    adrTugas nextTug;
};
struct elemTugas {
    string matkul, deadline, kodeMatkul;
    adrTugas nextTug;
};
struct ListMahasiswa {
    adrMahasiswa first;
};

void createList(ListMahasiswa &L);
adrMahasiswa createElemenMahasiswa(elemMahasiswa);
adrTugas createElemenTugas(elemTugas);
void addMahasiswa(ListMahasiswa &L, adrMahasiswa P); //1
void showMahasiswa(ListMahasiswa L); //2
void deleteMahasiswa(ListMahasiswa &L, adrMahasiswa P); //3
void searchMahasiswa(ListMahasiswa L, adrMahasiswa P); //4
void addTugas(ListMahasiswa &L, adrTugas P); //5
void connectTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q); //6
void showAll(ListMahasiswa L); //7
void searchTugas(ListMahasiswa L, adrTugas P); //8
void deleteTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q); //9
void countTugas(ListMahasiswa &L, adrMahasiswa P); //10

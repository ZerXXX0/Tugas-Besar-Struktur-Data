#include <iostream>
#define info(P) P->info
#define nextMhs(P) P->nextMhs
#define first(L) L.first
#define nextTug(P) P->nextTug

using namespace std;

typedef struct elemMahasiswa *adrMahasiswa;
typedef struct elemTugas *adrTugas;
typedef struct mahasiswa infotypeMhs;
typedef struct tugas infotypeTug;
struct mahasiswa{
    string nama, kelas, jurusan, gender;
    int angkatan;
};
struct tugas{
    string nama, matkul, deadline, kodeMatkul;
};
struct elemMahasiswa {
    infotypeMhs info;
    adrMahasiswa nextMhs;
    adrTugas nextTug;
};
struct elemTugas {
    infotypeTug info;
    adrTugas nextTug;
};
struct ListMahasiswa {
    adrMahasiswa first;
};

void createList(ListMahasiswa &L);
adrMahasiswa createElemenMahasiswa(infotypeMhs x);
adrTugas createElemenTugas(infotypeTug x);
void addMahasiswa(ListMahasiswa &L, adrMahasiswa P); //1
void showMahasiswa(ListMahasiswa L); //2
void deleteMahasiswa(ListMahasiswa &L, adrMahasiswa P); //3
adrMahasiswa searchMahasiswa(ListMahasiswa L, string name); //4
void addTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q); //5
//void connectTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q); //6
void showAll(ListMahasiswa L); //7
adrTugas searchTugas(ListMahasiswa L, string name); //8
void deleteTugas(ListMahasiswa &L, adrTugas P, adrMahasiswa Q); //9
void countTugas(ListMahasiswa &L, adrMahasiswa P); //10

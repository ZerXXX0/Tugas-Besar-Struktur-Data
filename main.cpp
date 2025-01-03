#include <iostream>
#include "mll.h"

using namespace std;

int main()
{
    /*
    Muhammad Ghozy Abdurrahman
    Athallah Fairuz Javier

    Javier is here
    Ghozy is here
    */

    //Variables declaration
    ListMahasiswa L;
    adrMahasiswa P;
    adrTugas Q;
    infotypeMhs x;
    infotypeTug y;

    //Creating list
    createList(L);

    //Interface
    int choice;
    do {
        cout << "\n==============================\n";
        cout << "     Student Management\n";
        cout << "==============================\n";
        cout << "1. Add Student\n";
        cout << "2. Add Assignment to Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Print All Students\n";
        cout << "5. Search for a Student\n";
        cout << "6. Print All Student and Assignment\n";
        cout << "7. Search for an Assignment\n";
        cout << "8. Delete an Assignment\n";
        cout << "9. Count Assignment\n";
        cout << "0. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice (0-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                string nama, kelas, jurusan, gender;
                int angkatan;

                cout << "Enter name: ";
                cin >> x.nama;
                cout << "Enter class: ";
                cin >> x.kelas;
                cout << "Enter jurusan: ";
                cin >> x.jurusan;
                cout << "Enter angkatan: ";
                cin >> x.angkatan;
                cout << "Enter gender: ";
                cin >> x.gender;

                P = createElemenMahasiswa(x);
                addMahasiswa(L, P);
                break;
                }
            case 2:
                {
                string name;
                cout << "Enter Student's Name: ";
                cin >> name;
                adrMahasiswa P = searchMahasiswa(L, name);

                if (P != nullptr) {
                    string name, matkul, deadline, kodeMatkul;
                    cout << "Enter assignment name: ";
                    cin >> y.name;
                    cout << "Enter subject: ";
                    cin >> y.matkul;
                    cout << "Enter subject code: ";
                    cin >> y.kodeMatkul;
                    cout << "Enter deadline: ";
                    cin >> y.deadline;

                    Q = createElemenTugas(y);
                    addTugas(L, Q, P);
                } else {
                    cout << "Not found";
                }

                break;
                }
            case 3:
                {
                string name;
                cout << "Enter Student's Name: ";
                cin >> name;
                adrMahasiswa P = searchMahasiswa(L, name);

                if (P != nullptr) {
                    deleteMahasiswa(L, P);
                    cout << "Student is deleted";
                } else {
                    cout << "Not found";
                }
                break;
                }
            case 4:
                {
                showMahasiswa(L);
                cout << endl;
                break;
                }
            case 5:
                {
                string name;
                cout << "Enter Student's Name: ";
                cin >> name;
                adrMahasiswa P = searchMahasiswa(L, name);

                if (P != nullptr) {
                    cout << "Student has found" << endl;
                    cout << "Nama: " << info(P).nama << endl;
                    cout << "Kelas: " << info(P).kelas << endl;
                    cout << "Angkatan: " << info(P).angkatan << endl;
                    cout << "Jurusan: " << info(P).jurusan << endl;
                    cout << "Gender: " << info(P).gender << endl;
                } else {
                    cout << "No student has found" << endl;
                }
                break;
                }
            case 6:
                {
                showAll(L);
                cout << endl;
                break;
                }
            case 7:
                {
                string name;
                cout << "Enter Assignment's Name: ";
                cin >> name;
                adrTugas P = searchTugas(L, name);

                if (P != nullptr) {
                    cout << "Assignment has found" << endl;
                    cout << "Nama: " << info(P).nama << endl;
                    cout << "Matkul: " << info(P).matkul << endl;
                    cout << "Deadline: " << info(P).deadline << endl;
                    cout << "Kode Matkul: " << info(P).kodeMatkul << endl;
                } else {
                    cout << "No assignment has found" << endl;
                }
                break;
                }
            case 8:
                {
                string name;
                cout << "Enter Student's Name: ";
                cin >> name;
                adrMahasiswa Q = searchMahasiswa(L, name);

                if (Q != nullptr) {
                    cout << "Enter Assignment's Name: ";
                    cin >> name;
                    adrTugas P = searchTugas(L, name);

                    if (P!=nullptr) {
                        deleteTugas(L, P, Q);
                    } else {
                        cout << "Not found";
                    }
                } else {
                    cout << "Not found";
                }
                break;
                }
            case 9:
                {
                string name;
                cout << "Enter Student's Name: ";
                cin >> name;
                adrMahasiswa P = searchMahasiswa(L, name);

                if (P != nullptr) {
                    countTugas(L, P);
                } else {
                    cout << "Not found";
                }
                break;
                }
            case 0:
                {
                cout << "Exiting the program. Goodbye! Tschuess! Arrivederci! Au Revoir! Adios! Sayonara!" << endl;
                cout << "Wir wuenschen Ihnen einen schoenen Tag!";
                break;
                }
            default:
                {
                cout << "Invalid choice. Please enter a number between 0 and 9.\n";
                }
        }
    } while (choice != 0);
    return 0;
}

/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    Langkah Pratikum ke-I
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    // array a dan b masing-masing memesan memori sebanyak 20 alamat 
    int i, j, a[20], b[20], banyakA, banyakB;

    cout<<"IRISAN & GABUNGAN 2 HIMPUNAN\n";
    cout<<"=============================\n\n";
    cout<<"Masukkan banyaknya anggota himpunan A: ";cin>>banyakA;
    
    // isi anggota A ditampung di array a
    for (i=0; i<banyakA; i++){
        cout<<"Masukkan anggota ke-"<<i+1<<" : ";cin>>a[i];
    }

    cout<<"\nMasukkan banyaknya anggota himpunan B: ";cin>>banyakB;

    // isi anggota B ditampung di array b
    for (i=0; i<banyakB; i++){  
        cout<<"Masukkan anggota ke-"<<i+1<<" : ";cin>>b[i];
    }
    
    // menampilkan isi dari array b  
    cout<<"\nHimpunan B={";
    for (i=0; i<banyakB; i++){
        cout<<b[i]<<",";
    }
    cout<<"}\n";
    
    cout<<"\n\n ----------------------------------  \n";
    cout<<"A irisan B = {";
    for (i=0; i<banyakA; i++){
        for (j=0; j<banyakB; j++){
            // a irisan b berisi anggota dari himpunan a dan b yang sama
            // jika isi dari array a = isi array b, maka tampilkan isi
            if (a[i]==b[j]){
                cout<<a[i]<<" ";
            }
        }
    }
    cout<<"}\n";

    // menampilkan gabungan isi dari array a dan array b
    cout<<"\nA gabungan B = {";
    for (i=0; i<banyakA; i++){
        cout<<a[i]<<" ";
    }
    for (i=0; i<banyakB; i++){
        cout<<b[i]<<" ";
    }
    cout<<"}\n";

    cout<<"\n\nTekan sembarang untuk keluar..."; getch();
    return 0;
}


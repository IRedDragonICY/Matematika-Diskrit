/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    Langkah Pratikum Pertemuan ke-II
*/

#include <iostream>
using namespace std;

int main(){
    string a[] = {"changmin","Jaejoong"};
    string b[] = {"f8291","n4810","b0637"};

    int c[] = {2, 3, 4};
    int d[] = {2, 4, 8, 10, 12};

    cout << "Hasil penggabungan a dan b adalah : \n{";
    for (int i = 0; i < 2;){
        for (int j = 0; j < 3; j++){
            cout << "(" << a[i] << "," << b[j] << ")";
        }
        i++;
    }
    cout << "}" << endl;

    cout << "Hasil himpunan c habis membagi d : \n{";
    for (int k = 0; k < 3;){
        for (int i = 0; i < 5; i++){
            if (d[i] % c[k] == 0){
                cout << "(" << c[k] << "," << d[i] << "),";
            }
        }
        k++;
    }
    cout << "}" << endl;
    return 0;
}
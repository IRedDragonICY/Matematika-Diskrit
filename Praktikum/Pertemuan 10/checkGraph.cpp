#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    bool ketemu, nolsemua;
    // [1] Inisialisasi matriks dengan ukuran 10x10 dan variabel lainnya. Matriks ini akan digunakan untuk merepresentasikan graf. Variabel i, j, jumlah_simpul, jumlah_sisi, asal, dan tujuan digunakan untuk iterasi dan input pengguna.
    int matrix[10][10];
    int i, j, jumlah_simpul, jumlah_sisi, asal, tujuan;

    // inisialisasi
    cout << "jumlah simpul: ";
    cin >> jumlah_simpul;
    cout << "jumlah sisi: ";
    cin >> jumlah_sisi;

    for (i = 1; i <= jumlah_simpul; i++) {
        for (j = 1; j <= jumlah_simpul; j++) {
            matrix[i][j] = 0;
        }
    }
    // [2] Bagian ini mengisi matriks berdasarkan input pengguna. Pengguna memasukkan simpul asal dan tujuan, dan matriks diisi dengan angka 1 pada posisi tersebut. Ini menunjukkan bahwa ada sisi antara simpul asal dan tujuan.
    // isi matrix sesuai input graf
    for (i = 1; i <= jumlah_sisi; i++) {
        cout << "simpul asal: ";
        cin >> asal;
        cout << "simpul tujuan: ";
        cin >> tujuan;
        matrix[asal][tujuan] = 1;
        // [3]  Karena ini adalah graf tidak berarah, maka jika ada sisi dari simpul asal ke tujuan, maka juga ada sisi dari tujuan ke asal. Oleh karena itu, matriks diisi dengan angka 1 pada posisi tersebut.
        matrix[tujuan][asal] = 1;
    }

    // telusuri graf
    i = 1;
    nolsemua = false;

    while (i <= jumlah_simpul && !nolsemua) { // [4] Bagian ini menelusuri graf untuk mengecek apakah graf tersebut terhubung atau tidak. Jika semua simpul dalam graf terhubung, maka graf tersebut dianggap terhubung. Jika ada setidaknya satu simpul yang tidak terhubung dengan simpul lain, maka graf tersebut dianggap tidak terhubung.
        j = 1;
        ketemu = false;
        while (j <= jumlah_simpul && !ketemu) {
            if (matrix[i][j] == 1) {
                ketemu = true;
            } else {
                j++;
            }
        }
        if (!ketemu) {
            nolsemua = true;
        } else {
            i++;
        }
    }

    if (nolsemua) {
        cout << "graf tidak terhubung";
    } else {
        cout << "graf terhubung";
    }

    getch();
    return 0;
}
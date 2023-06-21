#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
    char kata1, kata2, kata3, kata4;
    int a, b, c, d;

    cout << "Masukkan titik pertama: ";
    cin >> kata1;
    cout << endl;

    cout << "Masukkan titik kedua: ";
    cin >> kata2;
    cout << endl;

    cout << "Masukkan titik ketiga: ";
    cin >> kata3;
    cout << endl;

    cout << "Masukkan titik keempat: ";
    cin >> kata4;
    cout << endl;

    cout << "Garis yang dapat dibentuk adalah: " << endl;
    cout << kata1 << kata4 << endl;
    cout << kata4 << kata3 << endl;
    cout << kata3 << kata2 << endl;
    cout << kata2 << kata1 << endl << endl;

    cout << "Masukkan jarak antara titik simpul " << kata1 << " dengan " << kata4 << " : ";
    cin >> a;
    cout << "Masukkan jarak antara titik simpul " << kata4 << " dengan " << kata3 << " : ";
    cin >> b;
    cout << "Masukkan jarak antara titik simpul " << kata3 << " dengan " << kata2 << " : ";
    cin >> c;
    cout << "Masukkan jarak antara titik simpul " << kata2 << " dengan " << kata1 << " : ";
    cin >> d;
    cout << endl << endl;

    cout << "Jadi panjang jarak totalnya = " << a+b+c+d << endl << endl;

    cout << "Mencari jalur terpendek dari " << kata1 << " menuju " << kata3 << " -> " << kata4 << " : " << endl;
    cout << "Alternatif pertama: " << kata1 << " -> " << kata2 << " -> " << kata3 << " -> " << kata4 << " = " << kata1 << kata2 << " + " << kata2 << kata3 << kata4 << endl;

    system("color f0");
    system("PAUSE");
    return EXIT_SUCCESS;
}

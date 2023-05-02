/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    Post Test Praktikum ke-V
*/
/*
Buatlah Program Menentukan Faktorial dari sebuah inputan, dengan ketentuan :
● Program bersifat dinamis
● Menggunakan Perulangan Iteratif dan Rekursif
dalam proses faktorial
● User bisa memlih dalam program nantinya mau
menggunakan faktorial mode Iteratif atau
Rekursif
● Buat programnya, dan jelaskan programnya dalam bentuk Pdf beserta screenshoot
*/

// Menggunakan OOP dengan pembagian kelas-kelas:
// 1. Faktorial - untuk melakukan perhitungan faktorial
// 2. UserInterface - sebagai penghubung antara kelas Faktorial dan main program

#include <iostream>
#include <unistd.h>

using namespace std;

// Kelas Faktorial
class Faktorial {
private:
int result;

public:
// Konstruktor yang menginisialisasi nilai awal result = 1
Faktorial() {
result = 1;
}

// Metode untuk menampilkan langkah-langkah dalam perhitungan iteratif
void showStepIterativeMethod(int number) {
    int resultTemp = 1;

    for (int i = 1; i <= number; i++) {
        cout << "int iterativeMethod(int " << number << ") {" << endl;
        cout << "    int result = 1;" << endl;
        cout << "    for(int i = 1; i <= " << number << "; i++) {" << endl;
        cout << "        result *= i;" << endl;
        cout << "    }" << endl;
        cout << "    return result;" << endl;
        cout << "}" << endl << endl;
        
        // Menampilkan penjelasan setiap langkah pada perulangan iteratif
        cout << "Penjelasan:" << endl;
        cout << "Perulangan iteratif ke-" << i << endl;
        cout << "Nilai i = " << i << endl;
        resultTemp *= i;
        cout << "result = " << resultTemp;
        sleep(2);
        system("cls");
    }
}

// Metode untuk melakukan perhitungan faktorial secara iteratif
void iterativeMethod(int number) {
    showStepIterativeMethod(number);
    
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
}

// Metode untuk menampilkan langkah-langkah dalam perhitungan rekursif
void showStepRecursiveMethod(int number) {
    cout << "int recursiveMethod(int " << number << ") {" << endl;
    cout << "    if(" << number << " == 1) {" << endl;
    cout << "        return 1;" << endl;
    cout << "    }" << endl;
    cout << "    result = " << number << " * recursiveMethod(" << number << " - 1);" << endl;
    cout << "    return result;" << endl;
    cout << "}" << endl << endl;

    // Menampilkan penjelasan setiap langkah pada perulangan rekursif
    cout << "Penjelasan:" << endl;
    if (number == 1) {
        cout << "Karena " << number << " == 1 maka akan mengeksekusi" << endl;
        cout << "return 1;" << endl;
    }
    else {
        cout << "Karena " << number << " != 1 maka akan mengeksekusi" << endl;
        cout << "return " << number << " * recursiveMethod(" << number << " - 1);" << endl;
    }
    sleep(2);
    system("cls");
}

// Metode untuk melakukan perhitungan faktorial secara rekursif
int recursiveMethod(int number) {
    showStepRecursiveMethod(number);
    if (number == 1) {
        return 1;
    }
    result = number * recursiveMethod(number - 1);
    return result;
}

// Getter untuk mengambil nilai dari variabel result
int getResult() {
    return result;
}
};

// Kelas UserInterface
class UserInterface {
private:
int number;
bool isMethodIterative;
Faktorial faktorial;

public:
// Konstruktor untuk mengambil input dari user dan menentukan metode perhitungan faktorial yang dipilih
UserInterface() {
cout << "n!" << endl;
cout << "Masukkan bilangan n : ";
cin >> number;

    isMethodIterative = menuMethod();
    
    if (isMethodIterative) {
        faktorial.iterativeMethod(number);
    }
    else {
        faktorial.recursiveMethod(number);
    }

    printResult();
    restartProgram();
}

// Metode untuk menampilkan pilihan metode perhitungan faktorial kepada user
bool menuMethod() {
    int choice;
    cout << "Pilih metode perhitungan : " << endl;
    cout << "1. Iteratif" << endl;
    cout << "2. Rekursif" << endl;
    cout << "Masukkan pilihan : ";
    cin >> choice;
    system("cls");

    if (choice == 1) {
        return true;
    }
    else if (choice == 2) {
        return false;
    }
    else {
        cout << "Pilihan tidak tersedia" << endl;
        menuMethod();
    }

    return false;
}

// Metode untuk menampilkan hasil perhitungan faktorial dan penjelasannya
void printResult() {
    cout << number << "! = ";
    for (int i = number; i > 0; i--) {
        cout << i;
        if (i != 1) {
            cout << "x";
        }
    }
    cout << endl << endl;
    cout << "Jadi, hasil faktorial dari " << number << " adalah " << faktorial.getResult();
}

// Metode untuk meminta input user apakah ingin mengulang program atau tidak
void restartProgram() {
    char choice;
    cout << endl << endl;
    cout << "Apakah anda ingin mengulang program? (y/n) : ";
    cin >> choice;

    switch (choice) {
        case 'Y':
        case 'y':
            system("cls");
            UserInterface();
            break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Pilihan tidak tersedia";
            break;
    }
}
};

// Main program
int main() {
    UserInterface ui;
    return 0;
}

// Penjelasan kode:
// 1. Dilakukan pembagian kelas-kelas yaitu Faktorial dan UserInterface untuk memisahkan fungsi-fungsi yang berbeda
// 2. Kelas Faktorial memiliki metode iterativeMethod() dan recursiveMethod() yang digunakan untuk melakukan perhitungan faktorial baik secara iteratif atau rekursif
// 3. Kelas UserInterface digunakan untuk mengambil input dari user, menampilkan pilihan metode perhitungan faktorial, dan menampilkan hasil perhitungan beserta penjelasannya
// 4. Dalam kelas UserInterface, terdapat metode menuMethod() yang digunakan untuk menampilkan pilihan metode perhitungan faktorial kepada user dan mengembalikan nilai true jika user memilih metode iteratif atau false jika user memilih metode rekursif
// 5. Setelah selesai melakukan perhitungan faktorial, program akan meminta input user apakah ingin mengulang program atau tidak
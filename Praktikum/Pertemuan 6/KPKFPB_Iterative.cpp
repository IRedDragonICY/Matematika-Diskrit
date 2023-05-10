#include <iostream>

using namespace std;

class Math {
public:
    // Algoritma Brute Force
    // int getKPK(int num1, int num2) {
    //     if (i % num1 == 0 && i % num2 == 0) {
    //         return i;
    //     }
    //     return getKPK(num1, num2);
    // }

    // int getFPB(int num1, int num2) {
    //     if (num2 == 0) {
    //         return num1;
    //     } else {
    //         return getFPB(num2, num1 % num2);
    //     }
    // }
    // Algoritma Euclidean
    int getKPK(int num1, int num2) {
        int fpb = getFPB(num1, num2);
        return (num1 * num2) / fpb;
    }

    int getFPB(int num1, int num2) {
        while (num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
};

class Menu {
public:
    int displayMenu() {
        int choice;
        cout << "Masukkan pilihan anda:" << endl
             << "1. Menentukan KPK" << endl
             << "2. Menentukan FPB" << endl
             << "3. Keluar" << endl
             << "> ";
        cin >> choice;
        return choice;
    }
    void inputNum(int& num1, int& num2) {
        cout << "Masukkan bilangan pertama: ";
        cin >> num1;
        cout << "Masukkan bilangan kedua: ";
        cin >> num2;
    }
    void pressEnterToContinue() {
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }
};

class Program {
public:
    void run() {
        Math math;
        Menu menu;
        int choice;
        int num1, num2;

        while (true) {
            system("cls");
            choice = menu.displayMenu();

            system("cls");
            switch (choice) {
            case 1:
                cout << "Menentukan KPK" << endl;
                menu.inputNum(num1, num2);

                cout << "Bilangan pertama: " << num1 << endl;
                cout << "Bilangan kedua  : " << num2 << endl;
                cout << "KPK: " << math.getKPK(num1, num2) << endl;
                break;

            case 2:
                cout << "Menentukan FPB" << endl;
                menu.inputNum(num1, num2);

                cout << "Bilangan pertama: " << num1 << endl;
                cout << "Bilangan kedua: " << num2 << endl;
                cout << "FPB: " << math.getFPB(num1, num2) << endl;
                break;

            case 3:
                cout << "Keluar dari program..." << endl;
                return;

            default:
                cout << "Pilihan tidak valid!" << endl;
            }

            menu.pressEnterToContinue();
        }
    }
};

int main() {
    Program program;
    program.run();
    return 0;
}
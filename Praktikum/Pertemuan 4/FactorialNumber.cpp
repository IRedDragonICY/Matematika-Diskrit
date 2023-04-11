/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    POST TEST ke-IV
*/

#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

// deklarasi class Number
class Number {
    private:
        int n;
    public:
        float result;  

        // fungsi untuk menginputkan nilai n
        void input() {
            cout << "Masukkan Nilai n : ";
            cin >> n;
        }

        // fungsi perhitungan faktorial
        int calcFactorial(int n) {
            result = 1;
            for(int i = 1; i <= n; i++){
                result *= i;
            }
            return result;   
        }

        // fungsi untuk menampilkan perhitungan faktorial
        void showFactorial(int n){
            cout << n << "! = ";
            for (int i = n; i > 0; i--) {
                if (i == 1)
                    cout << i << " = ";
                else 
                    cout << i << " x ";
            }
            cout << calcFactorial(n) << endl;
        }

        // fungsi untuk menampilkan hasil faktorial
        void outputFactorial() {
            cout << "Jadi hasil dari Faktorial (" << n << ") adalah " << result << endl;
        }

        // fungsi recursive untuk menghitung bilangan fibonacci
        int checkFibonacci(int n) {
            if (n == 0 || n == 1) {
                return n;
            } else {
                return checkFibonacci(n-1) + checkFibonacci(n-2);
            }
        }

        // fungsi untuk menampilkan urutan bilangan fibonacci
        void showFibonacci(int n) {
            int fib[3] = {0, 1, 0};
            int pascalArr[n+1][n+1];
            cout << "Bilangan fibonacci ke-" << n << " adalah " << checkFibonacci(n-1) << endl;

            // membuat segitiga pascal
            for(int i=0; i<n; i++){

                fib[2] = fib[0] + fib[1];
                fib[0] = fib[1];
                fib[1] = fib[2];

                for (int j = 0; j < n-i; j++) {
                    cout << "  ";
                }

                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i)
                        pascalArr[i][j] = 1;
                    else 
                        pascalArr[i][j] = pascalArr[i-1][j-1] + pascalArr[i-1][j];
                    cout << setw(3) << pascalArr[i][j] << " ";
                }
                cout << endl;
            }

            // menampilkan hasil bilangan fibonacci
            fib[0] = 0;
            fib[1] = 1;
            fib[2] = 0;

            cout << "Fibonacci("<< n << ") = ";
            for (int i = 0; i < n; i++) {
                if (i == n-1)
                    cout << fib[0] << " = ";
                else 
                    cout << fib[0] << " + ";
                result += fib[0];
                fib[2] = fib[0] + fib[1];
                fib[0] = fib[1];
                fib[1] = fib[2];
            }
            cout << result << endl;
        }

        // fungsi untuk menampilkan hasil bilangan fibonacci
        void outputFibonacci(){
            cout << "Jadi hasil dari Fibonacci (" << n << ") adalah " << result << endl;
        }

        // fungsi untuk menjalankan fungsi perhitungan faktorial
        void Factorial() {
            input();
            result = calcFactorial(n);
            showFactorial(n);
            outputFactorial();
        }

        // fungsi untuk menjalankan fungsi bilangan fibonacci
        void Fibonacci() {
            input();
            showFibonacci(n);
            outputFibonacci();
        }
};

// deklarasi objek num dengan class Number
Number num;

// deklarasi class Menu untuk menampilkan menu program
class Menu {
private:
    int choice;

public:
    // fungsi untuk menampilkan dan mendapatkan pilihan user
    void input() {
        const int NUM_MENU_ITEMS = 3;
        bool isUserSelectingMenu = true;
        int selectedMenuItem = 1;
      
        while (isUserSelectingMenu) {
            system("cls");
            num.result = 0;

            cout << "+------------------------+" << endl;
            
            for (int indexMenu = 1; indexMenu <= NUM_MENU_ITEMS; indexMenu++) {
                if (indexMenu == selectedMenuItem)
                    cout << "| > ";
                else 
                    cout << "|   ";

                switch (indexMenu) {
                    case 1:
                        cout << "Faktorial (n!)       "; break;
                    case 2:
                        cout << "Fibonacci (n)        "; break;
                    case 3:
                        cout << "Exit                 "; break;
                }

                cout << "|" << endl;
            }
      
            cout << "+------------------------+" << endl;

            char input = getch();

            switch (input) {
                case 72: // up arrow
                    selectedMenuItem--;
                    if (selectedMenuItem < 1)
                        selectedMenuItem = NUM_MENU_ITEMS;
                    break;
                case 80: // down arrow
                    selectedMenuItem++;
                    if (selectedMenuItem > NUM_MENU_ITEMS)
                        selectedMenuItem = 1;
                    break;
                case 13: // enter
                    isUserSelectingMenu = false;
                    system("cls");

                    if (selectedMenuItem == 1)
                        num.Factorial();
                    if (selectedMenuItem == 2)
                        num.Fibonacci();
                    if (selectedMenuItem == 3)
                        exit(0);
                    break;
            }
        }
        
        cout << "\nTekan tombol apapun untuk kembali ke menu...";
        getch();
        return input();
    }
};

// deklarasi objek m dengan class Menu
Menu m;

// fungsi utama
int main() {
    m.input();
    return 0;
}
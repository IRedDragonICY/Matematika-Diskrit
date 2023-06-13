#include <iostream>
using namespace std;


int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

bool isValid(int n, int r) {
    if (r > n) {
        cout << "\nNilai r harus kurang dari n";
        return false;
    }
    if (n < 0 || r < 0) {
        cout << "\nNilai n dan r harus positif";
        return false;
    }
    return true;
}

void getInput(int &n, int &r) {
    cout << "\nMasukkan nilai n: "; cin >> n;
    cout << "Masukkan nilai r: "; cin >> r;
    if (!isValid(n, r)) getInput(n, r);
}

void permutation(int n, int r) {
    int result = factorial(n) / factorial(n - r);
    cout << "\nMaka Hasil permutasi: " << result << "\n\n";
}

void combination(int n, int r) {
    int result = factorial(n) / (factorial(r) * factorial(n - r));
    cout << "\nMaka hasil kombinasi: " << result << "\n\n";
}

void choose() {
    system("cls");
    int choice, n, r;
    bool isUseStep;
    cout << "\n1. Permutasi\n2. kombinasi\n3. Keluar";
    cout << "\n\npilihan anda : ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\n\nPermutasi\n\n";
            getInput(n, r);
            permutation(n, r);
            break;
        case 2:
            getInput(n, r);
            cout << "\n\nKombinasi\n\n";
            combination(n, r);
            break;
        case 3:
            cout << "\n\n***selesai***\n\n";
            break;
        default:
            cout << "\n\nPilihan tidak tersedia\n\n";
            system("pause");
            choose();
            break;
    }
    system("pause");system("cls");
    choose();
}

int main() {
    choose();
    return 0;
}
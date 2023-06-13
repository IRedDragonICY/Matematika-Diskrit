#include <cstdlib>
#include <iostream>
using namespace std;

class Madis {
public:
    void pilih(); // pendeklarasian fungsi pilihan
    void permutasi(); // pendeklarasian fungsi permutasi
    void kombinasi(); // pendeklarasian fungsi kombinasi
    int fak(int n); // pendeklarasian fungsi faktorial

private:
    int q[100];
};

void Madis::pilih() {
    int n;
    cout << "\n1. Permutasi\n2. kombinasi";
    cout << "\n\npilihan anda : ";
    cin >> n;
    if (n == 1)
        permutasi();
    if (n == 2)
        kombinasi();
    else
        cout << "\n\n***selesai***\n\n";
}

void Madis::permutasi() {
    int n, N, k, K, p;
    cout << "\nMasukkan nilai n="; cin >> n;
    cout << "Masukkan nilai r="; cin >> k;
    if (k > n) {
        cout << "\nNilai r harus kurang dari n";
        permutasi();
    }
    p = n - k;
    N = fak(n);
    K = fak(p);
    cout << "\nMaka hasil permutasi : " << N / K;
    cout << "\n\n";
    pilih();
}
void Madis::kombinasi() {
    int n, N = 1, k, K = 1, p, P = 1;
    cout << "\nMasukkan nilai n="; cin >> n;
    cout << "Masukkan nilai r="; cin >> k;
    if (k > n) {
        cout << "\nNilai r harus kurang dari n";
        kombinasi();
    }
    p = n - k;
    N = fak(n);
    K = fak(k);
    cout << "\n(nr)!-> ";
    P = fak(p);
    cout << "\nMaka hasil kombinasi : " << N / (K * P);
    cout << "\n\n";
    pilih();
}
/*
Rumus:
Permutasi = n!/(n-r)!
Kombinasi = n!/(r!(n-r)!)
*/

int Madis::fak(int n) {
    if (n<=1)
        return 1;
    else
        return n * fak(n - 1);
}

int main(int argc, char *argv[]) {
    Madis z;
    z.pilih();
    system("PAUSE");
    return EXIT_SUCCESS;
}

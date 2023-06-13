#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int hasil;

// Fungsi faktorial :
int faktorial(int nilai)
{
    hasil = nilai;
    // [1] Menggunakan perulangan untuk menghitung nilai faktorial
    while (nilai > 1)
    {
        hasil = hasil * (nilai - 1);    
        nilai = nilai - 1;
    }
    return hasil;
}

int main()
{
    int p, nq, max, x, i, j, n, k, r, s, tr, no;
    int a[100];

    div_t xx;

    // [2] Menginisialisasi array a dengan nilai 0
    for (i = 0; i < 100; i++)
    {
        a[i] = 0;
    }

    // Tampilan pembuka
    printf("--------------------------\nPROGRAM GENERATE PERMUTASI\n\n");
    printf(" Oleh Moh. Farid Hendianto \n");
    printf("--------------------------\n");

    // input nilai n (jumlah data <maksimal 100>)
    printf("Masukkan nilai n : ");
    scanf("%d", &n);

    // input data ke dalam array
    for (i = 1; i <= n; i++) // ulangi untuk semua data hingga data ke-n
    {
        printf("Masukkan nilai himpunan a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    // input nilai r
    printf("\nNilai r: ");
    scanf("%d", &tr);

    // hitung nilai permutasi
    p = faktorial(n); // [3] Menghitung nilai faktorial dari n

    nq = faktorial(n - tr);

    if (nq == 0)
    {
        nq = 1;
    }

    max = p / nq;

    printf("\nNilai permutasi: %d\nTekan Enter untuk melihat hasil generate permutasi...\n", max);
    getch(); // fungsi membaca karakter keyboard

    no = 1; // variabel untuk menampilkan nomor

    // men-generate permutasi dengan algoritma generate next-permutation
    // generate sebanyak nilai permutasi
    for (x = 1; x <= max; x++)
    {
        printf("%3d. ", no);
        for (i = 1; i <= tr; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        no++;

        j = n - 1;

        while (a[j] > a[j + 1])
        {
            j = j - 1; // j adalah subcript terbesar dengan aj < aj+1
        }

        k = n;

        while (a[j] > a[k])
        {
            k = k - 1; // ak adalah integer terkecil dan lebih besar dari aj
        }

        // tukar aj dan ak
        i = a[k];   // [4] Menyimpan nilai a[k] ke dalam variabel i
        a[k] = a[j];
        a[j] = i;

        r = n;
        s = j + 1;

        while (r > s)
        {
            // tukar ar dan as
            i = a[r]; 
            // [5] Menukar nilai a[r] dan a[s]
            a[r] = a[s];
            a[s] = i;

            r = r - 1;
            s = s + 1;
        }
    }

    getch();
}
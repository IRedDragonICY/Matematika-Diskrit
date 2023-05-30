#include <iostream>
#include <conio.h> 
using namespace std; // Menambahkan libary using namespace std agar membutuhkan std:: pada setiap perintah contohnya std::cout

/*void*/int main(){ // Menggantikan void dengan int karena fungsi main harus mengembalikan nilai
    int x,a,b;
    char i;
    {
        // menukar posisi b=1 dengan il:/*clrscr()*/ system("cls"); karena b=1 tidak digunakan
        
        il:/*clrscr()*/ system("cls"); // mengganti clrscr() karena bukan merupakan fungsi standar pada c++
        b=1;
        cout<<"Masukkan Bilangan untuk di Cek : ";cin >>x;
        for (a=2;a<=x-1;a++){
            if (x%a==0){
                b=0;
                break;
            }
        }
        if (x==1){
            b=0;    // menambahkan b=0 karena 1 bukan merupakan bilangan prima
        }


        if (b==1){
            cout<<"merupakan Bilangan Prima";
        }
        else{
            cout<<"bukan merupakan Bilangan Prima";
        }

    }
    if (b==0)
        cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Ulangi (y/n) ? ";cin>>i;
    if (i=='y'){
        goto il;
    }
    else
        cout<<"Terima Kasih";
}
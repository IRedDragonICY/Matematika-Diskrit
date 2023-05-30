#include <iostream>
#include <conio.h> 
using namespace std;

int main(){ 
    int x,a,b;
    char i;
    {
        il:system("cls");
        b=1;
        cout<<"Masukkan Bilangan untuk di Cek : ";cin >>x;
        
        for (a=2;a<=x-1;a++){
            if (x%a==0){
                b=0;
                break;
            }
        }
        if (x==1){
            b=0;
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
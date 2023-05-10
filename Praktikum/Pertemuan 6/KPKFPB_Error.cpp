#include <iostream>
Using namespace std;

main(){
    clrscr();
    int a,b,c,d;
    int p;
    int faktor1,faktor2,kpk,fpb;

    cout<<”Masukan Pilihan anda ?\n”;
    cout<<”1. Menentukan KPK\n”;
    cout<<”2. Menentukan FPB\n”;
    cout<<”3. Exit\n”;
    cin>>p;

    switch (p){
        case 1:
            cout<<”Menghitung KPK\n”;
            cout<<”Masukan Bilangan Pertama : \n”;
            cin>>a;
            cout<<”Masukan Bilangan Kedua : \n”;
            cin>>b;
            if (a>b)
            if (a%b){
                for(c=0;c<=a;c++){
                    if(a%c); //lanjutkan
                    else
                        faktor1=c;
                }
                for(d=0;d<=b;d++){
                    b%d;
                    if (b%d);
                    //lanjutkan
                    else
                        faktor2=d;
                }
            }
            else
                kpk=a;
            else if (b%a){
                for(d=0;d<=a;d++){
                    if(b%d);
                    //lanjutkan
                    else
                        faktor1=d;
                }
                for(c=0;c<=b;c++){
                    if (a%c);
                    //lanjutkan
                    else
                        faktor2=c;
                    }
                }
            else
                kpk=b;
                fpb=faktor1*faktor2;
                cout<<”Bilangan pertama :”<<endl;
                cout<<”Bilangan kedua :”<<endl;
                cout<<”KPK :”<<
            break;
            break;
    case 2:
        cout<<”Menghitung FPB\n”;
        cout<<”Masukan Bilangan pertama : \n”;
        cin>>a;
        cout<<”Masukan bilangan kedua : \n”;
        cin>>b;
        if (a
        if (b%a){
            for(c=0;c>=a;c–-){
                if(c%a);//lanjutkan
                else
                    faktor1=c;
                }
            for(d=0;d>=b;d-–){
                b%d;
                if (d%b);//lanjutkan
                else faktor2=d;
            }
            for(c=0;c>=b;c-–){
                if (c%a);//lanjutkan
                else
                    \faktor1=c;
        }
        }
        else
        fpb=b;
        fpb=faktor1*faktor2;
        cout<<”Bilangan pertama :”<<
        cout<<”Bilangan kedua :”<<
        cout<<”FPB :”<<
        break;
        case 3:
        cout<<”Exit Now !!!\n”;
        break;
        default:
        cout<<”Error !!!”;
        } getch();
        return 0;
}
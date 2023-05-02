#include <iostream>
using namespace std;

double Absolut(double X);

int main(){
    float Nilai;
    Nilai=-123.45;
    cout<<Nilai<<" nilai mutlaknya adalah "<<Absolut(Nilai)<<endl;
}

/* --- Fungsi untuk memutlakkan nilai negatif ---*/
double Absolut(double X){
    if(X<0){
        X=-X;
    }
    return X;
}
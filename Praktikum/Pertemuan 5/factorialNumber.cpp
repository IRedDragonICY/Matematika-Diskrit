#include <stdio.h>
long int Fak_Rekursif (int N);

main(){
    int N;N=5;
    printf("%d faktorial = %ld\n",N,Fak_Rekursif(N));
}

long int Fak_Rekursif (int N){
    if (N<=1)
        return 1;
    else 
        return N*Fak_Rekursif(N-1);
        
}
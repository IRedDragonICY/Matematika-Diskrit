/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    Post Test Pertemuan ke-II
*/

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <conio.h>
#define maxSets 100
#define maxElements 100
using namespace std;

// struct of Sets
struct{
    string Name;
    int totalElements;
    bool typeElements; // if true = int, if false = string
    int intElements[maxElements]; 
    string stringElements[maxElements];
}Sets[maxSets];
int totalSets;

// function to check the type of Elements in Sets
void numberingNameSets(int totalSets){
    for (int i=0;i<totalSets;i++){
        for (int j=0;j<26;j++){
            if (i==j){
                Sets[i].Name=char(j+65);
            }
        }
    }
}

// function to input total Elements in Sets
void totalElementsInSets(int i){
    cout<<"=============================="<<endl;
    cout<<"Jumlah elemen pada himpunan "<<Sets[i].Name<<" : ";cin>>Sets[i].totalElements;
    cout<<"=============================="<<endl;
}

// function to input Elements in Sets
void inputSets(){
    cout<<"Masukkan jumlah himpunan : ";cin>>totalSets;
    numberingNameSets(totalSets);
    for(int i=0;i<totalSets;i++){
        cout<<"1 = int"<<endl;
        cout<<"0 = string"<<endl;
        cout<<"Masukkan tipe data pada himpunan : ";cin>>Sets[i].typeElements;
        if (Sets[i].typeElements==true){
            totalElementsInSets(i);
            for(int j=0;j<Sets[i].totalElements;j++){
                cout<<"Elemen "<<j+1<<" pada himpunan "<<Sets[i].Name<<" : ";
                cin>>Sets[i].intElements[j];
            }
        }
        else{
            totalElementsInSets(i);
            for(int j=0;j<Sets[i].totalElements;j++){
                cout<<"Elemen "<<j+1<<" pada himpunan "<<Sets[i].Name<<" : ";
                if (j==0)
                    cin.ignore();
                getline(cin,Sets[i].stringElements[j]);
                cout<<"=============================="<<endl;
            }
        }
    }
}

// default value of Sets for Praktikum Matematika Diskrit soal no 2
void defaultSets(){
    totalSets = 2;
    Sets[0]= {"c", 3,true,{2,3,4},{} };
    Sets[1]= {"d", 5,true,{2,4,8,10,12},{}};
}

// function to print Elements in Sets
void selectInputUser(){
    bool isSelected[] = {true, false};
    bool isUserSelecting = true;
    while (isUserSelecting){
        system("cls");
        cout << "Pilih himpunan apakah ingin diinputkan sendiri atau menggunakan default?" << endl;
        for (int i = 0; i < 2; i++){
            if (isSelected[i])
                cout << "> ";
            else
                cout << "  ";
            if (i == 0)
                cout << "Default" << endl;
            else
                cout << "Manual" << endl;
        }
        switch (getch()){
            case 72:
                if (isSelected[0]){
                    isSelected[0] = false;
                    isSelected[1] = true;
                }
                else{
                    isSelected[0] = true;
                    isSelected[1] = false;
                }
                break;
            case 80:
                if (isSelected[0]){
                    isSelected[0] = false;
                    isSelected[1] = true;
                }
                else{
                    isSelected[0] = true;
                    isSelected[1] = false;
                }
                break;
            case 13:
                system("cls");
                if (isSelected[0]){
                    defaultSets();
                    isUserSelecting = false;
                }
                else{
                    inputSets();
                    isUserSelecting = false;
                }
                break;
        }
    }
}

// function to print Elements in Sets
void sortElements(int totalSets){
    cout<<"Mengecek apakah elemen pada himpunan sudah terurut atau belum . . ."<<endl;
    sleep(2);
    if (is_sorted(Sets[totalSets-1].intElements,Sets[totalSets-1].intElements+Sets[totalSets-1].totalElements)==true){
        cout<<"Elemen sudah terurut"<<endl;return;
    }
    for(int i=0;i<totalSets;i++){
        if (Sets[i].typeElements==true){
            // check if the Elements in Sets is already sorted or not
            if (is_sorted(Sets[i].intElements,Sets[i].intElements+Sets[i].totalElements)==false){
                cout<<"Elemen pada himpunan "<<Sets[i].Name<<" belum berurut"<<endl;
                sort(Sets[i].intElements,Sets[i].intElements+Sets[i].totalElements);
                cout<<"==============================="<<endl;
            }
            sleep(1);
        }
        else{
            // check if the Elements in Sets is already sorted or not
            if (is_sorted(Sets[i].stringElements,Sets[i].stringElements+Sets[i].totalElements)==false){
                cout<<"Elemen pada himpunan "<<Sets[i].Name<<" belum berurut"<<endl;
                sort(Sets[i].stringElements,Sets[i].stringElements+Sets[i].totalElements);
                cout<<"==============================="<<endl;
            }
            sleep(1);
        }
    }
    if (is_sorted(Sets[totalSets-1].intElements,Sets[totalSets-1].intElements+Sets[totalSets-1].totalElements)==true){
        cout<<"Elemen pada himpunan sudah diurutkan"<<endl;
        cout<<"Setelah elemen diurutkan . . "<<endl;
            for (int i=0;i<totalSets;i++){
                cout<<Sets[i].Name<<" = {";
                for (int j=0;j<Sets[i].totalElements;j++){
                    // check terlebih dahulu apakah Elements in Sets adalah int atau string
                    if (Sets[i].typeElements==true){
                        if (j==Sets[i].totalElements-1)
                            cout<<Sets[i].intElements[j];
                        else
                            cout<<Sets[i].intElements[j]<<",";
                    }
                    else{
                        if (j==Sets[i].totalElements-1)
                            cout<<Sets[i].stringElements[j];
                        else
                            cout<<Sets[i].stringElements[j]<<",";
                    }
                }
            cout<<"}"<<endl;
        }    
    }
}

// print list Elements in Sets
void printListElements(int totalSets){
    for (int i=0;i<totalSets;i++){
        if (Sets[i].typeElements==true){
            cout<<"Elemen pada himpunan "<<Sets[i].Name<<" = {";
            for (int j=0;j<Sets[i].totalElements;j++){
                if (j==Sets[i].totalElements-1)
                    cout<<Sets[i].intElements[j];
                else
                    cout<<Sets[i].intElements[j]<<",";
            }
            cout<<"}"<<endl;
        }
        else if (Sets[i].typeElements==false){
            cout<<"Elemen pada himpunan "<<Sets[i].Name<<" = {";
            for (int j=0;j<Sets[i].totalElements;j++){
                if (j==Sets[i].totalElements-1)
                    cout<<Sets[i].stringElements[j];
                else
                    cout<<Sets[i].stringElements[j]<<",";
            }
            cout<<"}"<<endl;
        }
    }
    sortElements(totalSets);
}

// function to print Elements in Sets
void calcRelation(){
    cout << "===================================================" << endl;
    cout << "R adalah relasi gabungan dari antara setiap pasangan" << endl;
    for (int i = 0; i < totalSets; i++){
        for (int j = 0; j < totalSets; j++){
            if (i != j){
                cout << Sets[i].Name << " R " << Sets[j].Name << " = {";
                for (int k = 0; k < Sets[i].totalElements; k++){
                    for (int l = 0; l < Sets[j].totalElements; l++){
                        // check terlebih dahulu apakah Elements in Sets adalah int atau string
                        if (Sets[i].typeElements==true){
                            cout << "(" << Sets[i].intElements[k] << "," << Sets[j].intElements[l] << ")";
                            if (k != Sets[i].totalElements - 1 || l != Sets[j].totalElements - 1){
                                cout << ",";
                            }
                        }
                        else{
                            cout << "(" << Sets[i].stringElements[k] << "," << Sets[j].stringElements[l] << ")";
                            if (k != Sets[i].totalElements - 1 || l != Sets[j].totalElements - 1){
                                cout << ",";
                            }
                        }
                    }
                }
                cout << "}" << endl;
            }
        }
    }
    cout << "===================================================" << endl;
}

void calcDivisible(){
    for (int i = 0; i < totalSets; i++){
        if (Sets[i].typeElements==false){
            cout<<"Beberapa himpunan mungkin bertipe data string, sehingga tidak dapat dibagi . . ."<<endl;
            return;
        }
    }
    for (int i = 0; i < totalSets; i++){
        for (int j = 0; j < totalSets; j++){
            if (i != j){
                cout << Sets[i].Name << " habis membagi " << Sets[j].Name << " = {";
                for (int k = 0; k < Sets[i].totalElements; k++){
                    for (int l = 0; l < Sets[j].totalElements; l++){
                        if (Sets[j].intElements[l] % Sets[i].intElements[k] == 0){
                            cout << "(" << Sets[i].intElements[k] << "," << Sets[j].intElements[l] << ")";
                            if (k != Sets[i].totalElements - 1 || l != Sets[j].totalElements - 1){
                                cout << ",";
                            }
                        }
                    }
                }
                cout << "}" << endl;
            }
        }
    }
    cout << "===================================================" << endl;
}

int main(){
    selectInputUser();
    printListElements(totalSets);
    calcRelation();
    calcDivisible();
    system("pause");
    return 0;
}
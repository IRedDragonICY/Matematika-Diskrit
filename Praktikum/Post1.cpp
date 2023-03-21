/* 
    Nama             : Mohammad Farid Hendianto
    NIM              : 2200018401
    Kelas            : A
    Mata Kuliah      : Matematika Diskrit
    Dosen            : Nur Rochmah Dyah PA, S.T., M.Kom.
    Post Test Praktikum ke-I
*/
// program for find intersection, union and modulus from sets by Ndik OwO

#include <iostream>
#include <algorithm>
#include <unistd.h>
#define maxSets 100
#define maxElements 100
using namespace std;

struct{
    string Name;
    int totalElements;
    int Elements[maxElements];
}Sets[maxSets];
int totalSets;

// title
void title(){
    cout<<"============================================================"<<endl;
    cout<<"Program for find Intersection, Union and Modulus from a Sets"<<endl;
    cout<<"============================================================"<<endl;
}
// Numbering Name Sets A,B,C,...AA,AB,AC,...AAA,AAB,AAC,..., etc
void numberingNameSets(int totalSets){
    for (int i=0;i<totalSets;i++){
        for (int j=0;j<26;j++){
            if (i==j){
                Sets[i].Name=char(j+65);
            }
        }
    }
}

// Input Sets
void inputSets(int totalSets){
    numberingNameSets(totalSets);
   
    for(int i=0;i<totalSets;i++){
        cout<<"=============================="<<endl;
        cout<<"Total Elements in Set "<<Sets[i].Name<<" : ";cin>>Sets[i].totalElements;
        cout<<"=============================="<<endl;
        for(int j=0;j<Sets[i].totalElements;j++){
            cout<<"Elements "<<j+1<<" in set "<<Sets[i].Name<<" : ";
            cin>>Sets[i].Elements[j];
        }
    }
}

// Sorting Elements in Sets
void sortElements(int totalSets){
    cout<<"Checking if the Elements in Sets is already sorted or not . . ."<<endl;
    sleep(2);
    for(int i=0;i<totalSets;i++){
        // check if the Elements in Sets is already sorted or not
        if (is_sorted(Sets[i].Elements,Sets[i].Elements+Sets[i].totalElements)==false){
            cout<<"Elements in Set "<<Sets[i].Name<<" is not sorted"<<endl;
            sort(Sets[i].Elements,Sets[i].Elements+Sets[i].totalElements);
            cout<<"==============================="<<endl;
            cout<<"After Sort the Elements in Sets"<<endl;
            for (int i=0;i<totalSets;i++){
                cout<<Sets[i].Name<<" = {";
                for (int j=0;j<Sets[i].totalElements;j++){
                    if (j==Sets[i].totalElements-1)
                        cout<<Sets[i].Elements[j];
                    else
                        cout<<Sets[i].Elements[j]<<",";
                }
            cout<<"}"<<endl;
            }
            cout<<"==============================="<<endl;

        }
        sleep(1);
    }
    if (is_sorted(Sets[totalSets-1].Elements,Sets[totalSets-1].Elements+Sets[totalSets-1].totalElements)==true){
        cout<<"Elements in Sets is already sorted"<<endl;
    }
}

// print list Elements in Sets
void printListElements(int totalSets){
    cout<<"=============================="<<endl;
    cout<<"List Elements in Sets"<<endl;
    for(int i=0;i<totalSets;i++){
        cout<<Sets[i].Name<<" = {";
        for(int j=0;j<Sets[i].totalElements;j++){
            if (j==Sets[i].totalElements-1)
                cout<<Sets[i].Elements[j];
            else
                cout<<Sets[i].Elements[j]<<",";
        }
        cout<<"}"<<endl;
    }
    cout<<"=============================="<<endl;
    // after sort the Elements in Sets
    sortElements(totalSets);
}

// Calculate Intersection using library algorithm from function set_intersection
void calculateIntersection(int totalSets){
    cout<<"\n=============================="<<endl;
    cout<<"Calculate Intersection"<<endl;
    for(int i=0;i<totalSets;i++){
        for(int j=0;j<totalSets;j++){
           if (i<j){
                int intersection[maxElements];
                int *ptr;
                ptr=set_intersection(Sets[i].Elements,Sets[i].Elements+Sets[i].totalElements,Sets[j].Elements,Sets[j].Elements+Sets[j].totalElements,intersection);
                for (int k=0;k<ptr-intersection;k++){
                    if (k==0){
                        for (int l=0;l<totalSets;l++){
                            if (l==i)
                                cout<<Sets[l].Name;
                            else if (l==j || l>i && l<j)
                                cout<<" n "<<Sets[l].Name;
                        }
                    }
                    if (k==0)
                        cout<<" = {";
                    if (k==ptr-intersection-1)
                        cout<<intersection[k]<<"}"<<endl;
                    else
                        cout<<intersection[k]<<",";
                }
            }
        }
    }
    cout<<"=============================="<<endl;
}

// Calculate Union using library algorithm from function set_union
void calculateUnion(int totalSets)
{
    cout<<"\n=============================="<<endl;
    cout<<"Calculate Union"<<endl;
    for (int i = 0; i < totalSets; i++)
    {
        for (int j = 0; j < totalSets; j++)
        {
            if (i < j)
            {
                int unionSet[maxElements];
                int *ptr;
                ptr = set_union(Sets[i].Elements, Sets[i].Elements + Sets[i].totalElements, Sets[j].Elements, Sets[j].Elements + Sets[j].totalElements, unionSet);
                for (int k = 0; k < ptr - unionSet; k++)
                {
                    if (k == 0)
                    {
                        for (int l = 0; l < totalSets; l++)
                        {
                            if (l == i)
                                cout << Sets[l].Name;
                            else if (l == j || l > i && l < j)
                                cout << " U " << Sets[l].Name;
                        }
                    }
                    if (k == 0)
                        cout << " = {";
                    if (k == ptr - unionSet - 1)
                        cout << unionSet[k] << "}" << endl;
                    else
                        cout << unionSet[k] << ",";
                }
            }
        }
    }
    cout<<"=============================="<<endl;
}

// Calculate modulo using library algorithm from function set_difference
void calculateModulus(int totalSets)
{
    cout<<"\n=============================="<<endl;
    cout<<"Modulus of Sets"<<endl;
    for (int i = 0; i < totalSets; i++)
    {
        for (int j = 0; j < totalSets; j++)
        {
            if (i < j)
            {
                int modulus[maxElements];
                int *ptr;
                ptr = set_difference(Sets[i].Elements, Sets[i].Elements + Sets[i].totalElements, Sets[j].Elements, Sets[j].Elements + Sets[j].totalElements, modulus);
                for (int k = 0; k < ptr - modulus; k++)
                {
                    if (k == 0)
                    {
                        cout << Sets[i].Name << " % " << Sets[j].Name;
                    }
                    if (k == 0)
                        cout << " = {";
                    if (k == ptr - modulus - 1)
                        cout << modulus[k] << "}" << endl;
                    else
                        cout << modulus[k] << ",";
                }
            }
        }
    }
    for (int i = 0; i < totalSets; i++)
    {
        for (int j = 0; j < totalSets; j++)
        {
            if (i < j)
            {
                int modulus[maxElements];
                int *ptr;
                ptr = set_difference(Sets[j].Elements, Sets[j].Elements + Sets[j].totalElements, Sets[i].Elements, Sets[i].Elements + Sets[i].totalElements, modulus);
                for (int k = 0; k < ptr - modulus; k++)
                {
                    if (k == 0)
                    {
                        cout << Sets[j].Name << " % " << Sets[i].Name;
                    }
                    if (k == 0)
                        cout << " = {";
                    if (k == ptr - modulus - 1)
                        cout << modulus[k] << "}" << endl;
                    else
                        cout << modulus[k] << ",";
                }
            }
        }
    }
    cout<<"=============================="<<endl;
}

int main()
{
    title();
    cout<<"Enter total Sets : ";cin>>totalSets;
    inputSets(totalSets);
    printListElements(totalSets);
    calculateIntersection(totalSets);
    calculateUnion(totalSets);
    calculateModulus(totalSets);
    return 0;
}

// Ora Wibu Ora ngoding

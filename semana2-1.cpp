#include<iostream>
#include <vector>

using namespace std;

//cree una funcion eterna, procesos internos que no retornan nada, solo me arregla el arreglo
void insertionSort(vector<int>& perchero){
    int n = perchero.size();
    for(int i=1; i<n; i++){
        int a = perchero[i];
        int b = i - 1;

        while(b>=0 && perchero[b] > a){
            perchero[b+1] = perchero[b];
            b = b - 1;
        }
        perchero[b+1] = a;
    }
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;


    vector<int> vestidos(n);
    for(int i=0; i<n; i++){
        cin>>vestidos[i];
    }

    insertionSort(vestidos);  
    
    int caja1 = vestidos[0];
    int caja2 = vestidos[n-1];
    int result = caja2 - caja1;
    cout<<result<<endl;

    }

    return 0;
}
#include<iostream>
#include <vector>

using namespace std;

/*Primero se crea la funcion interna insertionSort que no nos retorna nada,
solo me ordena el arreglo, luego declare una variable para obtener el tama;o
del vector perchero y cree un bucle que que va a recorrer desde el segundo elemento
hasta el ultimo. Cree otras dos variables, a que guarda el valor del
vector al inicio y b con el indice anterior al del principio, el bucle que
sigue desplaza los elementos en el vector para crear espacios y colocar
a "a" en la posicion correcta en el vector*/

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

/*Defini una variable y un bucle que procesara cada valor y los guardara en n,
declare un vector de tama;o n que guardara los valores y uso el bucle para que
lea los valores de n y almacene los valores en vestidos, luego utilizo
la funcion insertionSort para ordenar el vector vestidos y por ultimo declare 
las variables caja 1 (para asignar el valor mas bajo a vestidos) y caja 2 
(para asignar el valor mas alto a vestidos) y result (Calcula y guarda la 
diferencia entre el valor mas bajo y alto) y por ultimo imprime la diferencia
por pantalla*/
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
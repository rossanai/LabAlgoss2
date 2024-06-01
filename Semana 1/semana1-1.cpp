#include<iostream>
#include <vector>

/*Se definen las variables para luego ejecutarlas en el bucle t-- que en
cada iteracion procesa el numero las cartas, luego se crearon unos vectores
para guardar los valores de las cartas, se creo otro bucle que procesara
los valores y los almacenara en ese vector. luego el vector repetidas guarda el valor
de las cartas que se hayan repetido y el seguido bucle recorre todas las cartas para
ver las veces que aparece cada valor, y por ultimpo se declara una variable
de tipo entero para determinar el valor a imprimir*/

using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){
    int n, k;
    cin>>n;
    cin>>k;

    vector<int> cartas(n);
    for(int i=0; i<n; i++){
        cin>>cartas[i];
    }

    vector<int> repetidas(101, 0);
    for(int rept:cartas){
        repetidas[rept]++;

    }

    int solucion=0;
    for(int i=0; i<101; i++){
        if(repetidas[i]>=k){
            solucion++;
        }
    }

    int fin = (solucion>0)?k-1:n;
      cout<<fin<<endl;

  }             

    return 0;
}
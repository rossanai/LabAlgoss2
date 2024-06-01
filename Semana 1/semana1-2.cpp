#include<iostream>
using namespace std;

/* El programa realizado en clase :).
Este programa funciona por que, por medio de un bucle queremos que lea
los numeros de la terminal de manera continua hasta que se 
ingrese el numero 42 y se cierre el programa
*/
int main(){
   int numeros;
   
   while(true){        
    cin>>numeros;

    if(numeros==42){
        break;
    }
    cout<<numeros<<endl;
    
   }

    return 0;
}
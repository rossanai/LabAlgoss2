#include <iostream>
#include <vector>
using namespace std;

/*Primero se crea la funcion externa merge, la cual nos ayuda a ordenar los 
establoss antes de encontrar la distancia minima. Declare dos variables, las cuales
calcularan el primer y segundo tama;o de los sub vectores, luego declare dos vectores
temporales donde se guardaran los elementos n1 y n2, seguido realice un bucle
que se encarga que los elementos del sub vector se almacenen en L y R para que
puedan ser comparados y fusionados en a. Por ultimo, declare nuevamente otras variables
i, j y k; y realice los bucles para fusionar los dos sub vectores ya ordenados y
mandarlos de vuelta al vector original de forma ordenada.
*/

void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

/*Seguimos con el algoritmo de ordenamiento. En esta parte lo que se realizo fue,
Declare el vector y las variables pertinentes, realice un if para determinar si
el sub vector tiene 1 o 0 elementos (para saber si ya esta ordenado), declare la 
var m para dividir el sub vector en dos mitades y luego se llama la funcion para
ordenarlas. Luego se llama la funcion merge para combinarlas en orden y que
este completamente ordenado*/

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

/*Defini un vector que representa las posiciones de los establos, y dos variables,
una el numero de vacas y la otra la distancia minima. Declare otra var donde se
guarda la posicion del establo donde se coloco la ultima vaca y el contador. Seguido 
comienza un bucle donde recorre todos los establoss y el if comprueba si la distancia
entre el establos actual y el ultimo es almenos una distancia minima, si esa condicion
se cumple se coloca una vaca y si el bucle se termina sin colocar todas las vacas
retorna false, ya que no fue posible colocarlas todas*/

bool siVacas(const vector<int>& establos, int vacas, int distanciamin) {
    int ultimaposc = establos[0];
    int cont = 1; 
    
    for (int i = 1; i < establos.size(); ++i) {
        if (establos[i] - ultimaposc >= distanciamin) {
            ultimaposc = establos[i];
            cont++;
            if (cont == vacas) return true;
        }
    }
    
    return false;
}

/*En esta parte, declare la var N donde se ira guardando el numero total de
establos, luego se llama a mergeSort para que ordene a establos. Declare una var para
la distancia minima, distancia maxima y la mejor distancia encontrada, luego una busqueda
binaria de la distancia minima, donde mid calcula la distancia media entre distanciamini y distanciamaxi
y siVacas verifica si se puede colocar todas las vacas con una distancia minima y por
ultimo retorna mejordistancia si encuentra la mejor distancia encontrada para colocar a todas las vacas
con la distancia minima requerida*/

int mmdistancia(vector<int>& establos, int vacas) {
    int N = establos.size();
    
    mergeSort(establos, 0, N - 1);
    
    int distanciamini = 1; 
    int distanciamaxi = establos[N - 1] - establos[0];
    int mejordistancia = 0;
    
    while (distanciamini <= distanciamaxi) {
        int mid = distanciamini + (distanciamaxi - distanciamini) / 2;
        
        if (siVacas(establos, vacas, mid)) {
            mejordistancia = mid;
            distanciamini = mid + 1;
        } else {
            distanciamaxi = mid - 1;
        }
    }
    
    return mejordistancia;
}

/*Defini una variable que lee el numero de casos t y un bucle que procesara cada
valor para N y para C, luego un vector para guardar las posiciones de los establos
y se llama la funcion mmdistancia para determinar la mayir distancia minima
entre las vacas, por ultimo, imprime el resultado*/
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, C;
        cin >> N >> C;
        
        vector<int> establos(N);
        for (int i = 0; i < N; ++i) {
            cin >> establos[i];
        }
        
        int result = mmdistancia(establos, C);
        cout << result << endl;
    }
    
    return 0;
}
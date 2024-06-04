#include <iostream>
#include <vector>
using namespace std;

/*En este ejercicio usamos nuevamente el algoritmo mergeSort (ya explicado
detalladamente en el primer ejercicio de semana 3) adaptado a lo que nos pide
el ejercicio, en este caso se utilizaron unos vectores adicionales para mantener
los indices originales*/

void merge(vector<long long>& a, vector<long long>& indices, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

   vector<long long> L(n1), R(n2);
   vector<long long> LI(n1), RI(n2);

    for (long long i = 0; i < n1; ++i)
        L[i] = a[left + i], LI[i] = indices[left + i];
    for (long long j = 0; j < n2; ++j)
        R[j] = a[mid + 1 + j], RI[j] = indices[mid + 1 + j];

  
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k] = L[i], indices[k] = LI[i], i++;
        else
            a[k] = R[j], indices[k] = RI[j], j++;
        k++;
    }

   
    while (i < n1) {
        a[k] = L[i], indices[k] = LI[i];
        i++, k++;
    }

    
    while (j < n2) {
        a[k] = R[j], indices[k] = RI[j];
        j++, k++;
    }
}

void mergeSort(vector<long long>& a, vector<long long>& indices, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

         mergeSort(a, indices, left, mid);
        mergeSort(a, indices, mid + 1, right);

        merge(a, indices, left, mid, right);
    }
}

/*Defini una variable y un bucle que procesara cada valor y los guardara en n,
declare dos vectores a para guardar los valores de entradas e indices para mantener
los originales, luego un bucle que lee los valores de entrada y guarda en indices,
se llama la funcion mergeSort para ordenar el vector a y mantener los indices y por
ultimo declar un vector para almacenar el resultado final de cada caso e imprime el resultado*/
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;


        vector<long long> a(n), indices(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            indices[i] = i;
        }
        
        mergeSort(a, indices, 0, n - 1);
        
     vector<long long> result(n);

    for (int i = 0; i < n; ++i) {
    long long count = 0;
    long long score = a[i];
    for (int j = 0; j < n; ++j) {
        if (i != j && score >= a[j]) {
            score += a[j];
            count++;
        }
    }
    result[indices[i]] = count;
}
        
        for (long long i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
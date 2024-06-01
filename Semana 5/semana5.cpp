#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool paso1(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.second.second < b.second.second;
}

/* Se llama y crea la funcion heapsort para ordenar el vector pares
segun la frecuencia de aparicion y la posicion de la primera aparicion utilizando
el algoritmo de ordenamiento. La funcion de heapify es seleccionar un nodo como mayor
y se compara con sus hijos, si uno de sus hijos es mayor que el nodo, se intercambian entre
ellos. Luego la funcion heapsort utiliza a heapify para construir un heap maximo al inicio
y luego ir sacando los elementos uno por uno del heap moviemdo el maximo al final del vector.
Heapsort es capaz de ordenar eficientemente el vector, en este caso la frecuencia desdecnte
y posicion ascedente gracias a la funcion paso 1
*/ 

void heapify(vector<pair<int, pair<int, int>>>& pares, int n, int i) {
    int mayor = i; 
    int izquierda = 2 * i + 1; 
    int derecha = 2 * i + 2; 

    if (izquierda < n && !paso1(pares[izquierda], pares[mayor])) {
        mayor = izquierda;
    }

    if (derecha < n && !paso1(pares[derecha], pares[mayor])) {
        mayor = derecha;
    }

    if (mayor != i) {
        swap(pares[i], pares[mayor]);

        heapify(pares, n, mayor);
    }
}


void heapSort(vector<pair<int, pair<int, int>>>& pares) {
    int n = pares.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(pares, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(pares[0], pares[i]);

        heapify(pares, i, 0);
    }
}

int main() {
    int N, C;
    cin >> N >> C;
    vector<pair<int, pair<int, int>>> pares;

    for (int i = 0; i < N; ++i) {
        int guardar;
        cin >> guardar;
        bool verificar = false;
        for (auto& buscar : pares) {
            if (buscar.first == guardar) {
                buscar.second.first++;
                verificar = true;
                break;
            }
        }
        if (!verificar) {
            pares.push_back({guardar, {1, i}});
        }
    }

    heapSort(pares);

    for (int i = 0; i < pares.size(); i++) {
        int rep = pares[i].second.first;
        while (rep--) {
            cout << pares[i].first << " ";
        }
    }
    cout << endl;

    return 0;
}
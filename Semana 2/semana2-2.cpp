#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*Se crea la funcion paso 1 que determina el orden de los elementos, compara
el segundo elemento de cada par (a y b), si las frecuencias son iguales la funcion
compara las posiciones al inicio, retornara true si a aparece antes que b, esto
para que, el que aparecio primero en la lista se ordene antes.
*/

bool paso1(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.second.second < b.second.second;
}

/*Defini las variables y un vector de pares que guardara cada numero con su
frecuencia y posicion al principio. Luego cree un bucle que contara la frecuencia
de cada numero y guardara la posicion de su primera aparicion, si encuentra un numero
que ya esta en pares incrementa el cont y si no, lo a;ade a pares con el cont
inicializado en 1 y su posicion de aparicion. Se usa push back para ir almacenando
y actualizando la cuenta de apariciones de cada valor y su posicion de primera
aparicion eficientemente*/

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

    /*Defini una var que guardar la cantidad de elementos de pares, luego cree
    un bucle que lo que hara es que si pares[k] y pares[k+1] no ocurren se intercambiaran.
    Despues de ordenar el vector pares con las especificaciones pertinentes, se imprime
    cada numero la cantidad de veces que aparecio
    */

    int pos = pares.size();

    for (int j = 0; j < pos - 1; j++) {
        for (int k = 0; k < pos - j - 1; k++) {
            if (!paso1(pares[k], pares[k + 1])) {
                swap(pares[k], pares[k + 1]);
            }
        }
    }


    for (int i = 0; i < pos; i++) {
        int rep = pares[i].second.first;
        while (rep--) {
            cout << pares[i].first << " ";
        }
    }
    cout << endl;

    return 0;
}
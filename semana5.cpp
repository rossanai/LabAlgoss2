#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool comparacion(const pair<int, pair<int, int>>& numero1, const pair<int, pair<int, int>>& numero2) {
    if (numero1.second.first != numero2.second.first) {
        return numero1.second.first > numero2.second.first;
    }
    return numero1.second.second < numero2.second.second;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, pair<int, int>>> desorden;

    for (int i = 0; i < n; ++i) {
        int guardando;
        cin >> guardando;
        bool encontrado = false;
        for (auto& reccorre : desorden) {
            if (reccorre.first == guardando) {
                reccorre.second.first++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            desorden.push_back({guardando, {1, i}});
        }
    }

    int posicion = desorden.size();

    for (int j = 0; j < posicion - 1; j++) {
        for (int k = 0; k < posicion - j - 1; k++) {
            if (!comparacion(desorden[k], desorden[k + 1])) {
                swap(desorden[k], desorden[k + 1]);
            }
        }
    }

    for (int i = 0; i < posicion; i++) {
        int repeticiones = desorden[i].second.first;
        while (repeticiones--) {
            cout << desorden[i].first << " ";
        }
    }
    cout << endl;

    return 0;
}
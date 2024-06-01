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
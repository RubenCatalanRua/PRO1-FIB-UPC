#include <iostream>
#include <vector>
using namespace std;


typedef vector<string> Fila;
typedef vector<Fila> Matriu;

int nombre_de_paraules(const Matriu& m, char c, int k) {
    int total = 0;
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        int x = m[i].size();
        for (int j = 0; j < x; ++j) {
            if (k < m[i][j].size() and m[i][j][k] == c) ++total;
        }
    }
    return total;
}

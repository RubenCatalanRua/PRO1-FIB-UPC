// Foc!
#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> Fila;
typedef vector<Fila> Matriu;


void readMat(Matriu& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mat[i][j];
    }
}

void writeMat(const Matriu& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << mat[i][j];
        cout << endl;
    }
    cout << endl;
}

void fogonazo(Matriu& mat) {
    int n = mat.size();
    int m = mat[0].size();
    bool fuego = true;
    while (fuego) {
        fuego = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'F') {
                    if (j < m - 1 and mat[i][j+1] == 'A') {
                        mat[i][j+1] = 'F';
                        fuego = true;
                    }
                    if (0 < j and mat[i][j-1] == 'A') {
                        mat[i][j-1] = 'F';
                        fuego = true;
                    }
                    if (i < n - 1 and mat[i+1][j] == 'A') {
                        mat[i+1][j] = 'F';
                        fuego = true;
                    }
                    if (0 < i and mat[i-1][j] == 'A') {
                        mat[i-1][j] = 'F';
                        fuego = true;
                    }
                    mat[i][j] = '.';
                }
            }
        }
    }
}

int main() {
    int f,c;
    while (cin >> f >> c) {
        Matriu mat(f, Fila(c));
        readMat(mat);
        fogonazo(mat);
        writeMat(mat);
    }
}

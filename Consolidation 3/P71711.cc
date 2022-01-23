#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

bool ziga(const Matriu& mat) {
	int n = mat.size();
	int m = mat[0].size();
	int cr = mat[0][0];
	for (int j = 0; j < m; ++j) {
		if (j%2 == 0) {
			if (j == 0) {
				for (int i = 1; i < n; ++i) {
					if (mat[i][j] <= cr) return false;
					cr = mat[i][j];
				}
			}
			else {
				for (int i = 0; i < n; ++i) {
					if (mat[i][j] <= cr) return false;
					cr = mat[i][j];
				}

			}
		}
		else {
			for (int i = n - 1; i >= 0; --i) {
				if (mat[i][j] <= cr) return false;
				cr = mat[i][j];
			}
		}
	}
	return true;
}

void readMat(Matriu& mat) {
	int f = mat.size();
	int c = mat[0].size();
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) cin >> mat[i][j];
	}
}

int main() {
	int matN = 1;
	int f, c;
	while (cin >> f >> c) {
		Matriu mat(f, Fila(c));
		readMat(mat);
		if (ziga(mat)) cout << "matriu " << matN << ": si" << endl;
		else cout << "matriu " << matN << ": no" << endl;
		++matN;
	}
}
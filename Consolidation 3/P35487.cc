#include <iostream>
#include <vector>
using namespace std;

struct Info {
    string nom, hora;
};

string busca(string nom, const vector<Info>& v) {
    int n = v.size();
    int esq = 0;
    int dre = v.size() - 1;
    bool trobat = false;
    int end;
    while (esq <= dre and not trobat) {
        int pos = (esq + dre) / 2;
        if (nom < v[pos].nom) dre = pos - 1;
        else if (nom > v[pos].nom) esq = pos + 1;
        else {
            trobat = true;
            end = pos;
        }
    }
    if (not trobat) return "ABANDONA";
    else {
        if (end > 0 and end < n - 1) {
            if (v[end - 1].nom == v[end].nom or v[end + 1].nom == v[end].nom) return "???";
            else return v[end].hora;
        }
        else if (end == 0) {
            if (v[end + 1].nom == v[end].nom) return "???";
            else return v[end].hora;
        }
        else {
            if (v[end - 1].nom == v[end].nom) return "???";
            else return v[end].hora;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Info> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].nom >> v[i].hora;

    string dni,name;
    while (cin >> dni >> name) {
        cout << dni << " " << busca(name,v) << endl;
    }
}

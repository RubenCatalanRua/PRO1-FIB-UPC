#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector <char> > Tauler;

struct Bola {

  int x_ant, y_ant;  // Posicio anterior de la bola

  int x_act, y_act;  // Posicio actual de la bola

  int x_seg, y_seg;  // Posicio seguent de la bola

};

struct Xoc {
    int x, y;
};

void escriu_tauler(const Tauler& t) {
    int n = t.size();
    int m = t[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << t[i][j];
        cout << endl;
    }
    cout << endl;
}

void moure_fins_xocar (Tauler& t, Bola& b) {
    int f = t.size();
    int c = t[0].size();
    int xocs = 0;
    int bx, by, rx, ry;
    cin >> bx >> by >> rx >> ry;
    t[rx][ry] = 'b', t[bx][by] = 'B';
    b.x_act = bx, b.y_act = by;
    int dirX, dirY;
    if (bx == by and bx == 0) {
        b.x_seg = b.x_act + 1, b.y_seg = b.y_act + 1;
        dirX = 1, dirY = 1;
    }
    else if (bx == f-1 and by == c-1) {
        b.x_seg = b.x_act - 1, b.y_seg = b.y_act - 1;
        dirX = -1, dirY = -1;
    }
    else if (bx == f-1 and by == 0) {
        b.x_seg = b.x_act - 1, b.y_seg = b.y_act + 1;
        dirX = -1, dirY = 1;
    }
    else {
        b.x_seg = b.x_act + 1, b.y_seg = b.y_act - 1;
        dirX = 1, dirY = -1;
    }

    bool xocat = false;
    bool esq = false;
    vector<Xoc> v(0);
    while (xocs < 4 and not xocat and not esq) {
        b.x_ant = b.x_act, b.y_ant = b.y_act, b.x_act = b.x_seg, b.y_act = b.y_seg;
        if ((b.x_act == 0 or b.x_act == f-1) and (b.y_act == 0 or b.y_act == c-1)) esq = true;
        else if (b.x_act == rx and b.y_act == ry) xocat = true;
        else {
            if (b.x_act == f-1 or b.x_act == 0 or b.y_act == c-1 or b.y_act == 0) {
                if (b.x_act == f-1) dirX = -1;
                else if (b.x_act == 0) dirX = 1;
                else if (b.y_act == c-1) dirY = -1;
                else dirY = 1;
                Xoc l;
                l.x = b.x_act, l.y = b.y_act;
                v.push_back(l);
                ++xocs;
            }
            b.x_seg += dirX;
            b.y_seg += dirY;
        }
        t[b.x_ant][b.y_ant] = '=';
    }
    t[b.x_act][b.y_act] = 'B';
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << "(" << v[i].x << "," << v[i].y << ")";
    }
    cout << ": ";
    if (xocat and xocs == 3) cout << "si" << endl;
    else cout << "no" << endl;
    escriu_tauler(t);

}

int main() {
    int f,c;
    while (cin >> f >> c) {
        Tauler t(f, vector<char>(c,'.'));
        Bola b;
        moure_fins_xocar(t, b);
    }
}       
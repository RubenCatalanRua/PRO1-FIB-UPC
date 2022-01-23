 #include <iostream>
 #include <vector>
 using namespace std;
 
 
 struct Alumne {
     int dni;
     string nom;
 };
 
 
 struct Nota {
     int dni;
     string ass;     // assignatura
     string fac;     // facultat
     double nota;
 };
 
 
 void llegeix_alumnes(vector<Alumne>& alumnes) {
     int m;
     cin >> m;
     alumnes = vector<Alumne>(m);
     for (int i = 0; i < m; ++i) cin >> alumnes[i].dni >> alumnes[i].nom;
 }
 
 
 void llegeix_notes(vector<Nota>& notes) {
     int n;
     cin >> n;
     notes = vector<Nota>(n);
     for (int i = 0; i < n; ++i) {
         cin >> notes[i].dni >> notes[i].ass >> notes[i].fac >> notes[i].nota;
     }
 }
 
 
 int main() {
     cout.setf(ios::fixed);      // estableix el format dels reals
     cout.precision(2);          // per escriure les notes
 
     vector<Alumne> alumnes;
     vector<Nota> notes;
     llegeix_alumnes(alumnes);
     llegeix_notes(notes);
 
     int n = alumnes.size();
     int m = notes.size();
     int j = 0;
     for (int i = 0; i < n; ++i) {
        bool trobat = false;
        while (j < m and not trobat and notes[j].dni <= alumnes[i].dni) {
            if (alumnes[i].dni == notes[j].dni) trobat = true;
            else ++j;
        }
        if (trobat) {
            cout << alumnes[i].dni << " " << alumnes[i].nom << endl;
            int k = j;
            double mitjana = 0;
            int counter = 0;
            while (k < m and notes[k].dni == notes[j].dni) {
                cout << "     " << notes[k].ass << " " << notes[k].fac << " " << notes[k].nota << endl;
                ++counter;
                mitjana += notes[k].nota;
                ++k;
            }
            cout << "     mitjana: " << mitjana/counter << endl;
            cout << endl;
            j = k;
        }
     }
 }
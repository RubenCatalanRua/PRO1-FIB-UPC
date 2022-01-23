#include <iostream>
#include <vector>
using namespace std;


struct Person {
    string name;
    int age;
};

void escriu(const vector<Person>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) cout << v[i].name << " " << v[i].age << endl;
}

void insert(vector<Person>& v) {    // Hecho con Insertion Sort
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int x = v[i].age;
        string y = v[i].name;
        int j = i;
        while (j > 0 and (x > v[j - 1].age or (x == v[j-1].age and y < v[j-1].name))) {
            v[j] = v[j-1];
            --j;
        }
        v[j].name = y;
        v[j].age = x;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Person> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].name >> v[i].age;
    insert(v);
    escriu(v);
}

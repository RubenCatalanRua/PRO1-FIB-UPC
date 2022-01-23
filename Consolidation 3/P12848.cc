 #include <iostream>
 #include <vector>
 using namespace std;


int suma_digits (int n) {
    if (n < 10) return 1;
    else return 1 + suma_digits(n/10);
}

bool is_palindrome(int x) {
    int m = suma_digits(x);
    if (m == 1) return true;
    vector<int> v(m/2);
    for (int i = 0; i < m/2; ++i) {
        v[i] = x%10;
        x /= 10;
    }
    if (m%2 != 0) x /= 10;
    int i = m/2 - 1;
    while (x != 0) {
        if (x%10 != v[i]) return false;
        x /= 10;
        --i;
    }
    return true;
}

vector<int> garb(int n) {
    vector<bool> v(n+1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (v[i]) {
            for (int j = i*i; j <= n; j += i) v[j] = false;
        }
    }
    vector<int> aux(0);
    for (int i = 2; i < n + 1; ++i) {
        if (v[i] and is_palindrome(i)) aux.push_back(i);
    }
    return aux;
}

int main() {
    vector<int> v = garb(9817189);
    int n;
    while (cin >> n) cout << v[n-1] << endl;
}

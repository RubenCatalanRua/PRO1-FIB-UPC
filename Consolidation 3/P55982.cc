#include <iostream>
#include <vector>
using namespace std;


string suma(string x, string y) {
	int lenX = x.size();
	int lenY = y.size();
	string s(lenX + 1, '0');
	for (int i = 0; i < lenY; ++i) {
		int k = (s[lenX - i] - '0') + (x[lenX - 1 - i] - '0') + (y[lenY - 1 - i] - '0');
		char a = '0' + k%10;
		char b = '0' + k/10;
		s[lenX - i] = a;
		s[lenX -1 - i] = b;
	}
	for (int i = lenY; i < lenX; ++i) {
		int k = (s[lenX - i] - '0') + (x[lenX - 1 - i] - '0');
		char a = '0' + k%10;
		char b = '0' + k/10;
		s[lenX - i] = a;
		s[lenX -1 - i] = b;
	}
	return s;
}


int main() {
         string x, y;
         while (cin >> x >> y) cout << suma(x, y) << endl;
     }
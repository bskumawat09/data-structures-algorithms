// Time		: O(log2(n))
// Space	: O(1)

#include <iostream>
using namespace std;

int power(int a, int n) {
	int res = 1;

	while(n != 0) {
		if(n % 2 != 0) {
			res = res * a;
			n--;
		}
		a = a * a;
		n = n / 2;
	}
	return res;
}

int main() {
	int a = 3;
	int n = 4;

	cout << a << "^" << n << " = " << power(a, n) << endl;
	return 0;
}
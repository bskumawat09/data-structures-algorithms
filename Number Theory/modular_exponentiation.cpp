#include <iostream>
using namespace std;

// Time		: O(logN)
// Space	: O(logN) or O(1)

int powModR(long long a, int n, int m) {
	if(n == 0)
		return 1;

	int k = powModR(a, n/2, m);

	if(n % 2 == 1)
		return (((1LL*k*k) % m) * (a % m)) % m;

	return (1LL*k*k) % m;
}

int powModI(long long a, int n, int m) {
	a = a % m;
	int res = 1;

	while(n) {
		if(n & 1 == 1) {	// if n is odd
			res = (res * a) % m;
		}
		a = (a * a) % m;	
		n = n >> 1;			// divide n by 2
	}

	return res;
}

int main() {
	long long a = 2;
	int n = 100000;
	int m = 1e9 + 7;

	cout << powModR(a, n, m) << endl;	// recursive binary exponentiation
	cout << powModI(a, n, m) << endl;	// iterative binary exponentiation
	return 0;
}
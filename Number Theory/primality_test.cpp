// Time		: O(sqrt(n))
// Space	: O(1)

#include <iostream>
using namespace std;

bool isPrime(int n) {
	if(n == 1 || n == 0) {
		return false;
	}
	for(int i = 2; i*i < n; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n = 17;

	if(isPrime(n))
		cout << n << " is prime" << endl;
	else
		cout << n << " is not prime" << endl;
	
	return 0;
}
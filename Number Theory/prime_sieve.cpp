// Time		: O(n)
// Constant query time
// Space	: O(n)

#include <iostream>
using namespace std;

#define MAX 100001

bool primes[MAX];

void initialize() {
	for(int i=2; i<MAX; i++) {		// initially mark all the numbers as prime
		primes[i] = 1;				// except numbers '0' and '1'
	}
	for(int i=2; i*i<MAX; i++) {	// if a number is prime then mark all its 
		if(primes[i] == 1) {		// multiple as composite i.e '0'
			for(int j=i*i; j<=MAX; j+=i)	
				primes[j] = 0;
		}
	}
}

int main() {
	initialize();
	cout << "prime numbers(1 to 100): " << endl;

	for(int i=1; i<100; i++) {
		if(primes[i])
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
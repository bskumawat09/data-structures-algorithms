// Time		: O(n^2)
// Space	: O(1)
// Stable	: preserve the order for same elements
// Adaptive	: takes less time if array is sorted

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	for(int i=1; i<n; i++) {
		int x = arr[i];
		int j = i-1;

		while(j >= 0 && arr[j] > x) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
}

void printArray(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, n);

	insertionSort(arr, n);

	printArray(arr, n);
	return 0;
}
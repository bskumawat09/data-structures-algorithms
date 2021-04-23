// Time			: O(n^2)
// Space		: O(1)
// Not stable	: does NOT preserve the order for same elements
// Not adaptive	: does NOT take less time if array is sorted

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
	for(int i=0; i<n-1; i++) {
		int min = arr[i];
		int minIdx = i;

		for(int j=i+1; j<n; j++) {
			if(arr[j] < min) {
				min = arr[j];
				minIdx = j;
			}
		}
		swap(arr[i], arr[minIdx]);
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

	selectionSort(arr, n);

	printArray(arr, n);
	return 0;
}
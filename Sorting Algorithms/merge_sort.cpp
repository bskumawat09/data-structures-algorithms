#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
	int A[end-start+1];			// auxilary array of (size end-start+1)
	int p = start;				// p store starting position of 1st sub-array
	int q = mid + 1;			// q store starting position of 2nd sub-array

	int k = 0;					// k is iterator to auxilary array A[]
	for(int i = start; i <= end; i++) {
		if(p > mid)					// if 1st sub-array finished
			A[k++] = arr[q++];

		else if(q > end)			// if 2nd sub-array finished
			A[k++] = arr[p++];

		else if(arr[p] > arr[q])	// if 2nd sub-array has smaller element
			A[k++] = arr[q++];

		else						// if 1st sub-array has smaller element
			A[k++] = arr[p++];
	}

	for(int j = 0; j < k; j++) {	// copy this auxilary array back to arr[]
		arr[start++] = A[j];
	}
}

void mergeSort(int arr[], int start, int end) {
	if(start >= end)				// if there is only one or no element in array
		return;
	
	int mid = (start + end)/2;		// find middle of an array

	mergeSort(arr, start, mid);		// sort the left sub-array
	mergeSort(arr, mid+1, end);		// sort the right sub-array

	merge(arr, start, mid, end);	// merge two sorted sub-arrays
}

int main() {
    int arr[] = {43, 61, 30, -20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++)
    	cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    	cout << arr[i] << " ";

    cout << endl;

    return 0;
}
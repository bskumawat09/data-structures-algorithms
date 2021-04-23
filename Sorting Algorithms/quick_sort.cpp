// Average Time	: O(n*logn)
// Worst Time 	: O(n^2)
// Space	: O(1)
// Not stable	: does NOT preserve the order for same elements
// Not adaptive	: does NOT take less time if array is sorted

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];

	int i = low-1;
	for(int j=low; j<high; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(int arr[], int l, int r) {
	if(l >= r)
		return;
	
	int p = partition(arr, l, r);
	quickSort(arr, l, p-1);
	quickSort(arr, p+1, r);
}

int main() {
    int arr[] = {26, 34, 25, 18, 12, -15, 43};
    int n = sizeof(arr)/sizeof(arr[0]);

    // print unsorted array
    for(int i=0; i<n; i++)
    	cout << arr[i] << " ";

    cout << endl;

    quickSort(arr, 0, n-1);

    // print sorted array
    for(int i=0; i<n; i++)
    	cout << arr[i] << " ";

    cout << endl;

    return 0;
}

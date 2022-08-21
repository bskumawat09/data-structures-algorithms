/*
Average Time: O(N*logN)
Worst Time 	: O(N^2)
Space		: O(1)
Stable		: NO, does NOT preserve the order for same elements
Adaptive	: NO, does NOT take less time if array is sorted
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void quickSort(int arr[], int l, int r) {
        if(l >= r)
            return;

        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];

        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

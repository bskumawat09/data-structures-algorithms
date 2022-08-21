/*
For every index find the smallest element and swap it with current.

Time	: O(N^2)
Space	: O(1)
Stable	: NO, does NOT preserve the order for same elements
Adaptive: NO, does NOT take less time if array is sorted

Best case	: [1,2,3,4,5], 0 swaps
Worst case	: [2,4,5,3,1], n-1 swaps
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void selectionSort(int arr[], int n) {
        for(int i = 0; i < n - 1; i++) {
            int min = arr[i];
            int minIdx = i;

            for(int j = i + 1; j < n; j++) {
                if(arr[j] < min) {
                    min = arr[j];
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }
};

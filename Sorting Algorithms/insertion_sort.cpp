/*
Time	: O(N^2)
Space	: O(1)
Stable	: YES, preserve the order for same elements
Adaptive: YES, takes less time if array is sorted
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void insertionSort(int arr[], int n) {
        for(int i = 1; i < n; i++) {
            int x = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > x) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = x;
        }
    }
};

// insertionsort
// Insertion sort is a simple comparison-based sorting algorithm.
// It works by dividing the list into a sorted and an unsorted part.    
// The sorted part is built up from left to right, and the unsorted part is the remaining elements.
// The algorithm iteratively takes one element from the unsorted part and inserts it into the correct position in the sorted part until the entire list is sorted.  

#include <bits/stdc++.h>
using namespace std;   

void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Time complexity: O(n^2) in the worst and average cases, O(n) in the best case (when the array is already sorted).
    // Space complexity: O(1) (in-place sorting algorithm)
}

// DRY RUN
// Consider the array [12, 11, 13, 5, 6]
// 1. First iteration (i = 1):
//    - key = 11, j = 0 (value 12)
//    - Compare 12 and 11, since 12 > 11, shift 12 to the right, resulting in [12, 12, 13, 5, 6]
//    - Decrement j to -1, insert key (11) at position j + 1, resulting in [11, 12, 13, 5, 6]
// 2. Second iteration (i = 2):
//    - key = 13, j = 1 (value 12)
//    - Compare 12 and 13, since 12 < 13, no shift needed, resulting in [11, 12, 13, 5, 6]
// 3. Third iteration (i = 3):
//    - key = 5, j = 2 (value 13)
//    - Compare 13 and 5, since 13 > 5, shift 13 to the right, resulting in [11, 12, 13, 13, 6]
//    - Compare 12 and 5, since 12 > 5, shift 12 to the right, resulting in [11, 12, 12, 13, 6]
//    - Compare 11 and 5, since 11 > 5, shift 11 to the right, resulting in [11, 11, 12, 13, 6]
//    - Decrement j to -1, insert key (5) at position j + 1, resulting in [5, 11, 12, 13, 6]
// 4. Fourth iteration (i = 4): 
//    - key = 6, j = 3 (value 13)
//    - Compare 13 and 6, since 13 > 6, shift 13 to the right, resulting in [5, 11, 12, 13, 13]
//    - Compare 12 and 6, since 12 > 6, shift 12 to the right, resulting in [5, 11, 12, 12, 13]
//    - Compare 11 and 6, since 11 > 6, shift 11 to the right, resulting in [5, 11, 11, 12, 13]
//    - Compare 5 and 6, since 5 < 6, no shift needed, resulting in [5, 6, 11, 12, 13]
// 5. The array is now sorted: [5, 6, 11, 12, 13]   


int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    insertion_sort(arr);
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}

// Selection sort is a simple comparison-based sorting algorithm.
// It works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and swapping it with the first unsorted element until the entire list is sorted.

#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    // Time complexity: O(n^2) in all cases (best, average, worst) because of the nested loops.
    // Space complexity: O(1) (in-place sorting algorithm)
}

// DRY RUN
// Consider the array [64, 25, 12, 22, 11]
// 1. First iteration (i = 0):
//    - min_index starts at 0 (value 64)
//    - Compare with 25 (index 1), update min_index to 1
//    - Compare with 12 (index 2), update min_index to 2
//    - Compare with 22 (index 3), min_index remains 2
//    - Compare with 11 (index 4), update min_index to 4
//    - Swap 64 with 11, resulting in [11, 25, 12, 22, 64]
// 2. Second iteration (i = 1):
//    - min_index starts at 1 (value 25)
//    - Compare with 12 (index 2), update min_index to 2
//    - Compare with 22 (index 3), min_index remains 2
//    - Compare with 64 (index 4), min_index remains 2
//    - Swap 25 with 12, resulting in [11, 12, 25, 22, 64]
// 3. Third iteration (i = 2):
//    - min_index starts at 2 (value 25)
//    - Compare with 22 (index 3), update min_index to 3
//    - Compare with 64 (index 4), min_index remains 3
//    - Swap 25 with 22, resulting in [11, 12, 22, 25, 64]
// 4. Fourth iteration (i = 3):
//    - min_index starts at 3 (value 25)
//    - Compare with 64 (index 4), min_index remains 3
//    - Swap 25 with 25 (no change), resulting in [11,
//      12, 22, 25, 64]
// 5. The array is now sorted: [11, 12, 22, 25, 64]


int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selection_sort(arr);
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
// Bubble Sort

#include <iostream>
#include <vector>
using namespace std;

// Bubble sort is a simple comparison-based sorting algorithm. 
// It works by repeatedly stepping through the list, comparing adjacent elements and swapping them if they are in the wrong order.
// The process is repeated until the list is sorted.

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }


    // Time complexity: O(n^2) in all cases (best, average, worst) because of the nested loops.
    // Space complexity: O(1) (in-place sorting algorithm)
}

// DRY RUN
// Consider the array [64, 34, 25, 12, 22,  11, 90]
// 1. First iteration (i = 0):              
//    - Compare 64 and 34, swap them, resulting in [34, 64, 25, 12, 22, 11, 90]
//    - Compare 64 and 25, swap them, resulting in [34, 25, 64, 12, 22, 11, 90]
//    - Compare 64 and 12, swap them, resulting in [34, 25, 12, 64, 22, 11, 90]
//    - Compare 64 and 22, swap them, resulting in [34, 25, 12, 22, 64, 11, 90]
//    - Compare 64 and 11, swap them, resulting in [34, 25, 12, 22, 11, 64, 90]
//    - Compare 64 and 90, no swap needed, resulting in [34, 25, 12, 22, 11, 64, 90]
// 2. Second iteration (i = 1):
//    - Compare 34 and 25, swap them, resulting in [25, 34, 12, 22, 11, 64, 90]
//    - Compare 34 and 12, swap them, resulting in [25, 12, 34, 22, 11, 64, 90]
//    - Compare 34 and 22, swap them, resulting in [25, 12, 22, 34, 11, 64, 90]
//    - Compare 34 and 11, swap them, resulting in [25, 12, 22, 11, 34, 64, 90]
//    - Compare 34 and 64, no swap needed, resulting in [25, 12, 22, 11, 34, 64, 90]
//    - Compare 64 and 90, no swap needed, resulting in [25, 12, 22, 11, 34, 64, 90]
// 3. Third iteration (i = 2):
//    - Compare 25 and 12, swap them, resulting in [12, 25, 22, 11, 34, 64, 90]
//    - Compare 25 and 22, swap them, resulting in [12, 22, 25, 11, 34, 64, 90]
//    - Compare 25 and 11, swap them, resulting in [12, 22, 11, 25, 34, 64, 90]
//    - Compare 25 and 34, no swap needed, resulting in [12, 22, 11, 25, 34, 64, 90]
//    - Compare 34 and 64, no swap needed, resulting in [12, 22, 11, 25, 34, 64, 90]
//    - Compare 64 and 90, no swap needed, resulting in [12, 22, 11, 25, 34, 64, 90]
// 4. Fourth iteration (i = 3): 
//    - Compare 12 and 22, no swap needed, resulting in [12, 22, 11, 25, 34, 64, 90]
//    - Compare 22 and 11, swap them, resulting in [12, 11, 22, 25, 34, 64, 90]
//    - Compare 22 and 25, no swap needed, resulting in [12, 11, 22, 25, 34, 64, 90]
//    - Compare 25 and 34, no swap needed, resulting in [12, 11, 22, 25, 34, 64, 90]
//    - Compare 34 and 64, no swap needed, resulting in [12, 11, 22, 25, 34, 64, 90]
//    - Compare 64 and 90, no swap needed, resulting in [12, 11, 22, 25, 34, 64, 90]
// 5. Fifth iteration (i = 4):  
//    - Compare 12 and 11, swap them, resulting in [11, 12, 22, 25, 34, 64, 90]
//    - Compare 12 and 22, no swap needed, resulting in [11, 12, 22, 25, 34, 64, 90]
//    - Compare 22 and 25, no swap needed, resulting in [11, 12, 22, 25, 34, 64, 90]
//    - Compare 25 and 34, no swap needed, resulting in [11, 12, 22, 25, 34, 64, 90]
//    - Compare 34 and 64, no swap needed, resulting in [11, 12, 22, 25, 34, 64, 90]
//    - Compare 64 and 90, no swap needed, resulting in [11, 12, 22, 25, 34, 64, 90]
// 6. The array is now sorted: [11, 12, 22, 25, 34, 64, 90]

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(arr);
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
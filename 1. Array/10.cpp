// Longest consective sequence in an array
/*
QUESTION:-
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
*/  

// example:- nums = [100, 4, 200, 1, 3, 2] -> output: 4 (the longest consecutive elements sequence is [1, 2, 3, 4])

// APPROACH:-
// We can use a hash set to store the elements of the array. Then, we can  iterate through the array and for each element, 
// we can check if it is the start of a sequence (i.e., if the previous element is not in the set). 
// If it is the start of a sequence, we can keep checking for the next elements in the sequence until we find an element that is not in the set. 
// We can keep track of the length of the longest sequence found so far and return it at the end.

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : numSet)
    {
        if (!numSet.count(num - 1)) // Check if it's the start of a sequence
        {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.count(currentNum + 1)) // Check for the next elements in the sequence
            {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak); // Update the longest streak
        }
    }

    return longestStreak;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // Output: 4
}

// TIME COMPLEXITY = O(N) : We iterate through the array once to create the hash set, which takes O(N) time.
// Then, we iterate through the hash set, which also takes O(N) time in the worst case. Therefore, the overall time complexity is O(N).
// SPACE COMPLEXITY = O(N) : We use a hash set to store the elements of the array, which takes O(N) space.

// STL OF HASH SET:-

/*
unordered_set<int> numSet(nums.begin(), nums.end());
This line of code initializes an unordered_set called numSet with the elements from the vector nums.
The constructor of unordered_set takes a range of iterators as arguments, and in this case, we are passing the beginning 
and end iterators of the nums vector. This allows us to efficiently create a hash set containing all the unique elements
from the nums vector, which we can then use for O(1) average time complexity lookups when checking for the presence of elements 
in the set.
*/

// we can insert by using insert function or by using initializer list as shown below:-
/*
unordered_set<int> numSet;
for (int num : nums) {
    numSet.insert(num);
}   
*/

// T.C for ordered set is O(log n) and for unordered set is O(1) on average.
// T.C for ordered set in worst case is O(n) and for unordered set in worst case is O(n) when there are many collisions in the hash function.
// We use unordered_set instead of set because we want to achieve O(1) average time complexity for lookups, which is crucial for the efficiency of our algorithm.
// ordered set is used when we want to maintain the order of elements and perform operations like finding the next greater element, while unordered_set is used when we only care about the presence of elements and want to achieve faster lookups.    



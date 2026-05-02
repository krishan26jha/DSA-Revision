// Longest Subarray with Sum K
// Given an array of integers and an integer k, find the length of the longest subarray that sums to k.

#include <bits/stdc++.h>
using namespace std;        

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int n = arr.size();
        /* We can use a hash map to store the sum of the subarray and its index. We can iterate through the array and keep adding the elements to the subarray sum. 
        If the subarray sum is equal to k, we can update the maximum length of the subarray. 
        If the subarray sum is greater than k, we can check if the difference between the subarray sum and k is present in the hash map. 
        If it is present, we can update the maximum length of the subarray by taking the difference between the current index and the index of the subarray sum that is equal to the difference. 
        We can also add the current subarray sum to the hash map if it is not already present.
        */
        int maxLen = 0;
        int subSum = 0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            subSum += arr[i];
            
            if(subSum == k){
                maxLen = max(maxLen,i+1);
            }
            int rem = subSum-k;
            if(mp.find(rem) != mp.end()){
                maxLen = max(maxLen,i-(mp[rem]));
            }
            
            if(mp.find(subSum) == mp.end()){
                mp[subSum] = i;
            }
            
        }
        return maxLen;
    }
};
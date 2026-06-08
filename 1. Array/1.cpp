// Move Zeroes to end

#include <bits/stdc++.h>
using namespace std;

// Aprroach 1: Two Pointer Approach
// We can use two pointers to solve this problem. We can maintain two pointers, one for the current index and another for the last non-zero element. 
// We can iterate through the array and whenever we encounter a non-zero element, we can swap it with the last non-zero element and update the last non-zero element pointer. This way, all the non-zero elements will be moved to the front of the array and all the zeroes will be moved to the end of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int ind= 0;
        int j=0;
        while(ind<nums.size()){
            if(nums[ind] == 0){
                 j = ind;
                break;
            }
            ind++;
        }
    
        int i = j+1;

        while(i < nums.size()){
            if(nums[i] != 0 && nums[j] == 0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else{
                i++;
            }
        }
      
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
}
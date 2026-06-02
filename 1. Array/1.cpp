// Move Zeroes to end

#include <bits/stdc++.h>
using namespace std;

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
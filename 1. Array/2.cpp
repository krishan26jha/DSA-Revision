// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:   

    void rotateLeft(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
    void rotateRight1(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }

    void rotateRight(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        reverse(nums.begin(),nums.begin() + (n-k));
        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> nums2 = {1,2,3,4,5,6,7};
    vector<int> nums3 = {1,2,3,4,5,6,7};
    int k = 3;
    s.rotateLeft(nums,2);
    cout<<"Left Rotation: ";
    for(int i:nums){
        cout<<i<<" ";
    }
    s.rotateRight(nums2,k);
    cout<<"\nRight Rotation: ";
    for(int i:nums2){
        cout<<i<<" ";
    }

    s.rotateRight1(nums3,k);
    cout<<"\nRight Rotation: ";
    for(int i:nums3){
        cout<<i<<" ";
    }
} 


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

    void rotateLeft1(vector<int>&nums,int k) {
        // T.C : O(n*k) where n is the size of the array and k is the number of rotations. This is because for each rotation, we are shifting all elements of the array by one position, which takes O(n) time. Since we are doing this k times, the overall time complexity is O(n*k).
        // S.C : O(1) since we are performing the rotation in-place without using any additional data structures that grow with the input size. We are only using a constant amount of extra space for temporary variables during the rotation process.
        if(nums.empty()) return;
        k = k % nums.size();
        int n = nums.size();
        for(int i=0;i<k;i++){
            int temp = nums[0];
            for(int j=1;j<n;j++){
                nums[j-1] = nums[j];
            }
            nums[n-1] = temp;
        }
    }

    void rotateLeft2(vector<int>& nums, int k) {
        // T.C : O(n) where n is the size of the array. This is because we are creating a new temporary array to hold the rotated elements, and we are iterating through the original array once to fill the temporary array. The overall time complexity is O(n).
        // S.C : O(n) since we are using an additional temporary array to store the rotated elements. The size of the temporary array is equal to the size of the input array, so the space complexity is O(n).
        k = k % nums.size();
        vector<int> temp(nums.begin()+k,nums.end());    
        for(int i=0;i<k;i++){
            temp.push_back(nums[i]);
        }
        nums = temp;    
    }

    void rotateRight1(vector<int>& nums,int k) {
        if(nums.empty()) return;
        k = k % nums.size();
        int n = nums.size();
        for(int i=0;i<k;i++){
            int temp = nums[n-1];
            for(int j=n-1;j>0;j--){
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
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


// find missing number in array of 1 to n

#include <bits/stdc++.h>
using namespace std;    

class Solution {
public: 
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        /*We calculate the sum of first n natural numbers using the formula n*(n+1)/2 and 
        then we calculate the sum of all the elements in the array and 
        then we subtract the sum of the array from the sum of first n natural numbers to get the missing number. */
        int sum = (n*(n+1))/2;
        int sum1 = 0;  //int sum1 = accumulate(nums.begin(),nums.end(),0);
        for(int i:nums){
            sum1 += i;
        }
        return sum - sum1;
    }
  
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;           
        /* we know that the missing number is in the range of 0 to n, 
        so we will take xor of all the numbers in the array and xor of all the numbers from 0 to n and
        then xor of both will give us the missing number */

        for(int i:nums){
            xor1 ^= i;
        }   
       int xor2 = 0;
        for(int i=0;i<=n;i++){
            xor2 ^= i;
        }
        return xor1 ^ xor2;

        // can we do this in one loop
        /* we can also do this in one loop by taking xor of all the numbers in the array and xor of all the numbers from 0 to n in the same loop and then xor of both will give us the missing number */
        int xor3 = 0;   
        for(int i=0;i<=n;i++){
            xor3 ^= i;
            if(i < n){
                xor3 ^= nums[i];
            }
        }
        return xor3;
    }

    int missingNumber2(vector<int>& nums) {
        int n = nums.size() + 1;
       
        /* we can also use a hash array to store the presence of each number in the array and
         then we can check for the missing number by checking the hash array. */
        vector<int>hash(n,0);
        for(int i:nums){
            hash[i] = 1;
        }
        for(int i=0;i<n;i++){
            if(hash[i] == 0){
                return i;
            }
        }
        return n; // This line should never be reached if the input is valid
    }
    

   
};  

int main(){
    Solution s;
    vector<int> nums = {0,1,2,3,4,5,6,7,9};
    cout<<s.missingNumber(nums);
    cout<<"\n"<<s.missingNumber1(nums);
    cout<<"\n"<<s.missingNumber2(nums);
}
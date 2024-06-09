#include<iostream>
#include<vector>
#include<unordered_map>
//https://leetcode.com/problems/subarray-sums-divisible-by-k/?envType=daily-question&envId=2024-06-09
class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
       std::unordered_map<int,int> freq;
       int count=0;
       int prefixsum=0;
       freq[0]=1;
       for(int i=0;i<nums.size();i++)
       {

            prefixsum=(prefixsum+nums[i]%k+k)%k;
            count+=freq[prefixsum];
            freq[prefixsum]+=1;
       }
       return count;
   

    }
};
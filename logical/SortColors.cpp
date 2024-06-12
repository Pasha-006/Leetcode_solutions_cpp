#include<iostream>
#include<vector>
//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int ones=0,twos=0,zeros=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zeros+=1;
            }
            if(nums[i]==1)
            {
                ones+=1;
            }
            if(nums[i]==2)
            {
                twos+=1;
            }
        }
        int i=0;
        while(zeros>0)
        {
            nums[i++]=0;
         
            zeros-=1;
        }
        while(ones>0)
        {
            nums[i++]=1;
            ones-=1;
        }
        while(twos>0)
        {
            nums[i++]=2;
            twos-=1;
        }
    }
};
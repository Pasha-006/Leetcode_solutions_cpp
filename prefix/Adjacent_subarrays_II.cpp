//https://leetcode.com/contest/weekly-contest-423/problems/adjacent-increasing-subarrays-detection-ii/submissions/

#include<iostream>
#include<vector>
#include<algorithm>
class Solution
{
    int maxIncreasingSubarrays(std::vector<int> &nums)
    {   
        std::vector<int> increase_order;
        increase_order.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
              increase_order.push_back(increase_order[increase_order.size()-1]+1);
            }
            else
            {
                increase_order.push_back(1);
            }

        }
        std::vector<int> max_values;
        int index=0;
        max_values.push_back(1);
        for(int i=1;i<increase_order.size();i++)
        {
            if(increase_order[i-1]<increase_order[i])
            {
                max_values[index]=increase_order[i];
            }
            else 
            {
                max_values.push_back(1);
                index++;

            }
        }
        int ans=0;
        if(max_values.size()==1)
        {
            return max_values[0]/2;
        }
        for(int i=1;i<max_values.size();i++)
        {
            int temp=0;
            if(max_values[i]==max_values[i-1])
            {
                temp=max_values[i];
            }
            else 
            {
                temp=std::max(std::max(max_values[i-1],max_values[i])/2,std::min(max_values[i-1],max_values[i]));

            }
            if(temp>ans)
            {
                ans=temp;
            }

        }
        if(ans==0)
        {
            return 1;
        }
        


        return ans;
    }
};
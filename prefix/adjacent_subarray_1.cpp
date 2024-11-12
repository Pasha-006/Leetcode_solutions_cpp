#include<iostream>
#include<algorithm>

class Solution
{
    public:

    bool hasIncreasingSubarrays(std::vector<int> &nums, int k)
    {

        int size=nums.size();
        if(size/k<2)
        {
            return false;
        }
        for(int i=0;i<size-k*2+1;i++)
        {
            int flag=0;
            for(int j=i;j<i+k-1;j++)
            {
                if(nums[j+1]<=nums[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(int j=i+k;j<i+k*2-1;j++)
                {
                    if(nums[j+1]<=nums[j])
                    {
                        flag=2;
                        break;
                    }
                }
                if(flag==0)
                {
                    return true;
                }
            }


        }
    return false;
    }


};
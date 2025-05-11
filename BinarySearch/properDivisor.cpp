//https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/

#include<iostream>
#include<vector>
#include<cmath>
class Solution {
public:

    int properMaxDivisor(int number,int start,int end)
    {
        int ans=-1;
        while(start<end)
        {
            int mid=(start+end);
            if(number%mid==0)
            {
                ans=mid;
            }
      
            start=mid+1;
        }
        return ans;

    }
    void minOperations(std::vector<int>& nums) {
        for(int val:nums)
        {
            std::cout<<properMaxDivisor(val,1,int(sqrt(val))+1)<<std::endl;
        }
    }
};
int main()
{
    std::vector<int> v1{1,2,4,9,16,25,36};
    Solution s=Solution();
    s.minOperations(v1);


    return 0;
}

//https://leetcode.com/problems/counting-bits/?envType=problem-list-v2&envId=dynamic-programming
#include<iostream>
#include<vector>
class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            int setBits=0;
            for(int j=0;j<=16;j++)
            {
                int nthBit_value=(1<<j);
                int number=i&(nthBit_value);
                if(number!=0)
                {
                    setBits+=1;
                }               
            }
            ans[i]=setBits;
        }
        return ans;
    }
};
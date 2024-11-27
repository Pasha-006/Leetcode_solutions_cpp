//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=dynamic-programming 
#include<iostream> 
#include<vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int size=prices.size();
        std::vector<int> maxPrice(size);
        maxPrice[size-1]=-1;
        for(int i=size-2;i>=0;i--)
        {
            maxPrice[i]=std::max(maxPrice[i+1],prices[i+1]);

        }
        for(int i=0;i<size;i++)
        {
            std::cout<<maxPrice[i]<<std::endl;
        }
        int ans=0;
        for(int i=0;i<size;i++)
        {
            ans=std::max(ans,maxPrice[i]-prices[i]);
        }
        return ans;
        
    }
};
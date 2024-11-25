//https://leetcode.com/problems/climbing-stairs/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        if (n==1)
        {
            return 1;
        }
        if (n==2)
        {
            return 2;
        }
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int j=3;j<n+1;j++)
        {
            dp[j]=dp[j-1]+dp[j-2];
        }
        return dp[n];

        
    }
};
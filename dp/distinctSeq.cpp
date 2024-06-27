#include<iostream>
class Solution {
public:
    
    int solve(std::string s,std::string t, int i,int j,std::vector<std::vector<int>> & dp)
    {
        if(j==t.length())
        {
            return 1;
        }
        if(i==s.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            dp[i][j]=solve(s,t,i+1,j,dp)+solve(s,t,i+1,j+1,dp);
        }
        else 
        {
            dp[i][j]=solve(s,t,i+1,j,dp);
        }
        return dp[i][j];
        
    }
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<int>> dp;
        for(int i=0;i<s.length();i++)
        {
            std::vector<int> vect;
            for(int j=0;j<t.length();j++)
            {
                vect.emplace_back(-1);
            }
            dp.emplace_back(vect);
        }
       

        return solve(s,t,0,0,dp);
    }
};


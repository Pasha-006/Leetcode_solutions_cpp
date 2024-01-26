
https://leetcode.com/problems/longest-common-subsequence/

Aproach 

text1="ace"  text2="abcde" 
common_subsequence_length=3  (ace) 

  make a two 2d dp with the row  as text1.length()+1    columns as text2.length()+1 

  0 a b c d e
  a 1 0 0 0 0
  c 1 1 2 0 0 
  e 0 0 2 2 3
  
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
  
        int dp[text1.length()+1][text2.length()+1];
        for(int i=0;i<text2.length()+1;i++)
        {
            dp[0][i]=0;
            
        }
         for(int i=0;i<text1.length()+1;i++)
        {
            dp[i][0]=0;
            
        }
        for(int i=1;i<text1.length()+1;i++)
        {
            for(int j=1;j<text2.length()+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
      
        return dp[text1.length()][text2.length()];
    }
};

#include<iostream>
#include<vector>

bool isPalidrome(int left,int right,std::string s)
{
    while(left<=right)
    {
        if(s[left]!=s[right])
        {
            return false;
        }
        left++;
        right-=1;
    }
    return true;
}
int partitionCuts(std::string s)
{
    int dp[s.length()];
    int partitions=0;
    int i=0;
    while(i<s.length())
    {
        int index=i;
        for(int j=i+1;j<s.length();j++)
        {
            if(isPalidrome(i,j)==true)
            {
                index=j;
            }
        }
        partitions++;
        i=index+1;
    }
    return 0;
}
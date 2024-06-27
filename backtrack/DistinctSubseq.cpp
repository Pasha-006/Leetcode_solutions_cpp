#include<iostream>
class Solution {
public:
    int solve(std::string s,std::string t, int sstart,int tstart,int size)
    {
        if(tstart==t.length() && size==tstart)
        {
            return 1;
        }
        
        if(tstart>t.length() || s.length()<sstart || tstart==t.length())
        {
            return 0;

        }
        int ans=0;
        for(int i=sstart;i<s.length();i++)
        {
            if(s[i]==t[tstart])
            {
                ans+=solve(s,t,i+1,tstart+1,size+1);
            }
        }

        return ans;
    }
    int numDistinct(std::string s, std::string t) {
        
        return solve(s,t,0,0,0);
    }
};

int main()
{
    Solution s;
    std::cout<<s.numDistinct("babgbag","bag");

    return 0;
}
#include<iostream>
#include<vector>

class Solution {
public:
    bool isPalindrome(int left,int right,std::string s)
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
    void solve(std::string s,int index,std::vector<std::vector<std::string>> & ans ,std::vector<std::string> & temp)
    {
        if(index>=s.length())
        {
            ans.emplace_back(temp);
            for(std::string c:temp)
            {
                std::cout<<c<<" ";
            }
            std::cout<<std::endl;
            return ;
        }

        for(int i=index;i<s.length();i++)
        {
            if(isPalindrome(index,i,s)==true)
            {
                temp.emplace_back(s.substr(index,i-index+1));
                solve(s,i+1,ans,temp);
                temp.pop_back();
            }
        }
        return ;

    }
    void  partition(std::string s) {
        std::vector<std::vector<std::string>>  ans;
        std::vector<std::string> temp;

        solve(s,0,ans,temp);
    }
};
int main()
{
    Solution s;
    s.partition("aab");

    return 0;
}
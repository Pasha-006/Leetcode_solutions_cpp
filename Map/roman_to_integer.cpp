#include<iostream>
#include<stack>
#include<map>
//https://leetcode.com/problems/roman-to-integer/submissions/1146722877/
class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char,int> map_;
        map_['I']=1;
        map_['V']=5;
        map_['X']=10;
        map_['L']=50;
        map_['C']=100;
        map_['D']=500;
        map_['M']=1000;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if((i<n-1) && map_[s[i]]<map_[s[i+1]])
            {
               ans+=map_[s[i+1]]-map_[s[i]];
               i+=1;
            }
            else
            {
                ans+=map_[s[i]];
            }
            std::cout<<"ans :"<<ans<<std::endl;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    std::string str;
    std::cout<<"enter the string : ";
    std::cin>>str;
    std::cout<<s.romanToInt(str);
}

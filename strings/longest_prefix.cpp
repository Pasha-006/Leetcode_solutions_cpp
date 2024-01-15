#include<iostream>
#include<vector>
//https://leetcode.com/problems/longest-common-prefix/submissions/1146653578/
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
  
        if(strs.size()==1)
        {
            return strs[0];
        }
        std::string prefix;
        std::string temp=strs[0];
        int index=0;
        int flag=0;
        int n=temp.size();
        while(index<n)
        {
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i][index]!=temp[index])
                {
                    flag=1;
                    break;
                }   
            }
            if(flag==1)
            {
                break;
            }
            std::cout<<"char is added :"<<temp[index]<<std::endl;
            prefix+=temp[index];
            index+=1;
        }
        return prefix;

        
    }
        
    
};
int main()
{
    Solution s;
    int n;
    std::cout<<"enter the no.of strings : ";
    std::cin>>n;
    std::vector<std::string> strs;
    for(int i=0;i<n;i++)
    {
        std::string name;
        std::cin>>name;
        strs.push_back(name);

    }
    std::string res=s.longestCommonPrefix(strs);
    std::cout<<"Result is length :"<<res.length();



    return 0;
}

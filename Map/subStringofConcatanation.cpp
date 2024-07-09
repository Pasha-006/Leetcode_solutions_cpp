#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        
        std::unordered_map<std::string,int> visit;
        for(std::string &c:words)
        {
            visit[c]++;
        }
        int wordLength=words[0].length();
        int totalLength=words.size()*wordLength;
        std::vector<int> ans;
        int stringLength=s.length();
        if(stringLength<totalLength)
        {
            return ans;
        }
        for(int i=0;i<=stringLength-totalLength;i++)
        {
            std::unordered_map<std::string,int> _temp=visit;
            int index=i;
            std::string sub=s.substr(index,wordLength);
            while(index<=stringLength-wordLength &&_temp.find(sub)!=_temp.end() && _temp[sub]!=0)
            {
               
                    _temp[sub]-=1;
                index+=wordLength;
                sub=s.substr(index,wordLength);    
            }
            int flag=0;
            
                for(auto & pair:_temp)
                {
                    if(pair.second!=0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans.emplace_back(i);
                }
            
        }
        return ans;
    }
};
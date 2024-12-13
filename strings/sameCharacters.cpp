#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::unordered_map<char,int>> freq;
        int totalWords=words.size();
        for(int i=0;i<totalWords;i++)
        {
            std::unordered_map<char,int> _map;
            for(char c: words[i])
            {
                _map[c]+=1;
            }
            freq.emplace_back(_map);
        }
        std::vector<std::string> commonCharacaters;
        for(int i=0;i<26;i++)
        {
            char curr='a'+i;
            std::string ans;
            ans+=curr;
            int min=INT32_MAX;
            for(int i=0;i<totalWords;i++)
            {
                int freqn=freq[i].count(curr);
                min=std::min(freqn,min);
            }
            if(min!=0)
            {
                for(int i=0;i<min;i++)
                {
                    commonCharacaters.emplace_back(ans);

                }

            }
        }
        return commonCharacaters;
        
    }
};
//https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/
#include<iostream> 
#include<unordered_map>

class Solution
{
    public:
        int numberOfSubstrings(std::string s,int k)
        { 
          
            int subStrings=0;
            int size=s.length();
            for(int i=0;i<size;i++)
            {
                 std::unordered_map<char,int> freq;
               for(int j=i;j<size;j++)
               { 
                 char curr=s[j];
                 
                 freq[curr]+=1;
                 for(auto pair:freq)
                 {
                    if(pair.second>=k)
                    {
                        subStrings+=1;
                        break;
                    
                    }
                 }

               }
            }
            return subStrings;


        }

};

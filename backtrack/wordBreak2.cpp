#include<iostream>
#include<vector>
#include<unordered_set>
class Solution {
    void solve(std::string s,std::string currString, int startIndex,std::unordered_set<std::string> & wordDict,std::vector<std::string> &ans)
    {
       if(startIndex==s.length())
       {
   
         
          ans.emplace_back(currString);
          std::cout<<std::endl;
          return ;
       }
      
         std::string curr="";
         std::cout<<" "<<std::endl;
        for(int i=startIndex;i<s.length();i++)
        {

          curr+=s[i];
           
          if(wordDict.find(curr)!=wordDict.end())
          {
            
          
            currString+=" ";
            currString+=curr;
            solve(s,currString,i+1,wordDict,ans);
            currString.erase(startIndex);
          }
        }
        
        return ;
    }
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        
        std::vector<std::string> ans;
        std::unordered_set<std::string> Dicts;
        for(std::string w:wordDict)
        {
            Dicts.insert(w);
        }
        std::string temp="";
        solve(s,temp,0,Dicts,ans);
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> dict{"apple","pen","applepen","pine","pineapple"};
    std::string n="pineapplepenapple";
    std::vector<std::string> st=s.wordBreak(n,dict);
    std::cout<<st.size();
    for(std::string w:st)
    {
        std::cout<<w<<" ";
    }
    
   
    return 0;
}
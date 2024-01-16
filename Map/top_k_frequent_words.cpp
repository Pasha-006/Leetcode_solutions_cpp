#include<iostream>
#include<set>
#include<vector>
#include<map>
//https://leetcode.com/problems/top-k-frequent-words/
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
       //std::priority_queue<std::pair<int, std::set<std::string>>> pq;
       
       std::map<std::string,int> mp;
       for(auto str:words)
       {
          mp[str]++;
       }
       std::map<int,std::set<std::string>,std::greater<int>> frequent_words;
       for(auto item:mp)
       {
            frequent_words[item.second].insert(item.first); 
       } 


       std::vector<std::string> ans;
       for(auto ptr:frequent_words)
       {
          std::set<std::string> hs=ptr.second;
          auto traverse_set=hs.begin();
          while(traverse_set!=hs.end() && k>0)
          {
            ans.push_back(*traverse_set);
            traverse_set++;
            k-=1;
          }
       }
       return ans;


    }
};
int main()
{
    std::vector<std::string> words={"i","love","leetcode","i","love","coding"};
    Solution s;
    std::vector<std::string> res=s.topKFrequent(words,2);
    for(auto str:res)
    {
        std::cout<<str<<" ";
    }
    return 0;
}
#include<iostream>
#include<unordered_map>
class Solution {
public:
    int balancedStringSplit(std::string s) {
        
    std::unordered_map<char,int> _map;
    _map['R']=0;
    _map['L']=0;
    int cnt=0;
      for(int i=0;i<s.length();i++)
      {
        _map[s[i]]+=1;
        if(_map['R']==_map['L'])
        {
           cnt+=1; 
        }

      }
      return cnt;

    }
};
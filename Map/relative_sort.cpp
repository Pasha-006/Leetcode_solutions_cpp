
//https://leetcode.com/problems/relative-sort-array/
#include<iostream>
#include<vector> 
#include<map>
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::map<int,int> freq2;
    std::vector<int> ans;
    for(int i=0;i<arr1.size();i++)
    {
        freq2[arr1[i]]+=1;
    }
        for(int i=0;i<arr2.size();i++)
        {
            if(freq2.count(arr2[i])==0)
            {
                continue;
            }
            while(freq2[arr2[i]]!=0)
            {
                ans.emplace_back(arr2[i]);
                freq2[arr2[i]]-=1;
            }

            
        }
        for(auto & pair: freq2)
        {
          
            while(pair.second!=0)
            {
                ans.emplace_back(pair.first);
                pair.second-=1;
            }
            
        }
        return ans;
    }
};
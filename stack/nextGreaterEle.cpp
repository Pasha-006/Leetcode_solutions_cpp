//https://leetcode.com/problems/next-greater-element-i/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>


class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::unordered_map<int,int> nextGreater;
      std::stack<int> _stack;


      for(int i=0;i<nums2.size();i++)
      {

            while(!_stack.empty() && _stack.top()<nums2[i])
            {
                nextGreater[_stack.top()]=nums2[i];
                _stack.pop();
            }
            _stack.push(nums2[i]);
      }

      std::vector<int> result;

      for(int i=0;i<nums1.size();i++)
      {
        
        if(nextGreater.find(nums1[i])!=nextGreater.end())
        {
            result.emplace_back(nextGreater[nums1[i]]);
        }
        else 
        {
            result.emplace_back(-1);
        }

      }

      return result;

        
    }
};
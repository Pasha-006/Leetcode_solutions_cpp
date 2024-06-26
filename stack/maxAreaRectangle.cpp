
#include<iostream>
#include<utility>
#include<stack>
#include<vector>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
       // std::cout<<heights[0]<<std::endl;
        int maxArea=heights[0];
     
        std::stack<std::pair<int,int>> stack;
        stack.push(std::make_pair(0,heights[0]));
        int prevIndex=0;
        int index=1;
        
        
        
        for(int i=1;i<heights.size();i++)
        {
             int flag=0;

            while(!stack.empty() &&stack.top().second>heights[i])
            {
                flag=1;
                
                int area=(i-stack.top().first)*stack.top().second;
                prevIndex=stack.top().first;
                if(area>maxArea)
                {
                    maxArea=area;
                }
                stack.pop();
            }    
            if(flag==0)
            {
                stack.push(std::make_pair(i,heights[i]));
            }
            else 
            {
                stack.push(std::make_pair(prevIndex,heights[i]));
            }

        }
        while(!stack.empty())
        {
            
            int area=(heights.size()-stack.top().first)* stack.top().second;
            if(area>maxArea)
            {
                maxArea=area;
            }
            stack.pop();
        }
         return maxArea;


    }
};


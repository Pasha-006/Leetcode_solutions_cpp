class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matri) {

       int rows=matri.size();
       int cols=matri[0].size();
       int matrix[rows][cols];
       for(int i=0;i<rows;i++)
       {
        for(int j=0;j<cols;j++)
        {
            matrix[i][j]=(matri[i][j]-48);
        }
       }
       
       for(int i=1;i<rows;i++)
       {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]==1)
            {
            matrix[i][j]=matrix[i-1][j]+matrix[i][j];
            }
        }
       }
        int finalmaxArea=0;
       for(int j=0;j<rows;j++)
       {
        
        std::vector<int> heights;
        for(int i=0;i<cols;i++)
        {
            heights.emplace_back(matrix[j][i]);
            std::cout<<matrix[j][i]<<" ";

        }
        std::cout<<std::endl;
    
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
        if(maxArea>finalmaxArea)
        {
            finalmaxArea=maxArea;
        }
       }
        return finalmaxArea;

    }
};
//https://leetcode.com/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> results;
        if(numRows>=1)
        {
            std::vector<int> curr{1};
            results.emplace_back(curr);
        }
        if(numRows>=2)
        {
            std::vector<int> curr{1,1};
            results.emplace_back(curr);
        }
        for(int j=3;j<=numRows;j++)
        {
            std::vector<int> curr(j);
            
            curr[0]=1;
            
            for(int i=1;i<=curr.size()-2;i++)
            {
            
                curr[i]=results[j-2][i-1]+results[j-2][i];

            }
         
            std::cout<<results[1][1]<<std::endl;
            curr[j-1]=1;
            std::cout<<"\n";
            results.emplace_back(curr);

        }
        return results;
        
    }
};
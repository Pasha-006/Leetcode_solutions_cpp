#include<iostream>
#include<vector> 
#include<unordered_set>

void setZeroes(std::vector<std::vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::unordered_set<int> rows;
    std::unordered_set<int> cols;
    int rowSize=A.size();
    int colSize=A[0].size();
    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;j++)
        {
            if(A[i][j]==0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;j++)
        {
            if(rows.find(i)!=rows.end())
            {
                A[i][j]=0;
            }
            else
            if(cols.find(j)!=cols.end())
            {
                A[i][j]=0;
            }
        }
    }


}
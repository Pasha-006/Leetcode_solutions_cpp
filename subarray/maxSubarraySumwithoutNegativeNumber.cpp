#include<iostream>
#include<vector>
std::vector<int> maxset(std::vector<int> &A) {
    
     int StartPos=0;
    int endPos=0;
    long long sum=-1;
    int currPos=0;
    int currEnd=0;
    long long currSum=0;
    int flag=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<0)
        {
            
            if(currSum>sum)
            {
                StartPos=currPos;
                endPos=currEnd;
                sum=currSum;
            }
            currSum=0;
            flag=1;

        }
        else 
        {   
            if(flag==1)
            {
                flag=0;
                currPos=i;
                currEnd=currPos;
            }
            currEnd+=1;
            currSum+=A[i];
        }
         
    }
    int currSubarray_length=currEnd-currPos;
    if(sum<currSum)
    {
        StartPos=currPos;
        endPos=currEnd;
        
    } 
    
    std::vector<int> result;
    for(int i=StartPos;i<endPos;i++)
    {
        result.emplace_back(A[i]);
    }
    return result;
}

int main()
{

    std::vector<int> ans{1, 2, 5, -7, 2, 5};
    std::vector<int> result=maxset(ans);
    for(int i=0;i<result.size();i++)
    {
        std::cout<<result[i]<<" ";
    }


    return 0;
}

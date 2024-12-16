#include<vector>
#include<vector>

std::vector<int> addArrays(std::vector<int> &A, std::vector<int> &B) {
    int arrayAsize=A.size();
    int arrayBsize=B.size();
    int currAInd=arrayAsize-1;
    int currBInd=arrayBsize-1;
    int carryForward=0;
    std::vector<int> res;
    while(currAInd>=0 && currBInd>=0)
    {
        int sum=(carryForward+A[currAInd]+B[currBInd]);
        int div=(sum)/10;
        if(div>0)
        {
            sum=(carryForward+A[currAInd]+B[currBInd])%10;
            carryForward=1;
        }
        else 
        {
            carryForward=0;
        }
        res.emplace_back(sum);
        currAInd-=1;
        currBInd-=1;

    }
    while(currAInd>=0)
    {
        int sum=(carryForward+A[currAInd]);
        int div=(sum)/10;
        if(div>0)
        {
            sum=(carryForward+A[currAInd])%10;
            carryForward=1;
        }
        else 
        {
            carryForward=0;
        }
        res.emplace_back(sum);
        currAInd-=1;

    }
    while(currBInd>=0)
    {
         int sum=(carryForward+B[currBInd]);
        int div=(sum)/10;
        if(div>0)
        {
            sum=(carryForward+B[currBInd])%10;
            carryForward=1;
        }
        else 
        {
            carryForward=0;
        }
        res.emplace_back(sum);
        currBInd-=1;
    }
    if(carryForward!=0)
    {
        res.emplace_back(carryForward);
    }
    int left=0;
    int right=res.size()-1;
    while(left<=right)
    {
        int temp=res[left];
        res[left]=res[right];
        res[right]=temp;
    }
    return res;
}

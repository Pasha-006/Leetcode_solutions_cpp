//https://leetcode.com/problems/minimum-array-sum/ 
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
/*
case 1: apply op1 one 

case 2: apply op2  

case 3: apply first op1 then op2 

case 4: apply first op2 then op1 

case 5: no operation


*/
int MinsumArray(std::vector<int> &nums,int index,int k,int op1,int op2,int size,std::vector<std::vector<std::vector<int>>>& dp)
{
    int ans=INT32_MAX;


    if(index==size)
    {
        return 0;
    }
        if(dp[index][op1][op2]!=-1)
    {
        return dp[index][op1][op2];
    }

    //case 1 
    if(op1!=0)
    {
        int currSum=int(std::ceil(nums[index]/2.00))+MinsumArray(nums,index+1,k,op1-1,op2,size,dp);
        ans=std::min(currSum,ans);
    }

    //case 2 
    if(op2!=0)
    {
        if(nums[index]>=k)
        {
            int currSum=(nums[index]-k)+MinsumArray(nums,index+1,k,op1,op2-1,size,dp);
            ans=std::min(currSum,ans);
        }
    }

 

    if(op1!=0 && op2!=0)
    {
        //case 3 
        int op1_value=std::ceil(nums[index]/2.00);
        if(op1_value>=k)
        {
            int currSum=(op1_value-k)+MinsumArray(nums,index+1,k,op1-1,op2-1,size,dp);
            ans=std::min(currSum,ans);
        }

        //case 4
        if(nums[index]>=k)
        {
            int op2_value=nums[index]-k;
            int currSum=int(std::ceil(op2_value/2.00))+MinsumArray(nums,index+1,k,op1-1,op2-1,size,dp);
            ans=std::min(currSum,ans);
        }

    }

    //case 5 
    int currSum=nums[index]+MinsumArray(nums,index+1,k,op1,op2,size,dp);
    ans=dp[index][op1][op2]=std::min(currSum,ans);
    return ans;
}




class Solution {
public:
    int minArraySum(std::vector<int>& nums, int k, int op1, int op2) {

        int size=nums.size();
        std::vector<std::vector<std::vector<int>>> dp(size,std::vector<std::vector<int>>(op1+1,std::vector<int>(op2+1,-1)));
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<op1;j++)
            {
                for(int k=0;k<op2;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return MinsumArray(nums,0,k,op1,op2,size,dp);


        
    }
};
#include<iostream>
#include<vector>
class SegTree
{
    private:
        std::vector<int> segTree;
    public:
        SegTree(std::vector<int> &num)
        {
            int size=num.size();
            segTree.resize(4*size);
            buildSegTree(num,0,size-1,0,size);
        }
        void  buildSegTree(std::vector<int> &nums,int segStart,int segEnd,int currIndex,int size)
        {
            if(segStart==segEnd)
            {
                segTree[currIndex]=nums[segStart];
                return;
            }
            int mid=(segStart+segEnd)/2;
            buildSegTree(nums,segStart,mid,currIndex*2+1,size);
            buildSegTree(nums,mid+1,segEnd,currIndex*2+2,size);

            segTree[currIndex]=std::max(segTree[currIndex*2+1],segTree[currIndex*2+2]);

        }
        int maxInQuery(int segStart,int segEnd,int left, int right,int currIndex)
        {
            if(segStart>=left && segEnd<=right)
            {
                return segTree[currIndex];
            }
            if(left>segEnd || right<segStart)
            {
                return 0;
            }
            int mid=(segStart+segEnd)/2;
            int currMax=std::max(maxInQuery(segStart,mid,left,right,currIndex*2+1),maxInQuery(mid+1,segEnd,left,right,currIndex*2+2));
            return currMax;

        }
        void updateSegtree(int segStart,int segEnd,int currIndex,int Index,std::vector<int> &nums)
        {
            if(segEnd==segStart)
            {
          
                segTree[currIndex]-=1;
                return ;
            }
            int mid=(segStart+segEnd)/2;
            if(Index>=segStart && Index<=mid)
            {
            updateSegtree(segStart,mid,currIndex*2+1,Index,nums);
            }
            else{
            updateSegtree(mid+1,segEnd,currIndex*2+2,Index,nums);
            }
            segTree[currIndex]=std::max(segTree[currIndex*2+1],segTree[currIndex*2+2]);

        }


};

class Solution {
public:
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        SegTree s=SegTree(nums);
        
        for(std::vector<int> &currVector:queries)
        {
        
            int start=currVector[0];
            int end=currVector[1];
             int currMax=s.maxInQuery(0,nums.size()-1,start,end,0);
            std::cout<<currMax<<std::endl; 
           if(currMax>0)
            {
               
                for(int i=start;i<=end;i++)
                {
                    s.updateSegtree(0,nums.size()-1,0,i,nums);
                    

                }
               
            }
        }
        
        int currMax=s.maxInQuery(0,nums.size()-1,0,nums.size()-1,0);
        
        if(currMax<=0)
         {
             return true;
         }
        return false;
    }
};
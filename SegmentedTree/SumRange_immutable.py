#https://leetcode.com/problems/range-sum-query-immutable/


class NumArray:
    def __init__(self, nums: List[int]):
        self.segmented_tree=[]
        for i in range(0,len(nums)*4):
            self.segmented_tree.append(0)
        self.build(nums,0,len(nums)-1,0)
        self.size=len(nums)-1
        print(self.segmented_tree)
    def build(self,nums,intialStart,intialEnd,currIndex):
        if intialStart==intialEnd:
            self.segmented_tree[currIndex]=nums[intialStart]
            return  nums[intialStart]
        mid=(intialStart+intialEnd)//2
        self.segmented_tree[currIndex]=self.build(nums,intialStart,mid,currIndex*2+1)+self.build(nums,mid+1,intialEnd,currIndex*2+2) 
        return self.segmented_tree[currIndex]
    def sum_range(self,currIndex,start,end,left,right):
        if left<=start and right>=end:
            return self.segmented_tree[currIndex]
        if end<left or start>right:
            return 0
        mid=(start+end)//2
        return self.sum_range(currIndex*2+1,start,mid,left,right)+self.sum_range(currIndex*2+2,mid+1,end,left,right)    

    def sumRange(self, left: int, right: int) -> int:
        return self.sum_range(0,0,self.size, left,right)
        


